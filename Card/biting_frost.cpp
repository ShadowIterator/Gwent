#include "biting_frost.h"
#include "game.h"
#include"card.h"
#include"cardset.h"
#include"field.h"
#include"global.h"
#include"si_object.h"
#include"userinteraction.h"
#include"weather.h"


Biting_Frost regist_Biting_Frost;

Biting_Frost::Biting_Frost(QObject* parent):Card(parent)
{
	qRegisterMetaType<Biting_Frost>("Biting_Frost");
}

Biting_Frost::Biting_Frost(const Biting_Frost& tcard):Card(tcard)
{

}

void Biting_Frost::_played_(Row *prow, int order, SI_Object *psrc, SI_String info)
{
	list<CardSet*> lcardSet;
	lcardSet.clear();
	int team=getProperty("team").toInt();
	for(int k=0;k!=MAX_ROUND_NUM;++k)
		lcardSet.push_back(game->field->row[team^1][k]);
	CardSet* pcardSet=game->user[team]->__inputCardSet(&lcardSet);
	emit game->field->_setWeather(pcardSet,"W_"+getProperty("name"),this,noinfo);

}
