#include "arachas_hatchling.h"
#include "game.h"
#include"card.h"
#include"cardset.h"
#include"field.h"
#include"global.h"
#include"si_object.h"
#include"userinteraction.h"
#include"weather.h"


Arachas_Hatchling regist_Arachas_Hatchling;

Arachas_Hatchling::Arachas_Hatchling(QObject* parent):Card(parent)
{
	qRegisterMetaType<Arachas_Hatchling>("Arachas_Hatchling");
}

Arachas_Hatchling::Arachas_Hatchling(const Arachas_Hatchling& tcard):Card(tcard)
{

}

void Arachas_Hatchling::_played_(Row *prow, int order, SI_Object *psrc, SI_String info)
{
	list<Card*> playlist;
	int team=getProperty("team").toInt();
	int tarRowNum=0;
	int tarTeamNum=team;

	list<Card*>::iterator it;
	CardSet* pdeck=game->field->deck[team];
	for(it=pdeck->cardSet.begin();it!=pdeck->cardSet.end();++it)
		if((*it)->getProperty("name")=="Arachas")
			playlist.push_back(*it);
	for(it=playlist.begin();it!=playlist.end();++it)
	{
		(*it)->getPosition(tarTeamNum,tarRowNum);
		emit game->field->_playCard(*it,game->field->row[tarTeamNum][tarRowNum],-1,this,noinfo);
	}

}
