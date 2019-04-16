#include "first_light.h"
#include "game.h"
#include"card.h"
#include"cardset.h"
#include"field.h"
#include"global.h"
#include"si_object.h"
#include"userinteraction.h"
#include"weather.h"


First_Light regist_First_Light;

First_Light::First_Light(QObject* parent):Card(parent)
{
	qRegisterMetaType<First_Light>("First_Light");
}

First_Light::First_Light(const First_Light& tcard):Card(tcard)
{

}

void First_Light::_played_(Row *prow, int order, SI_Object *psrc, SI_String info)
{
	Card* pClearSkies=Card::factory(game,"Clear_Skies");
	Card* pRally=Card::factory(game,"Rally");

	int team=getProperty("team").toInt();

	CardSet cardSet;
	cardSet.clear();
	cardSet.ins(pClearSkies,-1);
	cardSet.ins(pRally,-1);

	Card* tar=game->user[team]->__inputCard(&cardSet);
	tar->setup(team,game);
	game->field->addtoAllCard(tar);

	if(pClearSkies!=tar) pClearSkies->destroy();
	if(pRally!=tar) pRally->destroy();

	emit game->field->_playCard(tar,game->field->graveyard[team],-1,this,noinfo);
}
