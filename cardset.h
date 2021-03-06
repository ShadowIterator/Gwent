#ifndef CARDSET_H
#define CARDSET_H
#include"global.h"
#include"si_object.h"
#include"card.h"
#include"weather.h"

class CardSet:public SI_Object
{
	Q_OBJECT
public:
	list<Card*> cardSet;
	CardSet* fath;
	Weather* weather;
	int score;
public:
	CardSet(QObject *parent=0);
	Card* atIndex(int);
	bool checkCard(Card*);
	void __changeScore(int);
public slots:
	//*
	void clear();
	void reOrder();
//	void append(Card&);
//	void append(Card*);
///	void add(SI_String);
	void erase(Card&);
	void erase(Card*);
///	void del(SI_String);
	void ins(Card*,int);
	list<Card*>::iterator _getIterator(int);
	list<Card*>::iterator _getIterator(Card*);
///	int getPower() const;

#ifdef DEBUG
public:
	void ___print();

#endif //DEBUG
};



#endif // CARDSET_H
