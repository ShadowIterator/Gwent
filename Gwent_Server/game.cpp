#include"game.h"
#include"global.h"
#include<string>
#include<synchapi.h>
Game::~Game()
{
	delete field;
	delete user[0];
	delete user[1];
}

Game::Game(QObject *parent):QObject(parent)
{

	QTextStream qin(stdin);
	field=new Field;
	field->setGame(this);
	user[0]=new UserInteraction(0,this);
	user[1]=new UserInteraction(1,this);

	qDebug()<<"enter the path of first player's deck";
	qin>>deckpath[0];

	qDebug()<<"enter the path of second player's deck";
	qin>>deckpath[1];

	cardDir=":/Cards/Cards/";

	curTeam=0;
	round=0;

	for(int team=0;team!=MAX_TEAM_NUM;++team)
	{
		for(int k=0;k!=MAX_ROUND_NUM;++k)
			score[team][k]=0;
		winRound[team]=0;
		passed[team]=0;
	}

	cardInput.clear();
	cardSetInput.clear();
	orderInput.clear();


	connect(this,SIGNAL(_startGame()),this,SLOT(startGame()));
	connect(this,SIGNAL(_startRound(int,int)),this,SLOT(startRound(int,int)));
	connect(this,SIGNAL(_startTurn(int,int)),this,SLOT(startTurn(int,int)));

	connect(this,SIGNAL(_endGame()),this,SLOT(endGame()));
	connect(this,SIGNAL(_endRound(int)),this,SLOT(endRound(int)));
	connect(this,SIGNAL(_endTurn(int,int)),this,SLOT(endTurn(int,int)));
}

void Game::_inputCard_(Card* pcard)
{
	cardInput.push_back(pcard);
}

void Game::_inputCardSet_(CardSet * pcardSet)
{
	cardSetInput.push_back(pcardSet);
}

void Game::_inputOrder_(int order)
{
	orderInput.push_back(order);
}

Card* Game::__popFront_cardInput()
{
	Card* rtn=cardInput.front();
	cardInput.pop_front();
	return rtn;
}

CardSet* Game::__popFront_cardSetInput()
{
	CardSet* rtn=cardSetInput.front();
	cardSetInput.pop_front();
	return rtn;
}

int Game::__popFront_orderInput()
{
	int rtn=orderInput.front();
	orderInput.pop_front();
	return rtn;
}


void Game::startGame()
{
	emit startGame_();
	field->__loadDeck(0,deckpath[0],cardDir);
	field->__loadDeck(1,deckpath[1],cardDir);
	curTeam=rand()&1;

	field->deck[0]->reOrder();
	field->deck[1]->reOrder();

	for(int team=0;team!=MAX_TEAM_NUM;++team)
	{
		list<Card*>::iterator it;
		for(it=field->deck[team]->cardSet.begin();it!=field->deck[team]->cardSet.end();++it)
			if((*it)->getProperty("leader")=="true")
			{
				emit field->_drawCard(*it,NULL,noinfo);
				break;
			}
	}
	emit _startRound(0,curTeam);
}

void Game::startRound(int roundNum, int startTeam)
{
	emit startRound_(roundNum,startTeam);

	int drawNum;
	int swapNum;
	Card* choosenCard;
	this->round=roundNum;
	passed[0]=passed[1]=0;
	switch(roundNum)
	{
	case 0: drawNum=9; swapNum=3; break;
	case 1: drawNum=2; swapNum=2; break;
	case 2: drawNum=1; swapNum=1; break;
	}
	for(int team=0;team<2;++team)
	{

		for(int i=0;i!=drawNum;++i)
		{
			emit field->_drawCard(team,NULL,noinfo);
		}
	}
	for(int team=0;team<2;++team)
	{
		for(int i=0;i!=swapNum;++i)
		{
			field->hand[team]->___print();
			if(user[team]->queryBin("Finish swap?")) break;
			choosenCard=user[team]->__inputCard(field->hand[team]);
			if(choosenCard->getProperty("leader")=="true")
			{
				continue;
			}
			emit field->_adjustPlace(choosenCard,field->deck[team],-1,NULL,noinfo);
			emit field->_reOrder(field->deck[team],NULL,noinfo);
			emit field->_drawCard(team,NULL,noinfo);
		}
	}
	emit _startTurn(1,startTeam);
}

void Game::startTurn(int turnNum, int curTeam)
{
	emit startTurn_(turnNum,curTeam);

	field->graveyard[curTeam]->___print();
	field->___printBoard();
	field->hand[curTeam]->___print();
	if(!passed[curTeam]&&(!(passed[curTeam]|=user[curTeam]->queryBin("Do you want to pass(0/1)?")))&&(!(passed[curTeam]|=(field->hand[curTeam]->cardSet.empty()))))
	{
		Card* pcard=user[curTeam]->__inputCard(field->hand[curTeam]);
		CardSet* pcardSet=NULL;
		int order=-1;
		user[curTeam]->__inputPlace(pcard,pcardSet,order);
		emit field->_playCard(pcard,pcardSet,order,NULL,noinfo);
	}

	emit _endTurn(turnNum,curTeam);
}

void Game::endTurn(int turnNum, int curTeam)
{
	emit endTurn_(turnNum,curTeam);
	if(passed[0]&&passed[1])
	{
		emit _endRound(this->round);
	}
	this->curTeam=curTeam^1;
	emit _startTurn(turnNum+1,curTeam^1);
}

void Game::endRound(int roundNum)
{
	emit endRound_();

	for(int team=0;team!=MAX_TEAM_NUM;++team)
		score[team][roundNum]=field->board[team]->score;

	int winner=score[0][roundNum]>score[1][roundNum]?0:1;
	if(score[0][roundNum]==score[1][roundNum]) winner=-1;
	int startTeam;

	SI_String cmd;

	if(winner!=-1)
	{
		++winRound[startTeam=winner];
		cmd="setwinround#"+SI_String::number(winner)+"$"+SI_String::number(winRound[winner]);
		cout<<cmd.toStdString()<<endl;

	}
	else
	{
		++winRound[0];
		++winRound[1];
		cmd="setwinround#"+SI_String::number(0)+"$"+SI_String::number(winRound[0]);
		cout<<cmd.toStdString()<<endl;
		cmd="setwinround#"+SI_String::number(1)+"$"+SI_String::number(winRound[1]);
		cout<<cmd.toStdString()<<endl;

		startTeam=rand()&1;
	}

	if(winRound[0]==2||winRound[1]==2)
	{
		emit _endGame();
		return ;
	}

	for(int team=0;team!=2;++team)
	{
		list<Card*> eraseSet;
		eraseSet.assign(field->board[team]->cardSet.begin(),field->board[team]->cardSet.end());
		for(list<Card*>::iterator it=eraseSet.begin();it!=eraseSet.end();++it)
		{
			if((*it)->getProperty("tenacity")!="true")
				emit field->_destroyCard(*it,NULL,noinfo);
		}
		for(int k=0;k!=MAX_ROW_NUM;++k)
			emit field->_removeWeather(field->row[team][k],NULL,noinfo);
	}
	emit startRound(roundNum+1,startTeam);
}

void Game::endGame()
{
	emit endGame_();

	Sleep(100000);

	emit _gameover();

}

void Game::__init()
{
	QFile file("D:\\THU\\QT_Dir\\Gwent_Battle\\data.txt");
	if(!file.open(QIODevice::ReadOnly))
	{
		qFatal("open file failed");
		return ;
	}
	QTextStream fin(&file);
	QString temp;
	__inputQString(fin,temp);

	Card* pcard;
	field->cardNum=0;
	field->deck[0]->cardSet.clear();
	while(temp!="#")
	{
		pcard=field->allCard[(field->cardNum)++]=new Card;
		pcard->__readInfo(fin);
		pcard->setProperty("team","0");
		pcard->setPlace((field->deck[0]),-1);
		__inputQString(fin,temp);
		if(field->cardNum>=10) break;
	}
	while(temp!="#")
	{
		pcard=field->allCard[(field->cardNum)++]=new Card;
		pcard->__readInfo(fin);
		pcard->setProperty("team","1");
		pcard->setPlace((field->deck[1]),-1);
		__inputQString(fin,temp);
	}
}

void Game::__test()
{

}
