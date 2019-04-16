#include "commander_s_horn.h"
#include "game.h"
#include"card.h"
#include"cardset.h"
#include"field.h"
#include"global.h"
#include"si_object.h"
#include"userinteraction.h"
#include"weather.h"


Commander_s_Horn regist_Commander_s_Horn;

Commander_s_Horn::Commander_s_Horn(QObject* parent):Card(parent)
{
	qRegisterMetaType<Commander_s_Horn>("Commander's_Horn");
}

Commander_s_Horn::Commander_s_Horn(const Commander_s_Horn& tcard):Card(tcard)
{

}

void Commander_s_Horn::_played_(Row *prow, int order, SI_Object *psrc, SI_String info)
{
	int team=getProperty("team").toInt();
	Card* tar=game->user[team]->__inputCard(game->field->fullBoard);
	if(tar==NULL) return ;
	list<Card*>::iterator it=tar->place->_getIterator(tar);
	const int boostVal=4;
	int left=2;
	int right=2;
	list<Card*>::iterator lit,rit;
	for(lit=it;left&&lit!=tar->place->cardSet.begin();--left) --lit;
	for(rit=it,++right;right&&rit!=tar->place->cardSet.end();--right) ++rit;
	for(it=lit;it!=rit;++it)
		emit game->field->_boostCard(*it,boostVal,this,noinfo);
}
