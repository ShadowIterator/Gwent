#include "harpy_egg.h"
#include "game.h"
#include"card.h"
#include"cardset.h"
#include"field.h"
#include"global.h"
#include"si_object.h"
#include"userinteraction.h"
#include"weather.h"


Harpy_Egg regist_Harpy_Egg;

Harpy_Egg::Harpy_Egg(QObject* parent):Card(parent)
{
	qRegisterMetaType<Harpy_Egg>("Harpy_Egg");
}

Harpy_Egg::Harpy_Egg(const Harpy_Egg& tcard):Card(tcard)
{

}

void Harpy_Egg::_destroyed_(SI_Object*,SI_String)
{
	int team=getProperty("team").toInt();
	Card* pHarpy=Card::factory(game,"Harpy_Hatchling");
	pHarpy->setup(team,game);
	game->field->addtoAllCard(pHarpy);
	int rowNum=rand()%MAX_ROW_NUM;
	Row* tarRow=game->field->row[team][rowNum];
	int order=rand()%(tarRow->cardSet.size()+1);

	emit game->field->_playCard(pHarpy,tarRow,order,this,noinfo);
}

void Harpy_Egg::_consumed_(Card* psrcCard,SI_Object* psrc,SI_String info)
{
	const int boostPower=5;
	emit game->field->_boostCard(psrcCard,boostPower,this,info);
}
