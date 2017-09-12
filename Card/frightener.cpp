#include "frightener.h"
#include "game.h"
#include"card.h"
#include"cardset.h"
#include"field.h"
#include"global.h"
#include"si_object.h"
#include"userinteraction.h"
#include"weather.h"


Frightener regist_Frightener;

Frightener::Frightener(QObject* parent):Card(parent)
{
	qRegisterMetaType<Frightener>("Frightener");
}

Frightener::Frightener(const Frightener& tcard):Card(tcard)
{

}

void Frightener::_played_(Row *prow, int order, SI_Object *psrc, SI_String info)
{
	int team=getProperty("team").toInt();
	emit game->field->_drawCard(team,this,noinfo);
	CardSet selectSet;
	CardSet* pcardSet=game->field->board[team];
	for(list<Card*>::iterator it=pcardSet->cardSet.begin();it!=pcardSet->cardSet.end();++it)
		if(prow!=(*it)->place)
			selectSet.ins(*it,-1);
	Card* pcard=game->user[team]->__inputCard(&selectSet);
	if(pcard!=NULL)
		emit game->field->_adjustPlace(pcard,prow,-1,this,noinfo);
}
