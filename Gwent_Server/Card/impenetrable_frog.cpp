#include "impenetrable_frog.h"
#include "game.h"
#include"card.h"
#include"cardset.h"
#include"field.h"
#include"global.h"
#include"si_object.h"
#include"userinteraction.h"
#include"weather.h"


Impenetrable_Frog regist_Impenetrable_Frog;

Impenetrable_Frog::Impenetrable_Frog(QObject* parent):Card(parent)
{
	qRegisterMetaType<Impenetrable_Frog>("Impenetrable_Frog");
}

Impenetrable_Frog::Impenetrable_Frog(const Impenetrable_Frog& tcard):Card(tcard)
{

}


void Impenetrable_Frog::_played_(Row *prow, int order, SI_Object *psrc, SI_String info)
{
	list<CardSet*> lcardSet;
	lcardSet.clear();
	int team=getProperty("team").toInt();
	for(int k=0;k!=MAX_ROUND_NUM;++k)
		lcardSet.push_back(game->field->row[team^1][k]);
	CardSet* pcardSet=game->user[team]->__inputCardSet(&lcardSet);
	emit game->field->_setWeather(pcardSet,"W_"+getProperty("name"),this,noinfo);

}
