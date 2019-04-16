#include "caranthir.h"
#include "game.h"
#include"card.h"
#include"cardset.h"
#include"field.h"
#include"global.h"
#include"si_object.h"
#include"userinteraction.h"
#include"weather.h"


Caranthir regist_Caranthir;

Caranthir::Caranthir(QObject* parent):Card(parent)
{
	qRegisterMetaType<Caranthir>("Caranthir");
}

Caranthir::Caranthir(const Caranthir& tcard):Card(tcard)
{

}

void Caranthir::_played_(Row *prow, int order, SI_Object *psrc, SI_String info)
{
	int team=prow->getProperty("team").toInt();
	int rowNum=prow->getProperty("name").section("_",2,2).toInt();

	Card* pcard=game->user[team]->__inputCard(game->field->board[team^1]);
	CardSet* oppoRow=game->field->row[team^1][rowNum];
	if(pcard!=NULL)
		emit game->field->_adjustPlace(pcard,oppoRow,-1,psrc,info);
	emit game->field->_setWeather(oppoRow,"W_Biting_Frost",this,noinfo);
}
