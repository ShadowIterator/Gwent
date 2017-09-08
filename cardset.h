#ifndef CARDSET_H
#define CARDSET_H
#include"global.h"
#include"si_object.h"
#include"card.h"

class CardSet:public SI_Object
{
	Q_OBJECT
public:
	list<Card*> cardSet;
public:
	CardSet(QObject *parent=0);
public slots:
	//*
	void reOrder();
	void append(Card&);
	void append(Card*);
///	void add(SI_String);
	void erase(Card&);
	void erase(Card*);
///	void del(SI_String);
	void ins(Card*,int);
	list<Card*>::iterator _getIterator(int);
///	int getPower() const;

#ifdef DEBUG
public:
	void ___print()
	{
		qDebug()<<"Meta_data:-----"<<endl;
		___print_properties();
		qDebug()<<"end-Meta_data:--------"<<endl;
		for(list<Card*>::iterator it=cardSet.begin();it!=cardSet.end();++it)
		{
			(*it)->___print();
		}
		qDebug()<<endl;
	}

#endif //DEBUG
};



#endif // CARDSET_H
