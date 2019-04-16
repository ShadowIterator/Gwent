#include"userinteraction.h"
#include<iostream>
#include"game.h"
#include"cardsetwidget.h"
#include"fieldwidget.h"
#include<QSignalMapper>
#include"cardwidget.h"
#include<QStringList>
#include<synchapi.h>
using std::cin;
using std::cout;

UserInteraction::UserInteraction(int team,Game* pgame,QObject *parent):SI_Object(parent),game(pgame)
{
	setProperty("team",SI_String::number(team));

	allcard.clear();
	allcardSet.clear();

	for(int i=0;i!=MAX_TEAM_NUM;++i)
	{
		for(int k=0;k!=MAX_ROW_NUM;++k)
		{
			allcardSet.insert(game->field->row[i][k]->getProperty("name"),game->field->row[i][k]);
		}
		allcardSet.insert(game->field->graveyard[i]->getProperty("name"),game->field->graveyard[i]);
	}
	allcardSet.insert(game->field->hand[team]->getProperty("name"),game->field->hand[team]);

}



Card* UserInteraction::__inputCard(CardSet *pcardSet)
{
	if(pcardSet->cardSet.empty()) return NULL;
	qDebug()<<"Choose Card:"<<endl;
	list<Card*>::iterator it=pcardSet->cardSet.begin();
	int i,id;
	for(i=0;it!=pcardSet->cardSet.end();++i,++it)
	{
		qDebug()<<i<<" "<<(*it)->getProperty("name")<<"  "<<(*it)->getProperty("boostpower").toInt()+(*it)->getProperty("basepower").toInt();//<<endl;
	}
	cin>>id;
	while(id<0||id>=i)
	{
		qDebug()<<"id must in range"<<endl;
		cin>>id;
	}
	return pcardSet->atIndex(id);
}

CardSet* UserInteraction::__inputCardSet(list<CardSet*>* plcardSet)
{
	if(plcardSet->empty()) return NULL;
	qDebug()<<"Choose Row"<<endl;
	list<CardSet*>::iterator it=plcardSet->begin();
	list<Card*>::iterator cit;
	int i,id;
	for(i=0;it!=plcardSet->end();++i,++it)
	{
		qDebug()<<"---------------------------"<<endl
			<<i<<(*it)->getProperty("name")<<endl;
		for(cit=(*it)->cardSet.begin();cit!=(*it)->cardSet.end();++cit)
			qDebug()<<(*cit)->getProperty("name");
	}
	cin>>id;
	while(id<0||id>=i)
	{
		qDebug()<<"id must in range"<<endl;
		cin>>id;
	}
	it=plcardSet->begin();
	for(;id;++it,--id);
	return *it;
}

int UserInteraction::__inputOrder(CardSet *pcardSet)
{
	list<Card*>::iterator it=pcardSet->cardSet.begin();
	qDebug()<<"Choose Order"<<endl;
	int i,id;
	for(i=0;it!=pcardSet->cardSet.end();++i,++it)
	{
		qDebug()<<i<<endl
			   <<(*it)->getProperty("name")<<endl;
	}
	qDebug()<<i<<endl;
	cin>>id;
	while(id<0||id>i)
	{
		qDebug()<<"id must in range"<<endl;
		cin>>id;
	}
	return id;
}

int UserInteraction::__inputPlace(Card *pcard, CardSet *&rtn_pcardSet, int& rtn_order)
{
	int curTeam=pcard->getProperty("team").toInt();
	if(pcard->getProperty("type")=="spell")
	{
		rtn_pcardSet=game->field->graveyard[curTeam];
		rtn_order=-1;
		return SPELL;
	}
	int position=pcard->getProperty("position").toInt();
	list<CardSet*> lcardSet;
	lcardSet.clear();
	for(int i=0;i!=MAX_ROW_NUM;++i)
		if((position>>i)&1) lcardSet.push_back((game->field->row[curTeam][i]));
	position>>=MAX_ROW_NUM;
	for(int i=0;i!=MAX_ROW_NUM;++i)
		if((position>>i)&1) lcardSet.push_back((game->field->row[curTeam^1][i]));

	rtn_pcardSet=__inputCardSet(&lcardSet);
	rtn_order=__inputOrder(rtn_pcardSet);
	return MINION;
}

void UserInteraction::inputCard(CardSet *pcardSet)
{
	Card* res=__inputCard(pcardSet);
	emit inputCard_(res);
}

void UserInteraction::inputCardSet(list<CardSet *> *plcardSet)
{
	CardSet* res=__inputCardSet(plcardSet);
	emit inputCardSet_(res);
}

void UserInteraction::inputOrder(CardSet *pcardSet)
{
	int res=__inputOrder(pcardSet);
	emit inputOrder_(res);
}

void UserInteraction::queryPass()
{
	qDebug()<<"Wanna Pass?(0/1)"<<endl;
	int val;
	cin>>val;
	if(val) emit _pass(getProperty("team").toInt());
}

int UserInteraction::queryBin(SI_String ques)
{
	qDebug()<<ques<<"(0/1)"<<endl;
	int rtn;
	cin>>rtn;
	if(rtn) return 1;
	return 0;
}
//\ui

Card* UserInteraction::_ui_getCard(SI_String cardID)
{
	QMap<SI_String,Card*>::iterator it=allcard.find(cardID);
	if(it==allcard.end()) return NULL;
	return it.value();
}

CardSet* UserInteraction::_ui_getCardSet(SI_String cardSetName)
{
	QMap<SI_String,CardSet*>::iterator it=allcardSet.find(cardSetName);
	if(it==allcardSet.end()) return NULL;
	return it.value();
}

void UserInteraction::_ui_newCard(SI_String cmd)
{
	SI_String cardName=cmd.section("$",0,0);
	SI_String cardID=cmd.section("$",1,1);
	Card* pcard=Card::factory(game,cardName);
	pcard->cid=cardID.toInt();
	game->field->addtoAllCard(pcard);
	allcard.insert(cardID,pcard);
}

void UserInteraction::_ui_eraseID(int id)
{
	QMap<SI_String,Card*>::iterator it=allcard.find(SI_String::number(id));
	if(it==allcard.end()) return ;
	allcard.erase(it);
}

void UserInteraction::_ui_setPlace(SI_String cmd)
{
	SI_String cardID=cmd.section("$",0,0);
	SI_String cardSetName=cmd.section("$",1,1);
	int order=cmd.section("$",2,2).toInt();
	Card* pcard=_ui_getCard(cardID);
	if(pcard==NULL) return ;
	CardSet* pcardSet=_ui_getCardSet(cardSetName);

	emit game->field->_ui_setPlace(pcard,pcardSet,order);

	pcardSet->pwidget->_update();
}

void UserInteraction::_ui_setProperty(SI_String cmd)
{
	SI_String cardID=cmd.section("$",0,0);
	SI_String propertyName=cmd.section("$",1,1);
	SI_String propertyVal=cmd.section("$",2,2);
	Card* pcard=_ui_getCard(cardID);
	if(pcard==NULL) return ;

	emit game->field->_ui_setCardProperty(pcard,propertyName,propertyVal);
}

void UserInteraction::_ui_setWinRound(SI_String cmd)
{
	int team=cmd.section("$",0,0).toInt();
	SI_String winRound=cmd.section("$",1,1);

	game->field->pwidget->winRound[team]->setText(winRound);
}

void UserInteraction::_ui_setScore(SI_String cmd)
{
	SI_String cardSetName=cmd.section("$",0,0);
	SI_String val=cmd.section("$",1,1);
	SI_String cardSetType=cardSetName.section("_",0,0);
	int team=cardSetName.section("_",1,1).toInt();
	if(cardSetType=="row")
	{
		int rowNum=cardSetName.section("_",2,2).toInt();
		game->field->pwidget->rowScore[team][rowNum]->setText(val);
	}
	else
	{
		game->field->pwidget->boardScore[team]->setText(val);
	}
}

Card* UserInteraction::_ui__inputCard(CardSet *pcardSet)
{
	selectCard=NULL;

	Card* rtn;
	list<Card*>::iterator it;
	QSignalMapper *mapper=new QSignalMapper(this);

	for(int k=0;k<game->field->cardNum;++k)
		game->field->allCard[k]->pwidget->setEnabled(false);
	for(it=pcardSet->cardSet.begin();it!=pcardSet->cardSet.end();++it)
	{
		if((*it)->place==NULL||_ui_getCardSet((*it)->place->getProperty("name"))==NULL)
		{
			game->field->selectArea->ins(*it,-1);
		}
		(*it)->pwidget->setEnabled(true);
		connect((*it)->pwidget->w_picbutton,SIGNAL(clicked()),mapper,SLOT(map()));
		mapper->setMapping((*it)->pwidget->w_picbutton,(*it)->cid);

	}

	connect(mapper,SIGNAL(mapped(int)),this,SLOT(_ui__inputCard_done_(int)));

	while(selectCard==NULL)
	{
		game->field->_ui_updateAll();
		QCoreApplication::processEvents();
		Sleep(100);
	}

	rtn=selectCard;

	for(it=pcardSet->cardSet.begin();it!=pcardSet->cardSet.end();++it)
	{
		disconnect((*it)->pwidget->w_picbutton,SIGNAL(clicked()),mapper,SLOT(map()));
	}

	for(int k=0;k<game->field->cardNum;++k)
		game->field->allCard[k]->pwidget->setEnabled(true);

	delete mapper;

	game->field->selectArea->clear();

	return rtn;

}

void UserInteraction::_ui__inputCard_done_(int id)
{
	selectCard=_ui_getCard(SI_String::number(id));
}


void UserInteraction::_ui_inputCard(SI_String cmd)
{
	qDebug()<<"_ui_inputCard"<<endl;

	QStringList slist=cmd.split("$");
	CardSet tcardSet;
	tcardSet.clear();

	for(int i=0;i<slist.size();++i)
	{
		tcardSet.ins(_ui_getCard(slist[i]),-1);
	}

	Card* rtnval=_ui__inputCard(&tcardSet);

	emit _outputInfo("select_Card cid="+SI_String::number(rtnval->cid));
}

int UserInteraction::rowNametoID(SI_String rowName)
{
	int team=rowName.section("_",1,1).toInt();
	int rowNum=rowName.section("_",2,2).toInt();
	return team*3+rowNum;
}

CardSet* UserInteraction::IDtoRow(int id)
{
	int team=id/3;
	int rowNum=id%3;
	return game->field->row[team][rowNum];
}

CardSet* UserInteraction::_ui__inputCardSet(list<CardSet *> *pcardlist)
{
	CardSet *pcardset;
	CardSet *rtn;
	int team;
	int rowNum;
	SI_String rowName;
	selectCardSet=NULL;
	QSignalMapper *mapper=new QSignalMapper(this);
	list<CardSet*>::iterator it;
	QPushButton* rowButton;
	for(int team=0;team!=MAX_TEAM_NUM;++team)
		for(int k=0;k!=MAX_ROW_NUM;++k)
				game->field->pwidget->rowScore[team][k]->setEnabled(false);
	for(it=pcardlist->begin();it!=pcardlist->end();++it)
	{
		rowName=(*it)->getProperty("name");
		team=rowName.section("_",1,1).toInt();
		rowNum=rowName.section("_",2,2).toInt();
		rowButton=game->field->pwidget->rowScore[team][rowNum];
		rowButton->setEnabled(true);
		connect(rowButton,SIGNAL(clicked(bool)),mapper,SLOT(map()));
		mapper->setMapping(rowButton,rowNametoID(rowName));
	}

	connect(mapper,SIGNAL(mapped(int)),this,SLOT(_ui__inputCardSet_done_(int)));

	while(selectCardSet==NULL)
	{
		QCoreApplication::processEvents();
		Sleep(100);
	}

	rtn=selectCardSet;

	for(it=pcardlist->begin();it!=pcardlist->end();++it)
	{
		rowName=(*it)->getProperty("name");
		team=rowName.section("_",1,1).toInt();
		rowNum=rowName.section("_",2,2).toInt();
		rowButton=game->field->pwidget->rowScore[team][rowNum];
		disconnect(rowButton,SIGNAL(clicked(bool)),mapper,SLOT(map()));
	}

	for(int team=0;team!=MAX_TEAM_NUM;++team)
		for(int k=0;k!=MAX_ROW_NUM;++k)
				game->field->pwidget->rowScore[team][k]->setEnabled(true);


	delete mapper;
	return rtn;
}

void UserInteraction::_ui__inputCardSet_done_(int id)
{
	selectCardSet=IDtoRow(id);
}

void UserInteraction::_ui_inputRow(SI_String cmd)
{
	QStringList slist=cmd.split("$");
	list<CardSet*> cardsetlist;
	cardsetlist.clear();
	for(int i=0;i<slist.size();++i)
		cardsetlist.push_back(_ui_getCardSet(slist[i]));
	CardSet* rtnval=_ui__inputCardSet(&cardsetlist);
	emit _outputInfo("select_Row "+rtnval->getProperty("name"));
}

void UserInteraction::_ui_inputOrder(SI_String cmd)
{
	SI_String rowName=cmd;
	CardSet* tarRow=_ui_getCardSet(rowName);
	int rtnval=_ui__inputOrder(tarRow);
	emit _outputInfo("select_Oder "+SI_String::number(rtnval));
}

const int DELTA_ROW=100000;

int UserInteraction::_ui__inputOrder(CardSet *pcardSet)
{
	selectOrder=-2;
	SI_String rowName=pcardSet->getProperty("name");
	QPushButton* rowButton;
	int team;
	int rowNum;
	int rtn;
	list<Card*>::iterator it;

	QSignalMapper *mapper=new QSignalMapper(this);
	for(int k=0;k<game->field->cardNum;++k)
		game->field->allCard[k]->pwidget->setEnabled(false);
	for(it=pcardSet->cardSet.begin();it!=pcardSet->cardSet.end();++it)
	{
		(*it)->pwidget->setEnabled(true);
		connect((*it)->pwidget->w_picbutton,SIGNAL(clicked(bool)),mapper,SLOT(map()));
		mapper->setMapping((*it)->pwidget->w_picbutton,(*it)->cid);
	}

	for(int team=0;team!=MAX_TEAM_NUM;++team)
		for(int k=0;k!=MAX_ROW_NUM;++k)
				game->field->pwidget->rowScore[team][k]->setEnabled(false);


	rowName=pcardSet->getProperty("name");
	team=rowName.section("_",1,1).toInt();
	rowNum=rowName.section("_",2,2).toInt();
	rowButton=game->field->pwidget->rowScore[team][rowNum];
	rowButton->setEnabled(true);
	connect(rowButton,SIGNAL(clicked(bool)),mapper,SLOT(map()));
	mapper->setMapping(rowButton,rowNametoID(rowName)+DELTA_ROW);

	connect(mapper,SIGNAL(mapped(int)),this,SLOT(_ui__inputOrder_done_(int)));

	while(selectOrder==-2)
	{
		QCoreApplication::processEvents();
		Sleep(100);
	}
	rtn=selectOrder;

	for(it=pcardSet->cardSet.begin();it!=pcardSet->cardSet.end();++it)
	{
		disconnect((*it)->pwidget->w_picbutton,SIGNAL(clicked()),mapper,SLOT(map()));
	}

	disconnect(rowButton,SIGNAL(clicked(bool)),mapper,SLOT(map()));

	for(int team=0;team!=MAX_TEAM_NUM;++team)
		for(int k=0;k!=MAX_ROW_NUM;++k)
				game->field->pwidget->rowScore[team][k]->setEnabled(true);


	for(int k=0;k<game->field->cardNum;++k)
		game->field->allCard[k]->pwidget->setEnabled(true);

	delete mapper;
	return rtn;

}

void UserInteraction::_ui__inputOrder_done_(int id)
{
	if(id>=DELTA_ROW)
	{
		selectOrder=-1;
		return ;
	}
	else
	{
		Card* pcard=_ui_getCard(SI_String::number(id));
		selectOrder=pcard->getOrder();
	}
}

void UserInteraction::_ui_setWeather(SI_String cmd)
{
	SI_String rowName=cmd.section("$",0,0);
	SI_String weather=cmd.section("$",1,1);

	CardSet* pcardSet=_ui_getCardSet(rowName);

	emit game->field->_ui_setWeather(pcardSet,weather);
}

void UserInteraction::ui_cmdExplainer(SI_String cmd)
{
	SI_String cmdType=cmd.section("#",0,0);
	SI_String remainCmd=cmd.section("#",1,1);

	if(cmdType=="newcard")
		_ui_newCard(remainCmd);
	if(cmdType=="setplace")
		_ui_setPlace(remainCmd);
	if(cmdType=="setproperty")
		_ui_setProperty(remainCmd);
	if(cmdType=="setscore")
		_ui_setScore(remainCmd);
	if(cmdType=="setwinround")
		_ui_setWinRound(remainCmd);
	if(cmdType=="inputcard")
		_ui_inputCard(remainCmd);
	if(cmdType=="inputrow")
		_ui_inputRow(remainCmd);
	if(cmdType=="inputorder")
		_ui_inputOrder(remainCmd);
	if(cmdType=="setweather")
		_ui_setWeather(remainCmd);
}
