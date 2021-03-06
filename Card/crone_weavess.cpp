#include "crone_weavess.h"
#include "game.h"
#include"card.h"
#include"cardset.h"
#include"field.h"
#include"global.h"
#include"si_object.h"
#include"userinteraction.h"
#include"weather.h"


Crone_Weavess regist_Crone_Weavess;

Crone_Weavess::Crone_Weavess(QObject* parent):Card(parent)
{
	qRegisterMetaType<Crone_Weavess>("Crone:Weavess");
}

Crone_Weavess::Crone_Weavess(const Crone_Weavess& tcard):Card(tcard)
{

}

void Crone_Weavess::_played_(Row *prow, int order, SI_Object *psrc, SI_String info)
{
	Card* pcard;
	int team=getProperty("team").toInt();
	CardSet* pdeck=game->field->deck[team];
	SI_String cardName;
	list<Card*> playlist;
	list<Card*>::iterator it;
	for(it=pdeck->cardSet.begin();it!=pdeck->cardSet.end();++it)
	{
		cardName=(*it)->getProperty("name");
		if(cardName=="Crone:Whispess"||cardName=="Crone:Brewess")
			playlist.push_back(*it);
	}
	for(it=playlist.begin();it!=playlist.end();++it)
		emit game->field->_playCard(*it,prow,-1,this,noinfo);
}
