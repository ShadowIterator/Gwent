#include"field.h"
#include"weather.h"
#include"fieldwidget.h"
#include"cardwidget.h"
#include"cardsetwidget.h"

void Field::setGame(Game *pgame)
{
	game=pgame;
}

void Field::addtoAllCard(Card *pcard)
{
	allCard[cardNum++]=pcard;
}

void Field::getRowNum(Card *pcard, int &teamNum, int &rowNum)
{
	teamNum=rowNum=-1;
	for(int team=0;team!=MAX_TEAM_NUM;++team)
		for(int k=0;k!=MAX_ROW_NUM;++k)
			if(row[team][k]->checkCard(pcard))
			{
				teamNum=team;
				rowNum=k;
				return ;
			}
}

void Field::getRowNum(CardSet *prow, int &teamNum, int &rowNum)
{
	teamNum=rowNum=-1;
	for(int team=0;team!=MAX_TEAM_NUM;++team)
		for(int k=0;k!=MAX_ROW_NUM;++k)
			if(row[team][k]==prow)
			{
				teamNum=team;
				rowNum=k;
				return ;
			}
}

SI_String Field::__getstr_place(CardSet* place)
{
	int teamNum;
	int rowNum;
	SI_String rtn;
	rtn.clear();
	for(teamNum=0;teamNum<MAX_TEAM_NUM;++teamNum)
		for(rowNum=0;rowNum<MAX_ROW_NUM;++rowNum)
			if(row[teamNum][rowNum]==place)
				return (teamNum+'0')+"_Row_"+(rowNum+'0');

	for(teamNum=0;teamNum<MAX_TEAM_NUM;++teamNum)
		if(hand[teamNum]==place)
			return (teamNum+'0')+"_Hand_"+(rowNum+'0');

	for(teamNum=0;teamNum<MAX_TEAM_NUM;++teamNum)
		if(deck[teamNum]==place)
			return (teamNum+'0')+"_Deck_"+(rowNum+'0');

	for(teamNum=0;teamNum<MAX_TEAM_NUM;++teamNum)
		if(graveyard[teamNum]==place)
			return (teamNum+'0')+"_Graveyard_"+(rowNum+'0');

	for(teamNum=0;teamNum<MAX_TEAM_NUM;++teamNum)
		if(exiled[teamNum]==place)
			return (teamNum+'0')+"_Exiled_"+(rowNum+'0');

	return "0_Nowhere_0";
}



int getid(SI_String cardName)
{
	int id=QMetaType::type(cardName.toLatin1());
	return id;
}


bool Field::__loadDeck(int team, const SI_String &deckPath,const SI_String& cardDir)
{
	QFile fdeck(deckPath);

	if(!fdeck.open(QIODevice::ReadOnly))
	{
		qFatal("open file failed");
		return false;
	}
	QTextStream deckin(&fdeck);

	QString cardName;
	Card* pcard;

	__inputQString(deckin,cardName);
	__inputQString(deckin,cardName);
	while(cardName!="}")
	{
		pcard=allCard[cardNum++]=Card::factory(game,cardName);
		pcard->setPlace(deck[team],-1);
		pcard->setProperty("team",SI_String::number(team));
		pcard->setProperty("tenacity","false");

		__inputQString(deckin,cardName);
	}
	return true;
}

void Field::reOrder(CardSet *pcardSet, SI_Object *psrc, SI_String info)
{
    pcardSet->reOrder();
}

void Field::adjustPlace(Card *pcard,CardSet* pcardSet,int order,SI_Object* psrc,SI_String info) //tar tarcardSet order (src (info
{
	CardSet* srcPlace=pcard->place;
	int srcOrder=-1;
	if(srcPlace!=NULL) pcard->getOrder();
	pcard->setPlace(pcardSet,order);
	emit adjustPlace_(pcard,srcPlace,srcOrder,pcardSet,order,psrc,info);
}

void Field::playCard(Card* pcard,Row* prow,int order,SI_Object* psrc,SI_String info) //tar tar_row order (info
{
	if(pcard->getProperty("type")!="spell")
		emit _adjustPlace(pcard,prow,order,psrc,info);
	else
		emit _destroyCard(pcard,psrc,info);
	emit playCard_(pcard,prow,order,psrc,info);
}

void Field::reviveCard(Card *pcard, Row *prow, int order, SI_Object *psrc, SI_String info)
{
	emit reviveCard_(pcard,prow,order,psrc,info);
	emit _adjustPlace(pcard,prow,order,psrc,info);
}

void Field::exileCard(Card* pcard,SI_Object* src,SI_String info) //tar (src (info
{
	emit exileCard_(pcard,src,info);
	emit _adjustPlace(pcard,exiled[pcard->getProperty("team").toInt()],-1,src,info);
}

void Field::increaseArmor(Card *pcard, int val, SI_Object *psrc, SI_String info)
{
	int oriArmor=pcard->getProperty("armor").toInt();
	emit _adjustArmor(pcard,val+oriArmor,psrc,info);
}

void Field::decreaseArmor(Card *pcard, int val, SI_Object *psrc, SI_String info)
{
	int oriArmor=pcard->getProperty("armor").toInt();
	emit _adjustArmor(pcard,Max(oriArmor-val,0),psrc,info);
}

void Field::damegeCard(Card* ptarCard,int val,SI_Object* psrc,SI_String info) //tar val (src (info
{

	if(ptarCard->getProperty("shield")=="true")
	{
		emit _adjustProperty(ptarCard,"shield","false",psrc,info);
		return ;
	}
	int srcArmor=ptarCard->getProperty("armor").toInt();
	int srcBoostPower=ptarCard->getProperty("boostpower").toInt();
	int srcBasePower=ptarCard->getProperty("basepower").toInt();

	int tarArmor=srcArmor;
	int tarBoostPower=srcBoostPower;

	tarArmor=Max(0,srcArmor-val);
	val=Max(val-srcArmor,0);

	tarBoostPower=srcBoostPower-val;

	if(tarArmor!=srcArmor)
		emit _adjustArmor(ptarCard,tarArmor,psrc,info);
	if(tarBoostPower!=srcBoostPower)
		emit _adjustBoostPower(ptarCard,tarBoostPower,psrc,info);
	if(srcBasePower+tarBoostPower<=0)
		emit _destroyCard(ptarCard,psrc,info);

	emit damegeCard_(ptarCard,val,psrc,info);
}

void Field::destroyCard(Card* ptarCard,SI_Object* psrc,SI_String info) //tar (src (info
{
	emit destroyCard_(ptarCard,psrc,info);
	emit _resetCard(ptarCard,psrc,info);
	if(ptarCard->getProperty("doomed")!="true")
		emit _adjustPlace(ptarCard,graveyard[ptarCard->getProperty("team").toInt()],-1,psrc,info);
	else
		emit _adjustPlace(ptarCard,exiled[ptarCard->getProperty("team").toInt()],-1,psrc,info);
}

void Field::drawCard(Card *pcard, SI_Object *psrc, SI_String info)
{
	emit _adjustPlace(pcard,hand[pcard->getProperty("team").toInt()],-1,psrc,info);
	emit drawCard_(pcard,psrc,info);
}

void Field::drawCard(int team,SI_Object* psrc,SI_String info)
{
	if(deck[team]->cardSet.size()==0)
	{
		// todo : handle no card condition
	}
	drawCard(*(deck[team]->cardSet.begin()),psrc,info);
}

void Field::boostCard(Card *pcard, int val, SI_Object *psrc, SI_String info)
{
	emit _adjustBoostPower(pcard,val+pcard->getProperty("boostpower").toInt(),psrc,info);
	emit boostCard_(pcard,val,psrc,info);
}

void Field::consumeCard(Card *psrcCard, Card *ptarCard, SI_Object *psrc, SI_String info)
{
	int power=ptarCard->getProperty("basepower").toInt()+ptarCard->getProperty("boostpower").toInt();
	emit _strengthenCard(psrcCard,power,psrc,info);
	emit _destroyCard(ptarCard,psrc,info);
	emit consumeCard_(psrcCard,ptarCard,psrc,info);
}

void Field::strengthenCard(Card *pcard, int val, SI_Object *psrc, SI_String info)
{
	emit _adjustBasePower(pcard,val+pcard->getProperty("basepower").toInt(),psrc,info);
	emit strengthenCard_(pcard,val,psrc,info);
}

void Field::weakenCard(Card *pcard, int val, SI_Object *psrc, SI_String info)
{
	int tarBasePower=pcard->getProperty("basepower").toInt();
	tarBasePower-=val;
	if(tarBasePower>0)
		emit _adjustBasePower(pcard,tarBasePower,psrc,info);
	else
		emit _destroyCard(pcard,psrc,info);
	emit weakenCard_(pcard,val,psrc,info);
}

void Field::adjustBasePower(Card *pcard, int val, SI_Object *psrc, SI_String info)
{
	int ori_basePower=pcard->getProperty("basepower").toInt();
	emit _adjustProperty(pcard,"basepower",SI_String::number(val),psrc,info);
	emit adjustBasePower_(pcard,ori_basePower,val,psrc,info);
}

void Field::adjustArmor(Card *pcard, int val, SI_Object *psrc, SI_String info)
{
	int ori_armor=pcard->getProperty("armor").toInt();
	emit _adjustProperty(pcard,"armor",SI_String::number(val),psrc,info);
	emit adjustArmor_(pcard,ori_armor,val,psrc,info);
}

void Field::adjustBoostPower(Card* pcard,int val,SI_Object* psrc,SI_String info)
{
	int ori_boostPower=pcard->getProperty("boostpower").toInt();
	emit _adjustProperty(pcard,"boostpower",SI_String::number(val),psrc,info);
	emit adjustBoostPower_(pcard,ori_boostPower,val,psrc,info);
}

void Field::shieldCard(Card *pcard, SI_Object *psrc, SI_String info)
{
	emit _adjustProperty(pcard,"shield","true",psrc,info);
	emit shieldCard_(pcard,psrc,info);
}

void Field::resetCard(Card *pcard,SI_Object* psrc,SI_String info)
{
	SI_String propertyName;
	SI_String propertyName_ori;
	SI_String propertyVal_ori;
	for(QMap<SI_String,SI_String>::iterator it=pcard->getBegin();it!=pcard->getEnd();++it)
	{
		propertyName=it.key();
		propertyVal_ori=pcard->getProperty("ori_"+propertyName);
		if(propertyVal_ori!="NoResult")
		{
			if(propertyName=="boostpower")
				emit _adjustBoostPower(pcard,propertyVal_ori.toInt(),psrc,info);
			else if(propertyName=="basepower")
				emit _adjustBasePower(pcard,propertyVal_ori.toInt(),psrc,info);
			else
				emit _adjustProperty(pcard,propertyName,propertyVal_ori,psrc,info);
		}
	}
	emit resetCard_(pcard,psrc,info);
}

void Field::adjustProperty(SI_Object *pcard, SI_String propertyName, SI_String propertyVal, SI_Object *psrc, SI_String info)
{
	SI_String propertyVal_ori=pcard->getProperty(propertyName);
	pcard->setProperty(propertyName,propertyVal);
	emit adjustProperty_(pcard,propertyName,propertyVal_ori,propertyVal,psrc,info);
}

void Field::setWeather(Row *prow, SI_String weatherName, SI_Object *psrc, SI_String info)
{
	Weather* oriWeather=prow->weather;
	if(oriWeather!=NULL)
	{
		if(oriWeather->getProperty("name")!=weatherName)
			emit _removeWeather(prow,psrc,info);
		else
			return ;
	}
	prow->weather=Weather::factory(game,weatherName);
	prow->weather->setToRow(prow);
	prow->weather->setProperty("team",psrc->getProperty("team"));

	emit setWeather_(prow,prow->weather,psrc,info);
}

void Field::removeWeather(Row *prow, SI_Object *psrc, SI_String info)
{
	if(prow->weather==NULL) return ;
	prow->weather->removeFromRow();
	emit removeWeather_(prow,psrc,info);
}

void Field::_playCard_(Card *pcard, Row *row, int order, SI_Object *psrc, SI_String info)
{
	emit pcard->played_(row,order,psrc,info);
}

void Field::_damegeCard_(Card *pcard, int val, SI_Object *psrc, SI_String info)
{
	emit pcard->dameged_(val,psrc,info);
}

void Field::_destroyCard_(Card *pcard, SI_Object *psrc, SI_String info)
{
	emit pcard->destroyed_(psrc,info);
}

void Field::_exileCard_(Card *pcard, SI_Object *psrc, SI_String info)
{
	emit pcard->exiled_(psrc,info);
}

void Field::_drawCard_(Card *pcard, SI_Object *psrc, SI_String info)
{
	emit pcard->drawed_(psrc,info);
}

void Field::_boostCard_(Card *pcard, int val, SI_Object *psrc, SI_String info)
{
	emit pcard->boosted_(val,psrc,info);
}

void Field::_adjustArmor_(Card *pcard, int oriVal, int tarVal, SI_Object *psrc, SI_String info)
{
	emit pcard->adjustArmor_(oriVal,tarVal,psrc,info);
}

void Field::_adjustBasePower_(Card *pcard, int oriVal, int tarVal, SI_Object *psrc, SI_String info)
{
	emit pcard->adjustBasePower_(oriVal,tarVal,psrc,info);
}

void Field::_adjustBoostPower_(Card *pcard, int oriVal, int tarVal, SI_Object *psrc, SI_String info)
{
	emit pcard->adjustBoostPower_(oriVal,tarVal,psrc,info);
}

void Field::_strengthenCard_(Card *pcard, int val, SI_Object *psrc, SI_String info)
{
	emit pcard->strengthened_(val,psrc,info);
}

void Field::_weakenCard_(Card *pcard, int val, SI_Object *psrc, SI_String info)
{
	emit pcard->weakened_(val,psrc,info);
}

void Field::_adjustPlace_(Card *pcard, CardSet *oriCardSet, int oriOrder, CardSet *tarCardSet, int tarOrder, SI_Object *psrc, SI_String info)
{
	emit pcard->adjustPlace_(oriCardSet,oriOrder,tarCardSet,tarOrder,psrc,info);
}

void Field::_shieldCard_(Card *pcard, SI_Object *psrc, SI_String info)
{

}

void Field::_changeScore_(Card *pcard, int oriVal, int tarVal)
{
	if(pcard->place!=NULL)
	{
		pcard->place->__changeScore(tarVal-oriVal);
	}
}

void Field::_adjustProperty_(SI_Object *pobj, SI_String propertyName, SI_String oriVal, SI_String tarVal, SI_Object *psrc, SI_String info)
{
	emit pobj->adjustProperty_(propertyName,oriVal,tarVal,psrc,info);
}

void Field::_consumeCard_(Card *psrcCard, Card *ptarCard, SI_Object *psrc, SI_String info)
{
	emit psrcCard->consume_(ptarCard,psrc,info);
	emit ptarCard->consumed_(psrcCard,psrc,info);
}

//ui

void Field::ui_setPlace(Card *pcard, CardSet *ptarPlace,int order)
{
	emit _adjustPlace(pcard,ptarPlace,order,NULL,noinfo);
}

void Field::ui_setCardProperty(Card *pcard, SI_String propertyName, SI_String propertyVal)
{
	emit _adjustProperty(pcard,propertyName,propertyVal,NULL,noinfo);
}

void Field::_ui_updateAll()
{
	for(int team=0;team!=MAX_TEAM_NUM;++team)
	{
		for(int k=0;k!=MAX_ROW_NUM;++k)
			if(row[team][k]->pwidget!=NULL)
				row[team][k]->pwidget->_update();
		if(hand[team]->pwidget!=NULL)
			hand[team]->pwidget->_update();
		if(graveyard[team]->pwidget!=NULL)
			graveyard[team]->pwidget->_update();
	}
	if(selectArea->pwidget!=NULL)
		selectArea->pwidget->_update();
}

void Field::ui_setWeather(CardSet *pcardSet, SI_String weather)
{
	pcardSet->setProperty("weather",weather);
}

Field::Field(QObject *parent):SI_Object(parent),game(NULL)
{
	pwidget=new FieldWidget(this);

	fullBoard=new CardSet;
	selectArea=new CardSet;
	selectArea->creatWidget();
	for(int team=0;team!=MAX_TEAM_NUM;++team)
	{
		board[team]=new CardSet;
		hand[team]=new CardSet;
		graveyard[team]=new CardSet;
		deck[team]=new CardSet;
		exiled[team]=new CardSet;
		for(int k=0;k!=MAX_ROW_NUM;++k)
		{
			row[team][k]=new CardSet;
			row[team][k]->creatWidget();
		}

		graveyard[team]->creatWidget();


		cardNum=0;
	}

	hand[ALLY]->creatWidget();

	connect(this,SIGNAL(_playCard(Card*,Row*,int,SI_Object*,SI_String)),this,SLOT(playCard(Card*,Row*,int,SI_Object*,SI_String)));
	connect(this,SIGNAL(_damegeCard(Card*,int,SI_Object*,SI_String)),this,SLOT(damegeCard(Card*,int,SI_Object*,SI_String)));
	connect(this,SIGNAL(_adjustBoostPower(Card*,int,SI_Object*,SI_String)),this,SLOT(adjustBoostPower(Card*,int,SI_Object*,SI_String)));
	connect(this,SIGNAL(_adjustBasePower(Card*,int,SI_Object*,SI_String)),this,SLOT(adjustBasePower(Card*,int,SI_Object*,SI_String)));
	connect(this,SIGNAL(_adjustArmor(Card*,int,SI_Object*,SI_String)),this,SLOT(adjustArmor(Card*,int,SI_Object*,SI_String)));
	connect(this,SIGNAL(_destroyCard(Card*,SI_Object*,SI_String)),this,SLOT(destroyCard(Card*,SI_Object*,SI_String)));
	connect(this,SIGNAL(_exileCard(Card*,SI_Object*,SI_String)),this,SLOT(exileCard(Card*,SI_Object*,SI_String)));
	connect(this,SIGNAL(_drawCard(Card*,SI_Object*,SI_String)),this,SLOT(drawCard(Card*,SI_Object*,SI_String)));
	connect(this,SIGNAL(_drawCard(int,SI_Object*,SI_String)),this,SLOT(drawCard(int,SI_Object*,SI_String)));
	connect(this,SIGNAL(_boostCard(Card*,int,SI_Object*,SI_String)),this,SLOT(boostCard(Card*,int,SI_Object*,SI_String)));
	connect(this,SIGNAL(_strengthenCard(Card*,int,SI_Object*,SI_String)),this,SLOT(strengthenCard(Card*,int,SI_Object*,SI_String)));
	connect(this,SIGNAL(_weakenCard(Card*,int,SI_Object*,SI_String)),this,SLOT(weakenCard(Card*,int,SI_Object*,SI_String)));
	connect(this,SIGNAL(_resetCard(Card*,SI_Object*,SI_String)),this,SLOT(resetCard(Card*,SI_Object*,SI_String)));
	connect(this,SIGNAL(_adjustPlace(Card*,CardSet*,int,SI_Object*,SI_String)),this,SLOT(adjustPlace(Card*,CardSet*,int,SI_Object*,SI_String)));
	connect(this,SIGNAL(_adjustProperty(SI_Object*,SI_String,SI_String,SI_Object*,SI_String)),this,SLOT(adjustProperty(SI_Object*,SI_String,SI_String,SI_Object*,SI_String)));
	connect(this,SIGNAL(_reOrder(CardSet*,SI_Object*,SI_String)),this,SLOT(reOrder(CardSet*,SI_Object*,SI_String)));
	connect(this,SIGNAL(_setWeather(Row*,SI_String,SI_Object*,SI_String)),this,SLOT(setWeather(Row*,SI_String,SI_Object*,SI_String)));
	connect(this,SIGNAL(_removeWeather(Row*,SI_Object*,SI_String)),this,SLOT(removeWeather(Row*,SI_Object*,SI_String)));
	connect(this,SIGNAL(_increaseArmor(Card*,int,SI_Object*,SI_String)),this,SLOT(increaseArmor(Card*,int,SI_Object*,SI_String)));
	connect(this,SIGNAL(_decreaseArmor(Card*,int,SI_Object*,SI_String)),this,SLOT(decreaseArmor(Card*,int,SI_Object*,SI_String)));
	connect(this,SIGNAL(_reviveCard(Card*,Row*,int,SI_Object*,SI_String)),this,SLOT(reviveCard(Card*,Row*,int,SI_Object*,SI_String)));
	connect(this,SIGNAL(_consumeCard(Card*,Card*,SI_Object*,SI_String)),this,SLOT(consumeCard(Card*,Card*,SI_Object*,SI_String)));
	connect(this,SIGNAL(_shieldCard(Card*,SI_Object*,SI_String)),this,SLOT(shieldCard(Card*,SI_Object*,SI_String)));

	connect(this,SIGNAL(adjustBoostPower_(Card*,int,int,SI_Object*,SI_String)),this,SLOT(_changeScore_(Card*,int,int)));
	connect(this,SIGNAL(adjustBasePower_(Card*,int,int,SI_Object*,SI_String)),this,SLOT(_changeScore_(Card*,int,int)));

	connect(this,SIGNAL(playCard_(Card*,Row*,int,SI_Object*,SI_String)),this,SLOT(_playCard_(Card*,Row*,int,SI_Object*,SI_String)));
	connect(this,SIGNAL(damegeCard_(Card*,int,SI_Object*,SI_String)),this,SLOT(_damegeCard_(Card*,int,SI_Object*,SI_String)));
	connect(this,SIGNAL(destroyCard_(Card*,SI_Object*,SI_String)),this,SLOT(_destroyCard_(Card*,SI_Object*,SI_String)));
	connect(this,SIGNAL(exileCard_(Card*,SI_Object*,SI_String)),this,SLOT(_exileCard_(Card*,SI_Object*,SI_String)));
	connect(this,SIGNAL(drawCard_(Card*,SI_Object*,SI_String)),this,SLOT(_drawCard_(Card*,SI_Object*,SI_String)));
	connect(this,SIGNAL(boostCard_(Card*,int,SI_Object*,SI_String)),this,SLOT(_boostCard_(Card*,int,SI_Object*,SI_String)));
	connect(this,SIGNAL(adjustArmor_(Card*,int,int,SI_Object*,SI_String)),this,SLOT(_adjustArmor_(Card*,int,int,SI_Object*,SI_String)));
	connect(this,SIGNAL(adjustBasePower_(Card*,int,int,SI_Object*,SI_String)),this,SLOT(_adjustBasePower_(Card*,int,int,SI_Object*,SI_String)));
	connect(this,SIGNAL(adjustBoostPower_(Card*,int,int,SI_Object*,SI_String)),this,SLOT(_adjustBoostPower_(Card*,int,int,SI_Object*,SI_String)));
	connect(this,SIGNAL(strengthenCard_(Card*,int,SI_Object*,SI_String)),this,SLOT(_strengthenCard_(Card*,int,SI_Object*,SI_String)));
	connect(this,SIGNAL(weakenCard_(Card*,int,SI_Object*,SI_String)),this,SLOT(_weakenCard_(Card*,int,SI_Object*,SI_String)));
	connect(this,SIGNAL(adjustProperty_(SI_Object*,SI_String,SI_String,SI_String,SI_Object*,SI_String)),this,SLOT(_adjustProperty_(SI_Object*,SI_String,SI_String,SI_String,SI_Object*,SI_String)));
	connect(this,SIGNAL(adjustPlace_(Card*,CardSet*,int,CardSet*,int,SI_Object*,SI_String)),this,SLOT(_adjustPlace_(Card*,CardSet*,int,CardSet*,int,SI_Object*,SI_String)));
	connect(this,SIGNAL(consumeCard_(Card*,Card*,SI_Object*,SI_String)),this,SLOT(_consumeCard_(Card*,Card*,SI_Object*,SI_String)));
	connect(this,SIGNAL(shieldCard_(Card*,SI_Object*,SI_String)),this,SLOT(_shieldCard_(Card*,SI_Object*,SI_String)));

	//ui
	connect(this,SIGNAL(_ui_setPlace(Card*,CardSet*,int)),this,SLOT(ui_setPlace(Card*,CardSet*,int)));
	connect(this,SIGNAL(_ui_setCardProperty(Card*,SI_String,SI_String)),this,SLOT(ui_setCardProperty(Card*,SI_String,SI_String)));
	connect(this,SIGNAL(_ui_setWeather(CardSet*,SI_String)),this,SLOT(ui_setWeather(CardSet*,SI_String)));
	//\ui
	for(int team=0;team!=MAX_TEAM_NUM;++team)
	{
		for(int k=0;k!=MAX_ROW_NUM;++k)
		{
			row[team][k]->setProperty("name","row_"+QString::number(team)+"_"+QString::number(k));
			row[team][k]->setProperty("team",SI_String::number(team));
		}
		hand[team]->setProperty("name","hand_"+QString::number(team));
		hand[team]->setProperty("team",SI_String::number(team));
		graveyard[team]->setProperty("name","graveyard_"+QString::number(team));
		graveyard[team]->setProperty("team",SI_String::number(team));
		deck[team]->setProperty("name","deck_"+QString::number(team));
		deck[team]->setProperty("team",SI_String::number(team));
		exiled[team]->setProperty("name","exiled_"+QString::number(team));
		exiled[team]->setProperty("team",SI_String::number(team));
		board[team]->setProperty("name","board_"+QString::number(team));
		board[team]->setProperty("team",SI_String::number(team));
	}
}
