#include "dagon.h"
#include"game.h"

Dagon regist_Dagon;

Dagon::Dagon(QObject* parent):Card(parent)
{
	qRegisterMetaType<Dagon>("Dagon");
}

Dagon::Dagon(const Dagon& tcard):Card(tcard)
{

}

void Dagon::_played_(Row *row, int order, SI_Object *psrc, SI_String info)
{
/*
	int team=getProperty("team").toInt();
	Card* tarCard=game->user[team]->__inputCard(game->field->fullBoard);
	if(tarCard!=NULL)
		emit game->field->_damegeCard(tarCard,1,this,noinfo);
*/
	Card* pfrost=Card::factory(game,"Biting_Frost");
	Card* prain=Card::factory(game,"Torrential_Rain");
	Card* pfrog=Card::factory(game,"Impenetrable_Frog");

	int team=getProperty("team").toInt();

	CardSet cardSet;
	cardSet.cardSet.push_back(pfrost);
	cardSet.cardSet.push_back(pfrog);
	cardSet.cardSet.push_back(prain);

	Card* tar=game->user[team]->__inputCard(&cardSet);
	//tar->setProperty("team",SI_String::number(team));
	tar->setup(team,game);
	game->field->addtoAllCard(tar);

	if(pfrost!=tar)
		pfrost->destroy();
	if(pfrog!=tar)
		pfrog->destroy();
	if(prain!=tar)
		prain->destroy();

	emit game->field->_playCard(tar,game->field->graveyard[team],-1,this,noinfo);

}


