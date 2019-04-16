#ifndef USERINTERACTION_H
#define USERINTERACTION_H

#include"global.h"
#include"si_object.h"
#include"card.h"
#include"cardset.h"
#include"field.h"

class UserInteraction:public SI_Object
{
	Q_OBJECT
public:
	Game* game;
public slots:
	void inputCard(CardSet*);
	void inputCardSet(list<CardSet*>*);
	void inputOrder(CardSet*);
	void queryPass();
	int queryBin(SI_String);
public:
	UserInteraction(int team,Game* pgame,QObject *parent=0);
	Card* __inputCard(CardSet*);
	CardSet* __inputCardSet(list<CardSet*>*);
	int __inputOrder(CardSet*);
	int __inputPlace(Card*,CardSet*&,int&);
signals:
	void inputCard_(Card*);
	void inputCardSet_(CardSet*);
	void inputOrder_(int);
	void _pass(int);
//	void _endTurn();
};


#endif // USERINTERACTION_H
