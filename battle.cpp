#include"battle.h"


inline int Min(int a,int b)
{
	return a<b?a:b;
}

inline int Max(int a,int b)
{
	return a>b?a:b;
}


SI_Object::SI_Object(QObject* parent=0):QObject(parent)
{
	properties.clear();
}


SI_String SI_Object::getProperty(const SI_String& propertyName) const
{
	map<SI_String,SI_String>::const_iterator it=properties.find(propertyName);
	if(it==properties.end()) return "NoResult";
	return it->second;
}

map<SI_String,SI_String>::iterator SI_Object::getBegin()
{
	map<SI_String,SI_String>::iterator it=properties.begin();
	return it;
}

map<SI_String,SI_String>::iterator SI_Object::getEnd()
{
	return properties.end();
}

void SI_Object::setProperty(const SI_String& propertyName,const SI_String& propertyVal)
{
	properties[propertyName]=propertyVal;
}

CardSet::CardSet(QObject *parent=0):SI_Object(parent)
{
	cardSet.clear();
}

void CardSet::reOrder()
{
	vector<Card*> temp;
	temp.assign(cardSet.begin(),cardSet.end());
	std::random_shuffle(temp.begin(),temp.end());
	cardSet.assign(temp.begin(),temp.end());
/*
	list<int> rank(cardSet.size());
	int i=0;
	for()
	std::random_shuffle(cardSet.begin(),cardSet.end());
*/
}

/*
void CardSet::append(const Card& tcard)
{
	cardSet.push_back(&tcard);
}
*/

void CardSet::append(Card* pcard)
{
	cardSet.push_back(pcard);
}

void CardSet::append(Card& tcard)
{
	append(&tcard);
}

void CardSet::erase(Card* pcard)
{
	list<Card*>::iterator it=std::find(cardSet.begin(),cardSet.end(),pcard);//cardSet.find(pcard);
	if(it!=cardSet.end())
	{
		cardSet.erase(it);
	}
}

void CardSet::erase(Card& tcard)
{
	erase(&tcard);
}

void CardSet::ins(Card* pcard,int order)
{
//
	if(order<0) cardSet.push_back(pcard);
	else if(!order) cardSet.push_front(pcard);
	else cardSet.insert(_getIterator(order),pcard);
}

list<Card*>::iterator CardSet::_getIterator(int index)
{
	if(index<0) return cardSet.end();
	list<Card*>::iterator it=cardSet.begin();
	for(;index&&(it!=cardSet.end());--index) ++it;
	return it;
}

User::User(QObject* parent=0):SI_Object(parent)
{

}

CardSet* Card::getPlace() const
{
	return place;
}

void Card::__readInfo(ifstream &in)
{
	SI_String propertyName;
	SI_String propertyVal;

	in>>propertyName;
	while(propertyName!="}")
	{
		in>>propertyVal;
		properties[propertyName]=propertyVal;
		properties["base_"+propertyName]=propertyVal;
	}
}

int Card::getOrder() const
{
	int rtn=0;
	for(list<Card*>::iterator it=place->cardSet.begin();it!=place->cardSet.end();++it,++rtn)
		if((*it)==this) return rtn;
	return -1;
}

void Card::setPlace(CardSet *pcardSet, int order)
{
	place->erase(this);
	place=pcardSet;
	if(order==-1) place->append(this);
	else place->ins(this,order);
}

/*
CardSet* Field::__getptr_place(SI_String place)
{
	int teamNum=place[0]-'0';
	int rowNum=place[place.size()]-'0';
	SI_String subPlace=place.section('_',0,0);
	if(subPlace=="Row") return row[teamNum][rowNum];
	if(subPlace=="Hand") return hand[teamNum];
	if(subPlace=="Deck") return deck[teamNum];
	if(subPlace=="Graveyard") return graveyard[teamNum];
	if(subplace=="Exiled") return exiled[teamNum];
	return NULL;
}
*/

SI_String Field::__getstr_place(CardSet* place)
{
	int teamNum;
	int rowNum;
	SI_String rtn;
	rtn.clear();
	for(teamNum=0;teamNum<MAX_TEAM_NUM;++teamNum)
		for(rowNum=0;rowNum<MAX_ROW_NUM;++rowNum)
			if(&row[teamNum][rowNum]==place)
				return (teamNum+'0')+"_Row_"+(rowNum+'0');

	for(teamNum=0;teamNum<MAX_TEAM_NUM;++teamNum)
		if(&hand[teamNum]==place)
			return (teamNum+'0')+"_Hand_"+(rowNum+'0');

	for(teamNum=0;teamNum<MAX_TEAM_NUM;++teamNum)
		if(&deck[teamNum]==place)
			return (teamNum+'0')+"_Deck_"+(rowNum+'0');

	for(teamNum=0;teamNum<MAX_TEAM_NUM;++teamNum)
		if(&graveyard[teamNum]==place)
			return (teamNum+'0')+"_Graveyard_"+(rowNum+'0');

	for(teamNum=0;teamNum<MAX_TEAM_NUM;++teamNum)
		if(&exiled[teamNum]==place)
			return (teamNum+'0')+"_Exiled_"+(rowNum+'0');

	return "0_Nowhere_0";
}

void Field::adjustPlace(Card *pcard,CardSet* pcardSet,int order,SI_Object* psrc,SI_String info) //tar tarcardSet order (src (info
{
	CardSet* srcPlace=pcard->place;
	int srcOrder=pcard->getOrder();
	pcard->setPlace(pcardSet,order);
	emit adjustPlace_(pcard,srcPlace,srcOrder,pcardSet,order,psrc,info);
}

void Field::playCard(Card* pcard,Row* prow,int order,SI_Object* psrc,SI_String info) //tar tar_row order (info
{
//	SI_String srcPlace=pcard->getProperty("place");
//	SI_String tarPlace=__getstr_place(prow);
	emit _adjustPlace(pcard,prow,order,psrc,info);
	emit playCard_(pcard,prow,order,psrc,info);
}

void Field::exileCard(Card* pcard,SI_Object* src,SI_String info) //tar (src (info
{
	emit _adjustPlace(pcard,&exiled[pcard->getProperty("team").toInt()],-1,src,info);
	emit exileCard_(pcard,src,info);
}

void Field::damegeCard(Card* ptarCard,int val,SI_Object* psrc,SI_String info) //tar val (src (info
{
	int srcArmor=ptarCard->getProperty("armor").toInt();
	int srcBoostPower=ptarCard->getProperty("boostPower").toInt();
	int srcBasePower=ptarCard->getProperty("basePower").toInt();

	int tarArmor=srcArmor;
	int tarBoostPower=srcBoostPower;
	int tarBasePower=srcBasePower;

	tarArmor=Max(0,srcArmor-val);
	val=Max(val-srcArmor,0);

	tarBoostPower=Max(0,srcBoostPower-val);
	val=Max(val-srcBoostPower,0);

	tarBasePower=Max(0,srcBasePower-val);
	val=Max(val-srcBasePower,0);

	if(tarArmor!=srcBasePower)
		emit _adjustArmor(ptarCard,tarArmor,psrc,info);
	if(tarBoostPower!=srcBoostPower)
		emit _adjustBoostPower(ptarCard,tarBoostPower,psrc,info);
	if(tarBasePower!=srcBasePower)
		emit _adjustBasePower(ptarCard,tarBasePower,psrc,info);
}

void Field::destroyCard(Card* ptarCard,SI_Object* psrc,SI_String info) //tar (src (info
{
	emit _adjustPlace(ptarCard,&graveyard[ptarCard->getProperty("team").toInt()],-1,psrc,info);
	emit destroyCard_(ptarCard,psrc,info);
}

void Field::drawCard(Card *pcard, SI_Object *psrc, SI_String info)
{
	emit _adjustPlace(pcard,&hand[pcard->getProperty("team").toInt()],-1,psrc,info);
	emit drawCard_(pcard,psrc,info);
}

void Field::drawCard(int team,SI_Object* psrc,SI_String info)
{
	if(deck[team].cardSet.size()==0)
	{
		// todo : handle no card condition
	}
	drawCard(*(deck[team].cardSet.begin()),psrc,info);
}

void Field::boostCard(Card *pcard, int val, SI_Object *psrc, SI_String info)
{
	emit _adjustBoostPower(pcard,val,psrc,info);
	emit boostCard_(pcard,val,psrc,info);
}

void Field::strengthenCard(Card *pcard, int val, SI_Object *psrc, SI_String info)
{
	emit _adjustBasePower(pcard,val,psrc,info);
	emit strengthenCard_(pcard,val,psrc,info);
}

void Field::weakenCard(Card *pcard, int val, SI_Object *psrc, SI_String info)
{
	emit _adjustBasePower(pcard,-val,psrc,info);
	emit weakenCard_(pcard,val,psrc,info);
}

void Field::resetCard(Card *pcard,SI_Object* psrc,SI_String info)
{
	SI_String propertyName;
	SI_String propertyName_ori;
	SI_String propertyVal_ori;
	for(map<SI_String,SI_String>::iterator it=pcard->getBegin();it!=pcard->getEnd();++it)
//	for(map<SI_String,SI_String>::iterator it=pcard->properties.begin();it!=pcard->properties.end();++it)
	{
		propertyName=it->first;
		propertyVal_ori=pcard->getProperty("ori_"+propertyName);
		if(propertyVal_ori!="NoResult")
		{
			emit _adjustProperty(pcard,propertyName,propertyVal_ori,psrc,info);
		}
		//propertyName_ori="ori_"+propertyName;
		//map<SI_String,SI_String>::iterator base_it;
		//base_it=
	}
	emit resetCard_(pcard,psrc,info);
}

void Field::adjustProperty(SI_Object *pcard, SI_String propertyName, SI_String propertyVal, SI_Object *psrc, SI_String info)
{
	SI_String propertyVal_ori=pcard->getProperty(propertyName);
	pcard->setProperty(propertyName,propertyVal);
	emit adjustProperty_(pcard,propertyName,propertyVal_ori,propertyVal,psrc,info);
}

/*
void Field::exileCard(Card*,SI_Object*,SI_String); //tar (src (info
void Field::disCard(Card*,SI_Object*,SI_String); //tar (src (info
void Field::drawCard(Card*,SI_Object*,SI_String); //tar (src (info
void Field::drawCard(int,SI_Object*,SI_String); //player (src (info
void Field::boostCard(Card*,int,SI_Object*,SI_String); //tar val (src (info
void Field::increaseArmor(Card*,int,SI_Object*,SI_String); //tar val (src (info
void Field::decreaseArmor(Card*,SI_Object*,SI_String); //tar (src (info
void Field::strengthenCard(Card*,int,SI_Object*,SI_String); //tar val (src (info
void Field::weakenCard(Card*,int,SI_Object*,SI_String); //tar val (src (info
void Field::resetCard(Card*,SI_Object*,SI_String); //tar (src (info

void Field::infield(Card*,SI_Object*,SI_String); //tar (src (info
void Field::exfield(Card*,SI_Object*,SI_String); //tar (src (info
void Field::ingraveyardCard(Card*,SI_Object*,SI_String); //tar (src (info
void Field::exgraveyardCard(Card*,SI_Object*,SI_String); //tar (src (info
void Field::inhandCard(Card*,SI_Object*,SI_String); //tar (src (info

void Field::propertyChanged(SI_Object*,SI_String,SI_String,SI_String); //tar pro_src pro_tar (info
void adjustPlace(Card* ptar,CardSet* ptarPlace,int tarOrder,SI_Object* psrc,SI_String info) //tar place_tar order (src (info
{
	CardSet* psrcPlace=ptar->getPlace();
	int srcOrder;
	if(tarOrder==-1)
	{
		srcOrder=-1;
	}
	else
	{
		srcOrder=ptar->getOrder();
	}
	ptar->setPlace(ptarPlace,tarOrder);

	emit adjustPlace_(ptar,psrcPlace,srcOrder,ptarPlace,tarOrder,psrc,info);
}

//	void _placeChanged_(Card*,SI_String,SI_String,SI_Object*,SI_String); //tar place_src place_tar (src (info


void _playCard_(Card*,Row*,int,SI_String); //tar tar_row order (info
void _damegeCard_(Card*,int,SI_Object*,SI_String); //tar val (src (info
void _destroyCard_(Card*,SI_Object*,SI_String); //tar (src (info
void _exileCard_(Card*,SI_Object*,SI_String); //tar (src (info
void _disCard_(Card*,SI_Object*,SI_String); //tar (src (info
void _drawCard_(Card*,SI_Object*,SI_String); //tar (src (info
void _drawCard_(int,SI_Object*,SI_String); //player (src (info
void _boostCard_(Card*,int,SI_Object*,SI_String); //tar val (src (info
void _increaseArmor_(Card*,int,SI_Object*,SI_String); //tar val (src (info
void _decreaseArmor_(Card*,SI_Object*,SI_String); //tar (src (info
void _strengthenCard_(Card*,int,SI_Object*,SI_String); //tar val (src (info
void _weakenCard_(Card*,int,SI_Object*,SI_String); //tar val (src (info
void _resetCard_(Card*,SI_Object*,SI_String); //tar (src (info

void _infield_(Card*,SI_Object*,SI_String); //tar (src (info
void _exfield_(Card*,SI_Object*,SI_String); //tar (src (info
void _ingraveyardCard_(Card*,SI_Object*,SI_String); //tar (src (info
void _exgraveyardCard_(Card*,SI_Object*,SI_String); //tar (src (info
void _inhandCard_(Card*,SI_Object*,SI_String); //tar (src (info

void _adjustPlace_(Card*,CardSet*,int,CardSet*,int,SI_Object*,SI_String); //tar place_src order_src place_tar order_tar (src (info
*/


void FlowControl::__test()
{

}
