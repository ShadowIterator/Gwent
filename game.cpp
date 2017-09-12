#include"game.h"

Game::Game(QObject *parent):QObject(parent)
{

	field=new Field;
	field->setGame(this);
	user[0]=new UserInteraction(0,this);
	user[1]=new UserInteraction(1,this);

	deckpath[0]="D:\\THU\\QT_Dir\\Gwent_Battle\\Cards\\deck0.txt";
	deckpath[1]="D:\\THU\\QT_Dir\\Gwent_Battle\\Cards\\deck1.txt";
	cardDir="D:\\THU\\QT_Dir\\Gwent_Battle\\Cards";

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
	case 0: drawNum=10; swapNum=3; break;
	case 1: drawNum=2; swapNum=2; break;
	case 2: drawNum=1; swapNum=1; break;
	}
	for(int team=0;team<2;++team)
	{
//		field->deck[team]->___print();
		for(int i=0;i!=drawNum;++i)
		{
			emit field->_drawCard(team,NULL,noinfo);
			//emit field->_drawCard(0,NULL,noinfo);
//			field->hand[team]->___print();
		}
	}
	for(int team=0;team<2;++team)
	{
		for(int i=0;i!=swapNum;++i)
		{
			if(user[team]->queryBin("Finish swap?")) break;
			choosenCard=user[team]->__inputCard(field->hand[team]);
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

	qDebug()<<"Team "<<curTeam<<" turn "<<turnNum<<endl;
	field->___printBoard();
	field->deck[curTeam]->___print();
	field->hand[curTeam]->___print();

	if(!passed[curTeam]&&(!(passed[curTeam]|=user[curTeam]->queryBin("Pass?")))&&(!(passed[curTeam]|=(field->hand[curTeam]->cardSet.empty()))))
	{
		Card* pcard=user[curTeam]->__inputCard(field->hand[curTeam]);
		CardSet* pcardSet=NULL;
		int order=-1;
		user[curTeam]->__inputPlace(pcard,pcardSet,order);
		emit field->_playCard(pcard,pcardSet,order,NULL,noinfo);
		//	int position=pcard->getProperty("position").toInt();

	/*
		if(pcard->getProperty("type")=="spell")
		{
			emit field->_playCard(pcard,field->graveyard[curTeam],-1,NULL,noinfo);
		}
		else
		{

			list<CardSet*> lcardSet;
			lcardSet.clear();
			for(int i=0;i!=MAX_ROW_NUM;++i)
				if((position>>i)&1) lcardSet.push_back((field->row[curTeam][i]));
			position>>=MAX_ROW_NUM;
			for(int i=0;i!=MAX_ROW_NUM;++i)
				if((position>>i)&1) lcardSet.push_back((field->row[curTeam^1][i]));
			CardSet* pcardSet=user[curTeam]->__inputCardSet(&lcardSet);
			int order=user[curTeam]->__inputOrder(pcardSet);

			CardSet* pcardSet=NULL;
			int order=user[curTeam]->__inputPlace(pcard,pcardSet,1);
			emit field->_playCard(pcard,pcardSet,order,NULL,noinfo);

			//pcardSet->___print();
			//field->hand[curTeam]->___print();
		}
		*/
	}

	//----------------------
	//field->___printBoard();

	//field->board[]

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

	if(winner!=-1) ++winRound[startTeam=winner];
	else
	{
		++winRound[0];
		++winRound[1];
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
}

void Game::__init()
{
//	ifstream fin("data.txt");
	QFile file("D:\\THU\\QT_Dir\\Gwent_Battle\\data.txt");
	if(!file.open(QIODevice::ReadOnly))
	{
		qFatal("open file failed");
		return ;
	}
	QTextStream fin(&file);
	QString temp;
	__inputQString(fin,temp);
	//fin>>temp;
	//Card* pcard=new Card;
	Card* pcard;
	field->cardNum=0;
	field->deck[0]->cardSet.clear();
	while(temp!="#")
	{
		//Card*& pcard=field->allCard[(field->cardNum)++];
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
//	field->___printBoard();


	qDebug()<<"INIT_OVER----------"<<endl<<endl<<endl;
}

void Game::__test()
{
//-----test---------
	QString noinfo=QString::fromStdString("");
	emit field->_drawCard(0,NULL,noinfo);
	emit field->_drawCard(0,NULL,noinfo);
//	field->hand[0].___print();
	emit field->_drawCard(1,NULL,noinfo);
//	field->hand[1].___print();
//	emit field->_playCard(*(field->hand[0].cardSet.begin()),&(field->row[0][1]),0,NULL,noinfo);
//	field->___printBoard();bb
//	field->row[0][1].___print();

	list<Card*>::iterator it=field->hand[0]->cardSet.begin();
	emit field->_adjustArmor(*it,3,NULL,noinfo);
//	field->hand[0].___print();

	++it;
	emit field->_boostCard(*it,4,NULL,noinfo);
//	field->hand[0].___print();

	emit field->_adjustArmor(*it,3,NULL,noinfo);
	field->hand[0]->___print();

//	emit field->_damegeCard(*it,15,NULL,noinfo);
	emit field->_weakenCard(*it,2,NULL,noinfo);
	field->hand[0]->___print();

	qDebug()<<"*******"<<endl;
	field->graveyard[0]->___print();

	emit field->_exileCard(*it,NULL,noinfo);
	field->graveyard[0]->___print();
	field->exiled[0]->___print();

	emit field->_weakenCard(*it,5,NULL,noinfo);
	field->exiled[0]->___print();
	field->graveyard[0]->___print();
/*
	field->deck[1].___print();
	qDebug()<<"*******************"<<endl;
	field->deck[1].reOrder();
	field->deck[1].___print();
*/
}
