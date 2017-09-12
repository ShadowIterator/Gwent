#ifndef BATTLE_H
#define BATTLE_H



#include"global.h"
#include"cardset.h"
#include"user.h"


class Field:public SI_Object
{
	Q_OBJECT
//	friend class Operator;
//private:
public:
	CardSet* row[MAX_TEAM_NUM][MAX_ROW_NUM];
	CardSet* board[MAX_TEAM_NUM];
	CardSet* hand[MAX_TEAM_NUM];
	CardSet* graveyard[MAX_TEAM_NUM];
	CardSet* deck[MAX_TEAM_NUM];
	CardSet* exiled[MAX_TEAM_NUM];
	CardSet* fullBoard;
	Card* allCard[MAX_CARD_NUM];
	Game* game;
	int cardNum;
	User user[2];
public:
	Field(QObject* parent=0);
//	CardSet* __getptr_place(SI_String);
	SI_String __getstr_place(CardSet*);

	void getRowNum(Card*,int&,int&);
	void getRowNum(CardSet*,int&,int&);

	void addtoAllCard(Card*);
	void setGame(Game*);
//add somthing
	bool __loadDeck(int,const SI_String&,const SI_String&);
public slots:

	void playCard(Card*,Row*,int,SI_Object*,SI_String); //tar tar_row order src (info
	void reviveCard(Card*,Row*,int,SI_Object*,SI_String); //tar tar_row order src (info
	void damegeCard(Card*,int,SI_Object*,SI_String); //tar val (src (info
	void destroyCard(Card*,SI_Object*,SI_String); //tar (src (info
	void exileCard(Card*,SI_Object*,SI_String); //tar (src (info
///	void disCard(Card*,SI_Object*,SI_String); //tar (src (info
	void drawCard(Card*,SI_Object*,SI_String); //tar (src (info
	void drawCard(int,SI_Object*,SI_String); //player (src (info
	void boostCard(Card*,int,SI_Object*,SI_String); //tar val (src (info
	void adjustArmor(Card*,int,SI_Object*,SI_String); //tar val (src (info
	void adjustBasePower(Card*,int,SI_Object*,SI_String);
	void adjustBoostPower(Card*,int,SI_Object*,SI_String);
	void strengthenCard(Card*,int,SI_Object*,SI_String); //tar val (src (info
	void weakenCard(Card*,int,SI_Object*,SI_String); //tar val (src (info
	void increaseArmor(Card*,int,SI_Object*,SI_String);
	void decreaseArmor(Card*,int,SI_Object*,SI_String);
	void resetCard(Card*,SI_Object*,SI_String); //tar (src (info
	void shieldCard(Card*,SI_Object*,SI_String);
	void setWeather(Row*,SI_String,SI_Object*,SI_String);
	void removeWeather(Row*,SI_Object*,SI_String);


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
	void consumeCard(Card*,Card*,SI_Object*,SI_String);
	void reOrder(CardSet*,SI_Object*,SI_String);


	void _playCard_(Card*,Row*,int,SI_Object*,SI_String); //tar tar_row order (info
	void _damegeCard_(Card*,int,SI_Object*,SI_String); //tar val (src (info
	void _destroyCard_(Card*,SI_Object*,SI_String); //tar (src (info
	void _exileCard_(Card*,SI_Object*,SI_String); //tar (src (info
///	void _disCard_(Card*,SI_Object*,SI_String); //tar (src (info
	void _drawCard_(Card*,SI_Object*,SI_String); //tar (src (info
//	void _drawCard_(int,SI_Object*,SI_String); //player (src (info
	void _boostCard_(Card*,int,SI_Object*,SI_String); //tar val (src (info
	void _adjustArmor_(Card*,int,int,SI_Object*,SI_String); //tar val_src val_tar (  (info
	void _adjustBasePower_(Card*,int,int,SI_Object*,SI_String); //tar val_src var_tar (src (info
	void _adjustBoostPower_(Card*,int,int,SI_Object*,SI_String); //tar val_src var_tar (src (info
	void _shieldCard_(Card*,SI_Object*,SI_String);
	//	void decreaseArmor_(Card*,SI_Object*,SI_String); //tar (src (info
	void _strengthenCard_(Card*,int,SI_Object*,SI_String); //tar val (src (info
	void _weakenCard_(Card*,int,SI_Object*,SI_String); //tar val (src (info
//	void _resetCard_(Card*,SI_Object*,SI_String); //tar (src (info
	void _adjustProperty_(SI_Object*,SI_String,SI_String,SI_String,SI_Object*,SI_String); //tar pro_src pro_src pro_tar (info
	void _adjustPlace_(Card*,CardSet*,int,CardSet*,int,SI_Object*,SI_String); //tar place_src order_src place_tar order_tar (src (info
	void _consumeCard_(Card*,Card*,SI_Object*,SI_String);

	void _changeScore_(Card*,int,int);
signals:
	void _shieldCard(Card*,SI_Object*,SI_String);
	void _consumeCard(Card*,Card*,SI_Object*,SI_String);
	void _increaseArmor(Card*,int,SI_Object*,SI_String);
	void _decreaseArmor(Card*,int,SI_Object*,SI_String);
	//*
	void _playCard(Card*,Row*,int,SI_Object*,SI_String); //tar tar_row order (info
	void _reviveCard(Card*,Row*,int,SI_Object*,SI_String);
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

	void _setWeather(Row*,SI_String,SI_Object*,SI_String);
	void _removeWeather(Row*,SI_Object*,SI_String);
///	void _infield(Card*,SI_Object*,SI_String); //tar (src (info
///	void _exfield(Card*,SI_Object*,SI_String); //tar (src (info
///	void _ingraveyardCard(Card*,SI_Object*,SI_String); //tar (src (info
///	void _exgraveyardCard(Card*,SI_Object*,SI_String); //tar (src (info
///	void _inhandCard(Card*,SI_Object*,SI_String); //tar (src (info

//----------------------------------------------------------------------------
	void shieldCard_(Card*,SI_Object*,SI_String);
	void consumeCard_(Card*,Card*,SI_Object*,SI_String);
	void playCard_(Card*,Row*,int,SI_Object*,SI_String); //tar tar_row order (info
	void reviveCard_(Card*,Row*,int,SI_Object*,SI_String);
	void damegeCard_(Card*,int,SI_Object*,SI_String); //tar val (src (info
	void destroyCard_(Card*,SI_Object*,SI_String); //tar (src (info
	void exileCard_(Card*,SI_Object*,SI_String); //tar (src (info
///	void disCard_(Card*,SI_Object*,SI_String); //tar (src (info
	void drawCard_(Card*,SI_Object*,SI_String); //tar (src (info
	//no slot
	void drawCard_(int,SI_Object*,SI_String); //player (src (info
	void boostCard_(Card*,int,SI_Object*,SI_String); //tar val (src (info
	void adjustArmor_(Card*,int,int,SI_Object*,SI_String); //tar val_src val_tar (  (info
	void adjustBasePower_(Card*,int,int,SI_Object*,SI_String); //tar val_src var_tar (src (info
	void adjustBoostPower_(Card*,int,int,SI_Object*,SI_String); //tar val_src var_tar (src (info

	//	void decreaseArmor_(Card*,SI_Object*,SI_String); //tar (src (info
	void strengthenCard_(Card*,int,SI_Object*,SI_String); //tar val (src (info
	void weakenCard_(Card*,int,SI_Object*,SI_String); //tar val (src (info
	void resetCard_(Card*,SI_Object*,SI_String); //tar (src (info
/*
	void infield_(Card*,SI_Object*,SI_String); //tar (src (info
	void exfield_(Card*,SI_Object*,SI_String); //tar (src (info
	void ingraveyardCard_(Card*,SI_Object*,SI_String); //tar (src (info
	void exgraveyardCard_(Card*,SI_Object*,SI_String); //tar (src (info
	void inhandCard_(Card*,SI_Object*,SI_String); //tar (src (info
*/
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

	void setWeather_(Row*,Weather*,SI_Object*,SI_String);
	void removeWeather_(Row*,SI_Object*,SI_String);


	void _reOrder(CardSet*,SI_Object*,SI_String);
#ifdef DEBUG
public:
	void ___printBoard()
	{
		for(int team=0;team!=2;++team)
		{
			qDebug()<<"Team #"<<team<<":----------------------"<<endl;
			for(int k=0;k!=MAX_ROW_NUM;++k)
			{
				//qDebug()<<"Row #"<<k<<":-------------"<<endl;
				row[team][k]->___print();
				//qDebug()<<"--------------------------------"
				//		<<row[team][k]->getProperty("name")<<endl
				//		<<"score "<<row[team][k]->score<<endl;

			}
			/*
			qDebug()<<"Hand:---------------"<<endl;
			hand[team]->___print();
			qDebug()<<"Graveyard:---------------"<<endl;
			graveyard[team]->___print();
			qDebug()<<"Deck:-------------------"<<endl;
			deck[team]->___print();
			qDebug()<<"Exiled:-----------------"<<endl;
			exiled[team]->___print();
			*/
		}

	}

#endif //DEBUG
};


#endif // BATTLE_H
