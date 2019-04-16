#ifndef BATTLE_H
#define BATTLE_H



#include"global.h"
#include"cardset.h"


class Field:public SI_Object
{
	Q_OBJECT
public:
	CardSet* row[MAX_TEAM_NUM][MAX_ROW_NUM];
	CardSet* board[MAX_TEAM_NUM];
	CardSet* hand[MAX_TEAM_NUM];
	CardSet* graveyard[MAX_TEAM_NUM];
	CardSet* deck[MAX_TEAM_NUM];
	CardSet* exiled[MAX_TEAM_NUM];
	CardSet* fullBoard;
	CardSet* selectArea;
	Card* allCard[MAX_CARD_NUM];
	Game* game;
	int cardNum;
	FieldWidget* pwidget;
public:
	Field(QObject* parent=0);
	SI_String __getstr_place(CardSet*);

	void getRowNum(Card*,int&,int&);
	void getRowNum(CardSet*,int&,int&);

	void addtoAllCard(Card*);
	void setGame(Game*);

	bool __loadDeck(int,const SI_String&,const SI_String&);
public slots:

	void playCard(Card*,Row*,int,SI_Object*,SI_String); //tar tar_row order src (info
	void reviveCard(Card*,Row*,int,SI_Object*,SI_String); //tar tar_row order src (info
	void damegeCard(Card*,int,SI_Object*,SI_String); //tar val (src (info
	void destroyCard(Card*,SI_Object*,SI_String); //tar (src (info
	void exileCard(Card*,SI_Object*,SI_String); //tar (src (info
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
	void adjustPlace(Card*,CardSet*,int,SI_Object*,SI_String); //tar place_tar order (src (info
	void adjustProperty(SI_Object*,SI_String,SI_String,SI_Object*,SI_String); //tar pro_tar (info
	void consumeCard(Card*,Card*,SI_Object*,SI_String);
	void reOrder(CardSet*,SI_Object*,SI_String);


	void _playCard_(Card*,Row*,int,SI_Object*,SI_String); //tar tar_row order (info
	void _damegeCard_(Card*,int,SI_Object*,SI_String); //tar val (src (info
	void _destroyCard_(Card*,SI_Object*,SI_String); //tar (src (info
	void _exileCard_(Card*,SI_Object*,SI_String); //tar (src (info
	void _drawCard_(Card*,SI_Object*,SI_String); //tar (src (info
	void _boostCard_(Card*,int,SI_Object*,SI_String); //tar val (src (info
	void _adjustArmor_(Card*,int,int,SI_Object*,SI_String); //tar val_src val_tar (  (info
	void _adjustBasePower_(Card*,int,int,SI_Object*,SI_String); //tar val_src var_tar (src (info
	void _adjustBoostPower_(Card*,int,int,SI_Object*,SI_String); //tar val_src var_tar (src (info
	void _shieldCard_(Card*,SI_Object*,SI_String);
	void _strengthenCard_(Card*,int,SI_Object*,SI_String); //tar val (src (info
	void _weakenCard_(Card*,int,SI_Object*,SI_String); //tar val (src (info
	void _adjustProperty_(SI_Object*,SI_String,SI_String,SI_String,SI_Object*,SI_String); //tar pro_src pro_src pro_tar (info
	void _adjustPlace_(Card*,CardSet*,int,CardSet*,int,SI_Object*,SI_String); //tar place_src order_src place_tar order_tar (src (info
	void _consumeCard_(Card*,Card*,SI_Object*,SI_String);

	void _changeScore_(Card*,int,int);
signals:
	void _shieldCard(Card*,SI_Object*,SI_String);
	void _consumeCard(Card*,Card*,SI_Object*,SI_String);
	void _increaseArmor(Card*,int,SI_Object*,SI_String);
	void _decreaseArmor(Card*,int,SI_Object*,SI_String);
	void _playCard(Card*,Row*,int,SI_Object*,SI_String); //tar tar_row order (info
	void _reviveCard(Card*,Row*,int,SI_Object*,SI_String);
	void _damegeCard(Card*,int,SI_Object*,SI_String); //tar val (src (info
	void _adjustBoostPower(Card*,int,SI_Object*,SI_String); //tar val (src (info
	void _adjustArmor(Card*,int,SI_Object*,SI_String); //tar val (src (info
	void _adjustBasePower(Card*,int,SI_Object*,SI_String); //tar val (src (info
	void _destroyCard(Card*,SI_Object*,SI_String); //tar (src (info
	void _exileCard(Card*,SI_Object*,SI_String); //tar (src (info
	void _drawCard(Card*,SI_Object*,SI_String); //tar (src (info
	void _drawCard(int,SI_Object*,SI_String); //player (src (info
	void _boostCard(Card*,int,SI_Object*,SI_String); //tar val (src (info
	void _strengthenCard(Card*,int,SI_Object*,SI_String); //tar val (src (info
	void _weakenCard(Card*,int,SI_Object*,SI_String); //tar val (src (info
	void _resetCard(Card*,SI_Object*,SI_String); //tar (src (info
	void _setWeather(Row*,SI_String,SI_Object*,SI_String);
	void _removeWeather(Row*,SI_Object*,SI_String);

	void shieldCard_(Card*,SI_Object*,SI_String);
	void consumeCard_(Card*,Card*,SI_Object*,SI_String);
	void playCard_(Card*,Row*,int,SI_Object*,SI_String); //tar tar_row order (info
	void reviveCard_(Card*,Row*,int,SI_Object*,SI_String);
	void damegeCard_(Card*,int,SI_Object*,SI_String); //tar val (src (info
	void destroyCard_(Card*,SI_Object*,SI_String); //tar (src (info
	void exileCard_(Card*,SI_Object*,SI_String); //tar (src (info
	void drawCard_(Card*,SI_Object*,SI_String); //tar (src (info
	void drawCard_(int,SI_Object*,SI_String); //player (src (info
	void boostCard_(Card*,int,SI_Object*,SI_String); //tar val (src (info
	void adjustArmor_(Card*,int,int,SI_Object*,SI_String); //tar val_src val_tar (  (info
	void adjustBasePower_(Card*,int,int,SI_Object*,SI_String); //tar val_src var_tar (src (info
	void adjustBoostPower_(Card*,int,int,SI_Object*,SI_String); //tar val_src var_tar (src (info
	void strengthenCard_(Card*,int,SI_Object*,SI_String); //tar val (src (info
	void weakenCard_(Card*,int,SI_Object*,SI_String); //tar val (src (info
	void resetCard_(Card*,SI_Object*,SI_String); //tar (src (info

	void _adjustProperty(SI_Object*,SI_String,SI_String,SI_Object*,SI_String); //tar pro_tar (info
	void adjustProperty_(SI_Object*,SI_String,SI_String,SI_String,SI_Object*,SI_String); //tar pro_src pro_src pro_tar (info

	void _adjustPlace(Card*,CardSet*,int,SI_Object*,SI_String); //tar place_tar order (src (info
	void adjustPlace_(Card*,CardSet*,int,CardSet*,int,SI_Object*,SI_String); //tar place_src order_src place_tar order_tar (src (info

	void setWeather_(Row*,Weather*,SI_Object*,SI_String);
	void removeWeather_(Row*,SI_Object*,SI_String);


	void _reOrder(CardSet*,SI_Object*,SI_String);

signals:

	void _ui_setPlace(Card*,CardSet*,int);
	void _ui_setCardProperty(Card*,SI_String,SI_String);
	void _ui_setWeather(CardSet*,SI_String);
public slots:
	void ui_setWeather(CardSet*,SI_String);
	void ui_setPlace(Card*,CardSet*,int);
	void ui_setCardProperty(Card*,SI_String,SI_String);

public:
	void _ui_updateAll();
#ifdef DEBUG
public:
	void ___printBoard()
	{
		for(int team=0;team!=2;++team)
		{
			qDebug()<<"Team #"<<team<<":----------------------"<<endl;
			for(int k=0;k!=MAX_ROW_NUM;++k)
			{
				row[team][k]->___print();
			}
		}

	}

#endif //DEBUG
};


#endif // BATTLE_H
