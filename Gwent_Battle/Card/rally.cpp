#include "rally.h"
#include "game.h"
#include"card.h"
#include"cardset.h"
#include"field.h"
#include"global.h"
#include"si_object.h"
#include"userinteraction.h"
#include"weather.h"


Rally regist_Rally;

Rally::Rally(QObject* parent):Card(parent)
{
	qRegisterMetaType<Rally>("Rally");
}

Rally::Rally(const Rally& tcard):Card(tcard)
{

}

void Rally::_played_(Row *prow, int order, SI_Object *psrc, SI_String info)
{
	int team=getProperty("team").toInt();
	CardSet* pdeck=game->field->deck[team];
	if(pdeck->cardSet.empty()) return ;
	int index=rand()%(pdeck->cardSet.size());
	Card* pcard=*(pdeck->_getIterator(index));

	CardSet* tarcardSet;
	int tarorder;

	game->user[team]->__inputPlace(pcard,tarcardSet,tarorder);

	emit game->field->_playCard(pcard,tarcardSet,tarorder,this,noinfo);

}
