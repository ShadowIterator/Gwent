#ifndef CARD_H
#define CARD_H

#include"global.h"
#include"si_object.h"

class Card:public SI_Object
{
	Q_OBJECT

	friend class Field;
private:
//	SI_String imgPath;
//	SI_String dllPath;
//	SI_String onPlay;
//	SI_String onDeath;
//	SI_String onHand;
//	SI_String onBoard;
	CardSet* place;
public:
	Card(QObject *parent=0);

	void __readInfo(QTextStream&);
//	void onPlay();
//	void onDeath();
/*
	void inHand();
	void exHand();
	void inBoard();
	void exBoard();
	void inGraveyard();
	void exGraveyard();

	void onExile();
	void onDameged();
	void onBoosted();
	void onDeath();
*/
	void callFunction(SI_String);
	CardSet* getPlace() const;
	int getOrder() const;
	void setPlace(CardSet*,int);

#ifdef DEBUG

	void ___print()
	{
		qDebug()<<"CardData:-------------"<<endl;
		___print_properties();
	}

#endif //DEBUG
};


#endif // CARD_H
