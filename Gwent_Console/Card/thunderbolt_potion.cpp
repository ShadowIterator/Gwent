#include "thunderbolt_potion.h"
#include "game.h"
#include"card.h"
#include"cardset.h"
#include"field.h"
#include"global.h"
#include"si_object.h"
#include"userinteraction.h"
#include"weather.h"


Thunderbolt_Potion regist_Thunderbolt_Potion;

Thunderbolt_Potion::Thunderbolt_Potion(QObject* parent):Card(parent)
{
	qRegisterMetaType<Thunderbolt_Potion>("Thunderbolt_Potion");
}

Thunderbolt_Potion::Thunderbolt_Potion(const Thunderbolt_Potion& tcard):Card(tcard)
{

}

void Thunderbolt_Potion::_played_(Row *prow, int order, SI_Object *psrc, SI_String info)
{
	int team=getProperty("team").toInt();
	Card* tar=game->user[team]->__inputCard(game->field->fullBoard);
	if(tar==NULL) return ;
	list<Card*>::iterator it=tar->place->_getIterator(tar);
	const int boostVal=3;
	const int armorVal=2;
	int left=1;
	int right=1;
	list<Card*>::iterator lit,rit;
	for(lit=it;left&&lit!=tar->place->cardSet.begin();--left) --lit;
	for(rit=it,++right;right&&rit!=tar->place->cardSet.end();--right) ++rit;
	for(it=lit;it!=rit;++it)
	{
		emit game->field->_boostCard(*it,boostVal,this,noinfo);
		emit game->field->_increaseArmor(*it,armorVal,this,noinfo);
	}
}
