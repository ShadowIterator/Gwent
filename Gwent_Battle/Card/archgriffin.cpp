#include "archgriffin.h"
#include "game.h"
#include"card.h"
#include"cardset.h"
#include"field.h"
#include"global.h"
#include"si_object.h"
#include"userinteraction.h"
#include"weather.h"


Archgriffin regist_Archgriffin;

Archgriffin::Archgriffin(QObject* parent):Card(parent)
{
	qRegisterMetaType<Archgriffin>("Archgriffin");
}

Archgriffin::Archgriffin(const Archgriffin& tcard):Card(tcard)
{

}

void Archgriffin::_played_(Row* prow,int order,SI_Object* psrc,SI_String info)
{
	emit game->field->_removeWeather(prow,this,noinfo);
	CardSet selectlist;
	selectlist.clear();
	CardSet* pgraveyard;
	list<Card*>::iterator it;
	for(int i=0;i!=MAX_TEAM_NUM;++i)
	{
		pgraveyard=game->field->graveyard[i];
		for(it=pgraveyard->cardSet.begin();it!=pgraveyard->cardSet.end();++it)
			if((*it)->getProperty("color")=="bronze")
				selectlist.ins(*it,-1);
	}
	int team=getProperty("team").toInt();
	Card* pcard=game->user[team]->__inputCard(&selectlist);
	int cardTeam=pcard->getProperty("team").toInt();
	cardTeam^=1;
	emit game->field->_adjustProperty(pcard,"team",SI_String::number(cardTeam),this,noinfo);
	emit game->field->_adjustPlace(pcard,game->field->graveyard[cardTeam],-1,this,noinfo);

}
