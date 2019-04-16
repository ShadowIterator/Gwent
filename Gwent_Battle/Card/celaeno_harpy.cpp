#include "celaeno_harpy.h"
#include "game.h"
#include"card.h"
#include"cardset.h"
#include"field.h"
#include"global.h"
#include"si_object.h"
#include"userinteraction.h"
#include"weather.h"


Celaeno_Harpy regist_Celaeno_Harpy;

Celaeno_Harpy::Celaeno_Harpy(QObject* parent):Card(parent)
{
	qRegisterMetaType<Celaeno_Harpy>("Celaeno_Harpy");
}

Celaeno_Harpy::Celaeno_Harpy(const Celaeno_Harpy& tcard):Card(tcard)
{

}

void Celaeno_Harpy::_played_(Row *prow, int order, SI_Object *psrc, SI_String info)
{
	const int effectTime=2;
	Card* pHarpyEgg;
	int team=getProperty("team").toInt();
	for(int i=0;i!=effectTime;++i)
	{
		pHarpyEgg=Card::factory(game,"Harpy_Egg");
		pHarpyEgg->setup(team,game);
		game->field->addtoAllCard(pHarpyEgg);

		emit game->field->_playCard(pHarpyEgg,prow,order,psrc,info);
	}
}
