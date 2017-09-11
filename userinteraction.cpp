#include"userinteraction.h"
#include<iostream>

using std::cin;
using std::cout;

UserInteraction::UserInteraction(int team,QObject *parent):SI_Object(parent)
{
	setProperty("team",SI_String::number(team));
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

		//(*it)->___print();
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
			qDebug()<<(*cit)->getProperty("name");//<<endl;
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
