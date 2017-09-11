#include "lacerate.h"
#include "game.h"
#include"card.h"
#include"cardset.h"
#include"field.h"
#include"global.h"
#include"si_object.h"
#include"userinteraction.h"
#include"weather.h"


Lacerate regist_Lacerate;

Lacerate::Lacerate(QObject* parent):Card(parent)
{
	qRegisterMetaType<Lacerate>("Lacerate");
}

Lacerate::Lacerate(const Lacerate& tcard):Card(tcard)
{

}

void Lacerate::_played_(Row *prow, int order, SI_Object *psrc, SI_String info)
{
	list<CardSet*> lcardSet;
	lcardSet.clear();
	int team=getProperty("team").toInt();
	for(int i=0;i!=MAX_TEAM_NUM;++i)
		for(int k=0;k!=MAX_ROUND_NUM;++k)
			lcardSet.push_back(game->field->row[i][k]);
	CardSet cardSet=*(game->user[team]->__inputCardSet(&lcardSet));

//	qDebug()<<pcardSet->cardSet.size();
	for(list<Card*>::iterator it=cardSet.cardSet.begin();it!=cardSet.cardSet.end();++it)
		emit game->field->_damegeCard(*it,3,this,info);

}
