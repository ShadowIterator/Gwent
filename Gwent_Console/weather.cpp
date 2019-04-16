#include"weather.h"
#include"game.h"
#include"cardset.h"

void Weather::_startTurn_(int turnNum,int curTeam)
{

}

Weather::Weather(QObject* parent):SI_Object(parent),id(QMetaType::UnknownType),row(NULL),game(NULL),addDamege(0)
{
}

void Weather::__doConnect()
{
	connect(game,SIGNAL(startTurn_(int,int)),this,SLOT(_startTurn_(int,int)));
}

Weather::Weather(const Weather &tweather):SI_Object(tweather)
{
	if(this!=&tweather)
	{
		row=tweather.row;
		game=tweather.game;
	}
}

void Weather::setToRow(CardSet *trow)
{
	if(trow==NULL) return;
	if(trow->weather!=NULL&&trow->weather!=this) trow->weather->removeFromRow();
	trow->weather=this;
	row=trow;
}

void Weather::removeFromRow()
{
	row->weather=NULL;
	row=NULL;
	game=NULL;
	QMetaType::destroy(id,this);
}

Weather::~Weather()
{

}

void Weather::__init()
{
	row=NULL;
	game=NULL;
	id=QMetaType::UnknownType;
	properties.clear();
}

Weather* Weather::factory(Game *pgame, const SI_String &weatherName)
{
	Weather* pweather;
	int id=QMetaType::type(weatherName.toLatin1());
	void *where=malloc(sizeof(Weather));
	if(id!=QMetaType::UnknownType)
	{
		void* tempp=QMetaType::construct(id,where,NULL);
		pweather=static_cast<Weather*>(tempp);
		pweather->__init();
		pweather->id=id;
		pweather->game=pgame;
		pweather->setProperty("name",weatherName);
		pweather->__doConnect();
	}
	return pweather;
}
