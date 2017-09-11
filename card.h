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

public:
	CardSet* place;
	Game* game;
	int id;

	Card(QObject *parent=0);
//	Card(Game*,QObject *parent=0);
	Card(const Card& tcard);

	bool __initInfo();
	void __readInfo(QTextStream&);
	void __init();
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

	static Card* factory(Game*,SI_String);

	void destroy();
	void setGame(Game*);
	void setup(int,Game*);

	virtual void __doConnect();
public slots:
	//virtual
	virtual void _played_(Row*,int,SI_Object*,SI_String);
	virtual void _dameged_(int,SI_Object*,SI_String);
	virtual void _destroyed_(SI_Object*,SI_String);
	virtual void _exiled_(SI_Object*,SI_String);
	virtual void _drawed_(SI_Object*,SI_String);
	virtual void _boosted_(int,SI_Object*,SI_String);
	virtual void _adjustBasePower_(int,int,SI_Object*,SI_String);
	virtual void _adjustBoostPower_(int,int,SI_Object*,SI_String);
	virtual void _adjustArmor_(int,int,SI_Object*,SI_String);
	virtual void _strengthened_(int,SI_Object*,SI_String);
	virtual void _weakened_(int,SI_Object*,SI_String);
	virtual void _reseted_(SI_Object*,SI_String);
	virtual void _adjustPlace_(CardSet*,int,CardSet*,int,SI_Object*,SI_String); //tar place_src order_src place_tar order_tar (src (info

//	virtual void _playCard_(Card*,Row*,int,SI_Object*,SI_String); //tar tar_row order (info
signals:
	void played_(Row*,int,SI_Object*,SI_String);
	void dameged_(int,SI_Object*,SI_String);
	void destroyed_(SI_Object*,SI_String);
	void exiled_(SI_Object*,SI_String);
	void drawed_(SI_Object*,SI_String);
	void boosted_(int,SI_Object*,SI_String);
	void adjustBasePower_(int,int,SI_Object*,SI_String);
	void adjustBoostPower_(int,int,SI_Object*,SI_String);
	void adjustArmor_(int,int,SI_Object*,SI_String);
	void strengthened_(int,SI_Object*,SI_String);
	void weakened_(int,SI_Object*,SI_String);
	void reseted_(SI_Object*,SI_String);
	void adjustPlace_(CardSet*,int,CardSet*,int,SI_Object*,SI_String); //tar place_src order_src place_tar order_tar (src (info

#ifdef DEBUG
public:
	void ___print()
	{
		//qDebug()<<"CardData:-------------"<<endl;
		//___print_properties();
		qDebug()<<getProperty("name")<<"  "<<getProperty("boostpower").toInt()+getProperty("basepower").toInt()<<endl;
	}

#endif //DEBUG
};


#endif // CARD_H

