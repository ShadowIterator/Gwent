#include "torrential_rain.h"
#include "game.h"
#include "cardset.h"
#include "field.h"
#include "userinteraction.h"
Torrential_Rain regist_Torrential_Rain;

Torrential_Rain::Torrential_Rain(QObject* parent):Card(parent)
{
	qRegisterMetaType<Torrential_Rain>("Torrential_Rain");
}

Torrential_Rain::Torrential_Rain(const Torrential_Rain& tcard):Card(tcard)
{

}

void Torrential_Rain::_played_(Row *prow, int order, SI_Object *psrc, SI_String info)
{
	list<CardSet*> lcardSet;
	lcardSet.clear();
	int team=getProperty("team").toInt();
	for(int k=0;k!=MAX_ROUND_NUM;++k)
		lcardSet.push_back(game->field->row[team^1][k]);
	CardSet* pcardSet=game->user[team]->__inputCardSet(&lcardSet);
	emit game->field->_setWeather(pcardSet,"W_"+getProperty("name"),this,noinfo);
}
