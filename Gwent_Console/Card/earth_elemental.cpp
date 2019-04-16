#include "earth_elemental.h"
#include "game.h"
#include"card.h"
#include"cardset.h"
#include"field.h"
#include"global.h"
#include"si_object.h"
#include"userinteraction.h"
#include"weather.h"


Earth_Elemental regist_Earth_Elemental;

Earth_Elemental::Earth_Elemental(QObject* parent):Card(parent)
{
	qRegisterMetaType<Earth_Elemental>("Earth_Elemental");
}

Earth_Elemental::Earth_Elemental(const Earth_Elemental& tcard):Card(tcard)
{

}

void Earth_Elemental::_played_(Row *prow, int order, SI_Object *psrc, SI_String info)
{
	 emit game->field->_shieldCard(this,this,noinfo);
}

void Earth_Elemental::_destroyed_(SI_Object *psrc, SI_String info)
{
	int team=getProperty("team").toInt();
	int rowNum=place->getProperty("name").section("_",2,2).toInt();
	const int spawnNum=2;
	Card* pLessEarthElemental;

	for(int k=0;k!=spawnNum;++k)
	{
		pLessEarthElemental=Card::factory(game,"Lesser_Earth_Elemental");
		pLessEarthElemental->setup(team,game);
		game->field->addtoAllCard(pLessEarthElemental);
		emit game->field->_playCard(pLessEarthElemental,game->field->row[team][rowNum],-1,this,noinfo);
	}
}
