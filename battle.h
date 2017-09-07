#ifndef BATTLE_H
#define BATTLE_H

#define DEBUG

//#include<map>
#include<QMap>
#include<list>
#include<vector>
#include<QString>
#include<QtCore>
#include<random>
#include<fstream>
#include<string>
#include<iostream>

typedef QString SI_String;

using std::string;
using std::cin;
using std::ifstream;
using std::map;
using std::list;
using std::vector;
//using std::shufle;
//using std::QQMap<SI_String,SI_String>::iterator;

class SI_Object;
class CardSet;
class Card;
class Field;
class Operator;

class SI_Object:public QObject
{
	Q_OBJECT
//private:
//public:
public:
	QMap<SI_String,SI_String> properties; //no "place"
public:
	//SI_Object();
	SI_Object(QObject *parent=0);
	SI_String getProperty(const SI_String&) const;

	QMap<SI_String,SI_String>::iterator getBegin();
	QMap<SI_String,SI_String>::iterator getEnd();

public slots:
	void setProperty(const SI_String&,const SI_String&);
#ifdef DEBUG

	void ___print_properties()
	{
		for(QMap<SI_String,SI_String>::iterator it=properties.begin();it!=properties.end();++it)
		{
			qDebug()<<it.key()<<" : "<<it.value()<<endl;
		}
	}

#endif //DEBUG
};



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

typedef CardSet Row;

class User:public SI_Object
{
	Q_OBJECT
public:
	User(QObject *parent=0);
};

const int MAX_TEAM_NUM=2;
const int MAX_ROW_NUM=3;
const int MAX_CARD_NUM=400;

class Field:public SI_Object
{
	Q_OBJECT
//	friend class Operator;
//private:
public:
	CardSet row[MAX_TEAM_NUM][MAX_ROW_NUM];
	CardSet board[MAX_TEAM_NUM];
	CardSet hand[MAX_TEAM_NUM];
	CardSet graveyard[MAX_TEAM_NUM];
	CardSet deck[MAX_TEAM_NUM];
	CardSet exiled[MAX_TEAM_NUM];
	Card* allCard[MAX_CARD_NUM];
	int cardNum;
	User user[2];
public:
	Field(QObject* parent=0);
//	CardSet* __getptr_place(SI_String);
	SI_String __getstr_place(CardSet*);
public slots:

	void playCard(Card*,Row*,int,SI_Object*,SI_String); //tar tar_row order src (info
	void damegeCard(Card*,int,SI_Object*,SI_String); //tar val (src (info
	void destroyCard(Card*,SI_Object*,SI_String); //tar (src (info
	void exileCard(Card*,SI_Object*,SI_String); //tar (src (info
///	void disCard(Card*,SI_Object*,SI_String); //tar (src (info
	void drawCard(Card*,SI_Object*,SI_String); //tar (src (info
	void drawCard(int,SI_Object*,SI_String); //player (src (info
	void boostCard(Card*,int,SI_Object*,SI_String); //tar val (src (info
	void adjustArmor(Card*,int,SI_Object*,SI_String); //tar val (src (info
//	void decreaseArmor(Card*,SI_Object*,SI_String); //tar (src (info
	void adjustBasePower(Card*,int,SI_Object*,SI_String);
	void adjustBoostPower(Card*,int,SI_Object*,SI_String);
	void strengthenCard(Card*,int,SI_Object*,SI_String); //tar val (src (info
	void weakenCard(Card*,int,SI_Object*,SI_String); //tar val (src (info

	void resetCard(Card*,SI_Object*,SI_String); //tar (src (info

///	void infield(Card*,SI_Object*,SI_String); //tar (src (info
///	void exfield(Card*,SI_Object*,SI_String); //tar (src (info
///	void ingraveyardCard(Card*,SI_Object*,SI_String); //tar (src (info
///	void exgraveyardCard(Card*,SI_Object*,SI_String); //tar (src (info
///	void inhandCard(Card*,SI_Object*,SI_String); //tar (src (info

//	void propertyChanged(SI_Object*,SI_String,SI_String); //tar pro_src  (info

///	void _playCard_(Card*,Row*,int,SI_String); //tar tar_row order (info
///	void _damegeCard_(Card*,int,SI_Object*,SI_String); //tar val (src (info
///	void _destroyCard_(Card*,SI_Object*,SI_String); //tar (src (info
///	void _exileCard_(Card*,SI_Object*,SI_String); //tar (src (info
///	void _disCard_(Card*,SI_Object*,SI_String); //tar (src (info
///	void _drawCard_(Card*,SI_Object*,SI_String); //tar (src (info
///	void _drawCard_(int,SI_Object*,SI_String); //player (src (info
///	void _boostCard_(Card*,int,SI_Object*,SI_String); //tar val (src (info
///	void _adjustArmor_(Card*,int,int,SI_Object*,SI_String); //tar val (src (info
//	void _decreaseArmor_(Card*,SI_Object*,SI_String); //tar (src (info
///	void _strengthenCard_(Card*,int,SI_Object*,SI_String); //tar val (src (info
///	void _weakenCard_(Card*,int,SI_Object*,SI_String); //tar val (src (info
///	void _resetCard_(Card*,SI_Object*,SI_String); //tar (src (info

///	void _infield_(Card*,SI_Object*,SI_String); //tar (src (info
///	void _exfield_(Card*,SI_Object*,SI_String); //tar (src (info
///	void _ingraveyardCard_(Card*,SI_Object*,SI_String); //tar (src (info
///	void _exgraveyardCard_(Card*,SI_Object*,SI_String); //tar (src (info
///	void _inhandCard_(Card*,SI_Object*,SI_String); //tar (src (info

//	void _propertyChanged_(SI_Object*,SI_String,SI_String,SI_String); //tar pro_src pro_tar (info
/// void _adjustProperty()
	void adjustPlace(Card*,CardSet*,int,SI_Object*,SI_String); //tar place_tar order (src (info
//	void _djustPlace_(Card*,SI_String,SI_String,SI_Object*,SI_String); //tar place_src place_tar (src (info
///	void _adjustPlace_(Card*,CardSet*,int,CardSet*,int,SI_Object*,SI_String); //tar place_src order_src place_tar order_tar (src (info

	void adjustProperty(SI_Object*,SI_String,SI_String,SI_Object*,SI_String); //tar pro_tar (info
///	void _adjustProperty_(SI_Object*,SI_String,SI_String,SI_String,SI_Object*,SI_String); //tar pro_src pro_src pro_tar (info

signals:
	//*
	void _playCard(Card*,Row*,int,SI_Object*,SI_String); //tar tar_row order (info
	//*
	void _damegeCard(Card*,int,SI_Object*,SI_String); //tar val (src (info
	//*
	void _adjustBoostPower(Card*,int,SI_Object*,SI_String); //tar val (src (info
	//*
	void _adjustArmor(Card*,int,SI_Object*,SI_String); //tar val (src (info
	//*
	void _adjustBasePower(Card*,int,SI_Object*,SI_String); //tar val (src (info
	//*
	void _destroyCard(Card*,SI_Object*,SI_String); //tar (src (info
	//*
	void _exileCard(Card*,SI_Object*,SI_String); //tar (src (info
///	void _disCard(Card*,SI_Object*,SI_String); //tar (src (info
	//*
	void _drawCard(Card*,SI_Object*,SI_String); //tar (src (info
	//*
	void _drawCard(int,SI_Object*,SI_String); //player (src (info
	//*
	void _boostCard(Card*,int,SI_Object*,SI_String); //tar val (src (info

//	void _decreaseArmor(Card*,SI_Object*,SI_String); //tar (src (info
	void _strengthenCard(Card*,int,SI_Object*,SI_String); //tar val (src (info
	void _weakenCard(Card*,int,SI_Object*,SI_String); //tar val (src (info
	//*
	void _resetCard(Card*,SI_Object*,SI_String); //tar (src (info

///	void _infield(Card*,SI_Object*,SI_String); //tar (src (info
///	void _exfield(Card*,SI_Object*,SI_String); //tar (src (info
///	void _ingraveyardCard(Card*,SI_Object*,SI_String); //tar (src (info
///	void _exgraveyardCard(Card*,SI_Object*,SI_String); //tar (src (info
///	void _inhandCard(Card*,SI_Object*,SI_String); //tar (src (info

//----------------------------------------------------------------------------
	void playCard_(Card*,Row*,int,SI_Object*,SI_String); //tar tar_row order (info
	void damegeCard_(Card*,int,SI_Object*,SI_String); //tar val (src (info
	void destroyCard_(Card*,SI_Object*,SI_String); //tar (src (info
	void exileCard_(Card*,SI_Object*,SI_String); //tar (src (info
	void disCard_(Card*,SI_Object*,SI_String); //tar (src (info
	void drawCard_(Card*,SI_Object*,SI_String); //tar (src (info
	void drawCard_(int,SI_Object*,SI_String); //player (src (info
	void boostCard_(Card*,int,SI_Object*,SI_String); //tar val (src (info
	void adjustArmor_(Card*,int,int,SI_Object*,SI_String); //tar val_src val_tar (src (info
	void adjustBasePower_(Card*,int,int,SI_Object*,SI_String); //tar val_src var_tar (src (info
	void adjustBoostPower_(Card*,int,int,SI_Object*,SI_String); //tar val_src var_tar (src (info

	//	void decreaseArmor_(Card*,SI_Object*,SI_String); //tar (src (info
	void strengthenCard_(Card*,int,SI_Object*,SI_String); //tar val (src (info
	void weakenCard_(Card*,int,SI_Object*,SI_String); //tar val (src (info
	void resetCard_(Card*,SI_Object*,SI_String); //tar (src (info

	void infield_(Card*,SI_Object*,SI_String); //tar (src (info
	void exfield_(Card*,SI_Object*,SI_String); //tar (src (info
	void ingraveyardCard_(Card*,SI_Object*,SI_String); //tar (src (info
	void exgraveyardCard_(Card*,SI_Object*,SI_String); //tar (src (info
	void inhandCard_(Card*,SI_Object*,SI_String); //tar (src (info

	//otherwise
	//used when a slot unable to be connected to the signals above
	//*
	void _adjustProperty(SI_Object*,SI_String,SI_String,SI_Object*,SI_String); //tar pro_tar (info
	void adjustProperty_(SI_Object*,SI_String,SI_String,SI_String,SI_Object*,SI_String); //tar pro_src pro_src pro_tar (info

//	void _adjustProperty(SI_Object*,SI_String,SI_String,SI_Object*,SI_String) //tar proN_tar proV_tar (src (info

	//*
	void _adjustPlace(Card*,CardSet*,int,SI_Object*,SI_String); //tar place_tar order (src (info
//	void placeChanged_(Card*,SI_String,SI_String,SI_Object*,SI_String); //tar place_src place_tar (src (info
	void adjustPlace_(Card*,CardSet*,int,CardSet*,int,SI_Object*,SI_String); //tar place_src order_src place_tar order_tar (src (info

#ifdef DEBUG
public:
	void ___printBoard()
	{
		for(int team=0;team!=2;++team)
		{
			qDebug()<<"Team #"<<team<<":----------------------"<<endl;
			for(int k=0;k!=MAX_ROW_NUM;++k)
			{
				qDebug()<<"Row #"<<k<<":-------------"<<endl;
				row[team][k].___print();
			}
			qDebug()<<"Hand:---------------"<<endl;
			hand[team].___print();
			qDebug()<<"Graveyard:---------------"<<endl;
			graveyard[team].___print();
			qDebug()<<"Deck:-------------------"<<endl;
			deck[team].___print();
			qDebug()<<"Exiled:-----------------"<<endl;
			exiled[team].___print();
		}

	}

#endif //DEBUG
};

class UserInteraction:public QObject
{
	Q_OBJECT
private:
	Field field;
};

class FlowControl:public QObject
{
public:
	Field field;
	int curTeam;
public:
	FlowControl(QObject* parent=0);
	void __init();
	void __test();
};

#endif // BATTLE_H
