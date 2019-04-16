#include"card.h"
#include"cardset.h"
#include"game.h"
#include"cardwidget.h"

SI_String Card::cardDir=":/card/src/card/";

CardSet* Card::getPlace() const
{
	return place;
}

void Card::setGame(Game *pgame)
{
	game=pgame;
}

bool Card::__initInfo()
{
	SI_String cardName=getProperty("name");
	QFile fcard;
	QTextStream cardin;
	SI_String temp,cardPath;

	cardPath=cardDir;
	cardPath=cardPath+__tofileName(cardName)+".txt";
	fcard.setFileName(cardPath);
	if(!fcard.open(QIODevice::ReadOnly))
	{
		qDebug()<<"open card file "<<cardName<<" failed"<<endl;
		return false;
	}
	cardin.setDevice(&fcard);
	__inputQString(cardin,temp);
	__readInfo(cardin);
	fcard.close();
	return true;
}

Card* Card::factory(Game* pgame,SI_String cardName)
{
	Card* pcard;
	pcard=new Card;
	pcard->__init();
	pcard->game=pgame;
	pcard->setProperty("name",cardName);
	pcard->__doConnect();
	pcard->__initInfo();
	pcard->pwidget=new CardWidget(pcard);
	return pcard;
}

void Card::destroy()
{
	QMetaType::destroy(id,this);
}

void Card::__readInfo(QTextStream &in)
{
	string temp;
	SI_String propertyName;
	SI_String propertyVal;

	__inputQString(in,propertyName);
	while(propertyName!="}")
	{
		__inputQString(in,propertyVal);
		setProperty(propertyName,propertyVal);
		setProperty("ori_"+propertyName,propertyVal);
		__inputQString(in,propertyName);
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
	if(place!=NULL)
		place->erase(this);
	place=pcardSet;
	place->ins(this,order);
}

void Card::getPosition(int &teamNum, int &rowNum)
{
	teamNum=getProperty("team").toInt();
	int position=getProperty("position").toInt();
	for(int i=0;i!=MAX_ROW_NUM;++i)
		if((position>>i)&1)
		{
			rowNum=i;
			return ;
		}
	position>>=MAX_ROW_NUM;
	teamNum^=1;
	for(int i=0;i!=MAX_ROW_NUM;++i)
		if((position>>i)&1)
		{
			rowNum=i;
			return ;
		}

}

void Card::_played_(Row *row, int order, SI_Object* psrc, SI_String info)
{

}

void Card::_dameged_(int val, SI_Object *psrc, SI_String info)
{

}

void Card::_destroyed_(SI_Object *psrc, SI_String info)
{

}

void Card::_exiled_(SI_Object *psrc, SI_String info)
{

}

void Card::_drawed_(SI_Object *psrc, SI_String info)
{

}

void Card::_boosted_(int val, SI_Object *psrc, SI_String info)
{

}

void Card::_adjustArmor_(int oriVal, int tarVal, SI_Object *psrc, SI_String info)
{

}

void Card::_adjustBasePower_(int oriVal, int tarVal, SI_Object *psrc, SI_String info)
{

}

void Card::_adjustBoostPower_(int oriVal, int tarVal, SI_Object *psrc, SI_String info)
{

}

void Card::_strengthened_(int val, SI_Object *psrc, SI_String info)
{

}

void Card::_weakened_(int val, SI_Object *psrc, SI_String info)
{

}

void Card::_reseted_(SI_Object *psrc, SI_String info)
{

}

void Card::_adjustPlace_(CardSet *oriCardSet, int oriOrder, CardSet *tarCardSet, int tarOrder, SI_Object *psrc, SI_String info)
{

}

void Card::_consumed_(Card*,SI_Object *psrc, SI_String info)
{

}

void Card::_consume_(Card* ptar,SI_Object* psrc,SI_String info)
{

}

void Card::__doConnect()
{

}

void Card::__init()
{
	place=NULL;
	game=NULL;
	id=QMetaType::UnknownType;
	pwidget=NULL;
}

void Card::setup(int team, Game *pgame)
{
	game=pgame;
	setProperty("team",SI_String::number(team));
}

Card::Card(QObject* parent):SI_Object(parent),game(NULL),place(NULL),id(QMetaType::UnknownType),pwidget(NULL)
{

	connect(this,SIGNAL(played_(Row*,int,SI_Object*,SI_String)),this,SLOT(_played_(Row*,int,SI_Object*,SI_String)));
	connect(this,SIGNAL(dameged_(int,SI_Object*,SI_String)),this,SLOT(_dameged_(int,SI_Object*,SI_String)));
	connect(this,SIGNAL(destroyed_(SI_Object*,SI_String)),this,SLOT(_destroyed_(SI_Object*,SI_String)));
	connect(this,SIGNAL(exiled_(SI_Object*,SI_String)),this,SLOT(_exiled_(SI_Object*,SI_String)));
	connect(this,SIGNAL(drawed_(SI_Object*,SI_String)),this,SLOT(_drawed_(SI_Object*,SI_String)));
	connect(this,SIGNAL(boosted_(int,SI_Object*,SI_String)),this,SLOT(_boosted_(int,SI_Object*,SI_String)));
	connect(this,SIGNAL(adjustArmor_(int,int,SI_Object*,SI_String)),this,SLOT(_adjustArmor_(int,int,SI_Object*,SI_String)));
	connect(this,SIGNAL(adjustBasePower_(int,int,SI_Object*,SI_String)),this,SLOT(_adjustBasePower_(int,int,SI_Object*,SI_String)));
	connect(this,SIGNAL(adjustBoostPower_(int,int,SI_Object*,SI_String)),this,SLOT(_adjustBoostPower_(int,int,SI_Object*,SI_String)));
	connect(this,SIGNAL(strengthened_(int,SI_Object*,SI_String)),this,SLOT(_strengthened_(int,SI_Object*,SI_String)));
	connect(this,SIGNAL(weakened_(int,SI_Object*,SI_String)),this,SLOT(_weakened_(int,SI_Object*,SI_String)));
	connect(this,SIGNAL(reseted_(SI_Object*,SI_String)),this,SLOT(_reseted_(SI_Object*,SI_String)));
	connect(this,SIGNAL(adjustPlace_(CardSet*,int,CardSet*,int,SI_Object*,SI_String)),this,SLOT(_adjustPlace_(CardSet*,int,CardSet*,int,SI_Object*,SI_String)));
	connect(this,SIGNAL(consumed_(Card*,SI_Object*,SI_String)),this,SLOT(_consumed_(Card*,SI_Object*,SI_String)));
	connect(this,SIGNAL(consume_(Card*,SI_Object*,SI_String)),this,SLOT(_consume_(Card*,SI_Object*,SI_String)));
	__init();
}


Card::Card(const Card& tcard):SI_Object(tcard)
{
	if(this!=&tcard)
	{
		place=tcard.place;
		game=tcard.game;
		id=tcard.id;
		pwidget=tcard.pwidget;
	}

}

