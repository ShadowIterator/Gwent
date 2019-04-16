#ifndef USERINTERACTION_H
#define USERINTERACTION_H

#include"global.h"
#include"si_object.h"
#include"card.h"
#include"cardset.h"
#include"field.h"
#include<QMap>

class UserInteraction:public SI_Object
{
	Q_OBJECT
public:
	Game* game;
	QMap<SI_String,Card*> allcard;
	QMap<SI_String,CardSet*> allcardSet;

	Card* selectCard;
	CardSet* selectCardSet;
	int order;
	int selectOrder;
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

public:
	Card* _ui__inputCard(CardSet*);
	CardSet* _ui__inputCardSet(list<CardSet*>*);
	int _ui__inputOrder(CardSet*);

	int rowNametoID(SI_String);
	CardSet* IDtoRow(int);
	void _ui_newCard(SI_String);
	void _ui_setPlace(SI_String);
	void _ui_setProperty(SI_String);
	void _ui_setScore(SI_String);
	void _ui_setWinRound(SI_String);
	void _ui_inputCard(SI_String);
	void _ui_eraseID(int);
	void _ui_inputRow(SI_String);
	void _ui_inputOrder(SI_String);
	void _ui_setWeather(SI_String);
	Card* _ui_getCard(SI_String);
	CardSet* _ui_getCardSet(SI_String);
public slots:
	void ui_cmdExplainer(SI_String);
	void _ui__inputCard_done_(int);
	void _ui__inputCardSet_done_(int);
	void _ui__inputOrder_done_(int);
signals:
	void _outputInfo(SI_String);
};


#endif // USERINTERACTION_H
