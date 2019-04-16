#include "harpy.h"
#include "game.h"
#include"card.h"
#include"cardset.h"
#include"field.h"
#include"global.h"
#include"si_object.h"
#include"userinteraction.h"
#include"weather.h"


Harpy regist_Harpy;

Harpy::Harpy(QObject* parent):Card(parent)
{
	qRegisterMetaType<Harpy>("Harpy");
}

Harpy::Harpy(const Harpy& tcard):Card(tcard)
{

}

void Harpy::_played_(Row *prow, int order, SI_Object *psrc, SI_String info)
{
	int team=getProperty("team").toInt();
	list<Card*> lcard;
	lcard.clear();
	int lowpower=INF;
	int boost,base;
	CardSet* pcardSet=game->field->board[team^1];
	for(list<Card*>::iterator it=pcardSet->cardSet.begin();it!=pcardSet->cardSet.end();++it)
	{
		boost=(*it)->getProperty("boostpower").toInt();
		base=(*it)->getProperty("basepower").toInt();
		if(boost+base>lowpower) continue;
		if(boost+base<lowpower)
		{
			lowpower=boost+base;
			lcard.clear();
		}
		lcard.push_back(*it);
	}
	for(list<Card*>::iterator it=lcard.begin();it!=lcard.end();++it)
		emit game->field->_damegeCard(*it,1,this,noinfo);
}
