#include"userinteraction.h"
#include<iostream>
#include"game.h"

using std::cin;
using std::cout;

UserInteraction::UserInteraction(int team,Game* pgame,QObject *parent):SI_Object(parent),game(pgame)
{
	setProperty("team",SI_String::number(team));
}

SI_String UserInteraction::getTeam()
{
	if(this==game->user[0]) return SI_String::number(0);
	return SI_String::number(1);
}

Card* UserInteraction::__inputCard(CardSet *pcardSet)
{
	if(pcardSet->cardSet.empty()) return NULL;
	QString cmd;
	cmd.clear();
	cmd+="to%"+getTeam()+"%inputcard#";
	qDebug()<<"Choose Card:"<<endl;
	list<Card*>::iterator it=pcardSet->cardSet.begin();
	int i,id;
	for(i=0;it!=pcardSet->cardSet.end();++i,++it)
	{
		cmd+=SI_String::number((*it)->cid)+"$";
	}
	cmd.chop(1);
	cout<<cmd.toStdString()<<endl;
	cin>>id;

	for(it=pcardSet->cardSet.begin();it!=pcardSet->cardSet.end();++it)
		if(id==(*it)->cid) return *it;
}

CardSet* UserInteraction::__inputCardSet(list<CardSet*>* plcardSet)
{
	if(plcardSet->empty()) return NULL;
	SI_String cmd;
	SI_String rowName;
	cmd="to%"+getTeam()+"%inputrow#";
	qDebug()<<"Choose Row"<<endl;
	list<CardSet*>::iterator it=plcardSet->begin();
	list<Card*>::iterator cit;
	int i,id;
	for(i=0;it!=plcardSet->end();++i,++it)
	{
		cmd=cmd+(*it)->getProperty("name")+"$";
	}
	cmd.chop(1);
	cout<<cmd.toStdString()<<endl;
	in>>rowName;

	for(it=plcardSet->begin();it!=plcardSet->end();++it)
		if((*it)->getProperty("name")==rowName)
			return *it;
	return NULL;
}

int UserInteraction::__inputOrder(CardSet *pcardSet)
{
	if(pcardSet->cardSet.empty()) return -1;
	list<Card*>::iterator it=pcardSet->cardSet.begin();

	int i,id;

	SI_String cmd;
	cmd="to%"+getTeam()+"%inputorder#"+pcardSet->getProperty("name");
	cout<<cmd.toStdString()<<endl;
	cin>>id;

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
