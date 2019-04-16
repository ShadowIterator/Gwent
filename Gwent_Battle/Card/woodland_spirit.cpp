#include "woodland_spirit.h"
#include "game.h"
#include"card.h"
#include"cardset.h"
#include"field.h"
#include"global.h"
#include"si_object.h"
#include"userinteraction.h"
#include"weather.h"


Woodland_Spirit regist_Woodland_Spirit;

Woodland_Spirit::Woodland_Spirit(QObject* parent):Card(parent)
{
	qRegisterMetaType<Woodland_Spirit>("Woodland_Spirit");
}

Woodland_Spirit::Woodland_Spirit(const Woodland_Spirit& tcard):Card(tcard)
{

}

void Woodland_Spirit::_played_(Row *prow, int order, SI_Object *psrc, SI_String info)
{
	int team=getProperty("team").toInt();
	int rowNum=prow->getProperty("name").section("_",2,2).toInt();
	const int spawnNum=3;
	Card* pRabidWolf;
	int tarRowNum=-1;
	int tarTeamNum=team;

	for(int k=0;k!=spawnNum;++k)
	{
		pRabidWolf=Card::factory(game,"Rabid_Wolf");
		pRabidWolf->setup(team,game);

		pRabidWolf->getPosition(tarTeamNum,tarRowNum);

		game->field->addtoAllCard(pRabidWolf);
		emit game->field->_playCard(pRabidWolf,game->field->row[tarTeamNum][tarRowNum],-1,this,noinfo);
	}

	emit game->field->_setWeather(game->field->row[team^1][rowNum],"W_Impenetrable_Frog",this,noinfo);
}
