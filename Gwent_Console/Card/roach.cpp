#include "roach.h"
#include "game.h"
#include"card.h"
#include"cardset.h"
#include"field.h"
#include"global.h"
#include"si_object.h"
#include"userinteraction.h"
#include"weather.h"


Roach regist_Roach;

Roach::Roach(QObject* parent):Card(parent)
{
	qRegisterMetaType<Roach>("Roach");
}

Roach::Roach(const Roach& tcard):Card(tcard)
{

}

void Roach::__doConnect()
{
	connect(game->field,SIGNAL(_playCard(Card*,Row*,int,SI_Object*,SI_String)),this,SLOT(playCard(Card*,Row*,int,SI_Object*,SI_String)));
}

void Roach::playCard(Card *pcard, Row *prow, int order, SI_Object *psrc, SI_String noinfo)
{
	SI_String placeName=place->getProperty("name").section("_",0,0);
	if(placeName!="deck") return ;
	if(pcard==this) return ;
	if(pcard->getProperty("color")!="gold") return ;
	if(pcard->getProperty("lead")=="true") return ;
	if(getProperty("team")!=pcard->getProperty("team")) return ;
	int team=getProperty("team").toInt();
	int rowNum=rand()%MAX_ROW_NUM;
	int tarOrder=rand()%(game->field->row[team][rowNum]->cardSet.size()+1);
	emit game->field->_playCard(this,game->field->row[team][rowNum],tarOrder,pcard,noinfo);

	return ;
}
