#include "vran_warrior.h"
#include "game.h"
#include"card.h"
#include"cardset.h"
#include"field.h"
#include"global.h"
#include"si_object.h"
#include"userinteraction.h"
#include"weather.h"


Vran_Warrior regist_Vran_Warrior;

Vran_Warrior::Vran_Warrior(QObject* parent):Card(parent),counter(2),loopCircle(2)
{
	qRegisterMetaType<Vran_Warrior>("Vran_Warrior");
}

Vran_Warrior::Vran_Warrior(const Vran_Warrior& tcard):Card(tcard)
{

}

void Vran_Warrior::_played_(Row *prow, int order, SI_Object *psrc, SI_String info)
{
	list<Card*>::iterator it=prow->_getIterator(this);
	++it;
	Card* tarCard;
	if(it==prow->cardSet.end()) return ;
	tarCard=*it;

	emit game->field->_consumeCard(this,tarCard,this,noinfo);
}

void Vran_Warrior::__doConnect()
{
	connect(game,SIGNAL(startTurn_(int,int)),this,SLOT(_startTurn_(int,int)));
}

void Vran_Warrior::_startTurn_(int turnNum, int curTeam)
{
	if(place==NULL) return ;
	if(place->getProperty("name").section("_",0,0)!="row") return ;
	--counter;
	if(counter) return ;

	counter=loopCircle;

	list<Card*>::iterator it=place->_getIterator(this);
	++it;
	Card* tarCard;
	if(it==place->cardSet.end()) return ;

	tarCard=*it;

	emit game->field->_consumeCard(this,tarCard,this,noinfo);
}
