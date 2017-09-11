#include"card.h"
#include"cardset.h"
#include"game.h"

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
	SI_String cardPath,temp;
	//cardName=__tofileName(cardName);
	cardPath=game->cardDir;
	cardPath=cardPath+"\\"+__tofileName(cardName)+".txt";
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

Card* Card::factory(SI_String cardName)
{
	Card* pcard;
//	int id=QMetaType::type(__toclassName(cardName).toLatin1());
	int id=QMetaType::type(cardName.toLatin1());
	void *where=malloc(sizeof(Card));
	if(id!=QMetaType::UnknownType)
	{
	//	pcard=static_cast<Card*>(QMetaType::construct(id),where,NULL);
	//	void* tempp=QMetaType::construct(id,tempcard,NULL);
		void* tempp=QMetaType::construct(id,where,NULL);
		pcard=static_cast<Card*>(tempp);
		pcard->__init();
		pcard->id=id;
		pcard->setProperty("name",cardName);
	}
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

//	in>>propertyName;
//	cin>>propertyName;
//	in>>temp;
//	propertyName=QString::fromStdString(temp);
	__inputQString(in,propertyName);
	while(propertyName!="}")
	{
		//in>>propertyVal;
		//in>>temp
		__inputQString(in,propertyVal);
		//properties[propertyName]=propertyVal;
		//properties["ori_"+propertyName]=propertyVal;

		//properties.insert(propertyName,propertyVal);
		//properties.insert("ori_"+propertyName,propertyVal);
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

void Card::__init()
{
	place=NULL;
	game=NULL;
	id=QMetaType::UnknownType;
}

void Card::setup(int team, Game *pgame)
{
	game=pgame;
	setProperty("team",SI_String::number(team));
}

Card::Card(QObject* parent):SI_Object(parent),game(NULL),place(NULL),id(QMetaType::UnknownType)
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
//	connect(this,SIGNAL(adjustProperty_(SI_String,SI_String,SI_String,SI_Object*,SI_String)),this,SLOT(_adjustProperty_(SI_String,SI_String,SI_String,SI_Object*,SI_String)));
	connect(this,SIGNAL(adjustPlace_(CardSet*,int,CardSet*,int,SI_Object*,SI_String)),this,SLOT(_adjustPlace_(CardSet*,int,CardSet*,int,SI_Object*,SI_String)));

	__init();
}

Card::Card(const Card& tcard):SI_Object(tcard)
{
	if(this!=&tcard)
	{
		place=tcard.place;
		game=tcard.game;
		id=tcard.id;
	}
}
