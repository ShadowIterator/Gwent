#include "ge_els.h"
#include "game.h"
#include"card.h"
#include"cardset.h"
#include"field.h"
#include"global.h"
#include"si_object.h"
#include"userinteraction.h"
#include"weather.h"


Ge_els regist_Ge_els;

Ge_els::Ge_els(QObject* parent):Card(parent)
{
	qRegisterMetaType<Ge_els>("Ge'els");
}

Ge_els::Ge_els(const Ge_els& tcard):Card(tcard)
{

}

void Ge_els::_played_(Row *prow, int order, SI_Object *psrc, SI_String info)
{
	Card* pgold=NULL;
	Card* psilver=NULL;
	Card* ptar=NULL;
	Card* pother=NULL;

	int team=getProperty("team").toInt();
	CardSet* pcardSet=game->field->deck[team];
	list<Card*>::iterator it;

	SI_String color;

	for(it=pcardSet->cardSet.begin();it!=pcardSet->cardSet.end()&&(pgold==NULL||psilver==NULL);++it)
	{
		color=(*it)->getProperty("color");
		if(color=="gold"&&pgold==NULL) pgold=*it;
		if(color=="silver"&&psilver==NULL) psilver=*it;
	}

	if(pgold==NULL&&psilver==NULL) return ;

	CardSet* tarcardSet;
	int tarorder;

	if(pgold==NULL||psilver==NULL)
	{
		ptar=pgold==NULL?psilver:pgold;
		game->user[team]->__inputPlace(ptar,tarcardSet,tarorder);
		emit game->field->_playCard(ptar,tarcardSet,tarorder,this,noinfo);
		return ;
	}

	CardSet tcardSet;
	tcardSet.clear();
	tcardSet.setProperty("team",SI_String::number(team));
	tcardSet.ins(pgold,-1);
	tcardSet.ins(psilver,-1);
	ptar=game->user[team]->__inputCard(&tcardSet);
	if(ptar!=pgold) pother=pgold;
	if(ptar!=psilver) pother=psilver;

	game->user[team]->__inputPlace(ptar,tarcardSet,tarorder);

	emit game->field->_playCard(ptar,tarcardSet,tarorder,this,noinfo);
	emit game->field->_adjustPlace(pother,game->field->deck[team],0,this,noinfo);

		//emit game->field->_playCard(pgold==NULL?psilver:pgold,);
}
