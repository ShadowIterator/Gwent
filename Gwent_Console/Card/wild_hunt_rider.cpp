#include "wild_hunt_rider.h"
#include "game.h"
#include"card.h"
#include"cardset.h"
#include"field.h"
#include"global.h"
#include"si_object.h"
#include"userinteraction.h"
#include"weather.h"


Wild_Hunt_Rider regist_Wild_Hunt_Rider;

Wild_Hunt_Rider::Wild_Hunt_Rider(QObject* parent):Card(parent)
{
	qRegisterMetaType<Wild_Hunt_Rider>("Wild_Hunt_Rider");
}

Wild_Hunt_Rider::Wild_Hunt_Rider(const Wild_Hunt_Rider& tcard):Card(tcard)
{

}

void Wild_Hunt_Rider::_played_(Row *prow, int order, SI_Object *psrc, SI_String info)
{
	int team=getProperty("team").toInt();
	int rowNum=prow->getProperty("name").section("_",2,2).toInt();
	Row* oppoRow=game->field->row[team^1][rowNum];
	if(oppoRow->weather==NULL) return ;
	if(oppoRow->weather->getProperty("name")!="W_Biting_Frost") return ;

	++(oppoRow->weather->addDamege);
}

void Wild_Hunt_Rider::_destroyed_(SI_Object *psrc, SI_String info)
{
	int team=getProperty("team").toInt();
	int rowNum=place->getProperty("name").section("_",2,2).toInt();
	Row* oppoRow=game->field->row[team^1][rowNum];
	if(oppoRow->weather==NULL) return ;
	if(oppoRow->weather->getProperty("name")!="W_Biting_Frost") return ;

	--(oppoRow->weather->addDamege);
}

void Wild_Hunt_Rider::_setWeather_(Row *prow, Weather *pweather, SI_Object *psrc, SI_String info)
{
	if(pweather->getProperty("name")!="W_Biting_Frost") return ;
	int wteam=prow->getProperty("team").toInt();
	int wrowNum=prow->getProperty("name").section("_",2,2).toInt();
	Row* cardRow=game->field->row[wteam^1][wrowNum];
	if(cardRow!=place) return ;
	++(pweather->addDamege);
}

void Wild_Hunt_Rider::__doConnect()
{
	connect(game->field,SIGNAL(setWeather_(Row*,Weather*,SI_Object*,SI_String)),this,SLOT(_setWeather_(Row*,Weather*,SI_Object*,SI_String)));
}
