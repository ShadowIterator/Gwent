#include "crone_whispess.h"
#include "game.h"
#include"card.h"
#include"cardset.h"
#include"field.h"
#include"global.h"
#include"si_object.h"
#include"userinteraction.h"
#include"weather.h"


Crone_Whispess regist_Crone_Whispess;

Crone_Whispess::Crone_Whispess(QObject* parent):Card(parent)
{
	qRegisterMetaType<Crone_Whispess>("Crone:Whispess");
}

Crone_Whispess::Crone_Whispess(const Crone_Whispess& tcard):Card(tcard)
{

}

void Crone_Whispess::_played_(Row *prow, int order, SI_Object *psrc, SI_String info)
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
		if(cardName=="Crone:Weavess"||cardName=="Crone:Brewess")
			playlist.push_back(*it);
	}
	for(it=playlist.begin();it!=playlist.end();++it)
		emit game->field->_playCard(*it,prow,-1,this,noinfo);
}
