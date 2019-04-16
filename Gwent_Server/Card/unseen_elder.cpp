#include "unseen_elder.h"
#include "game.h"
#include"card.h"
#include"cardset.h"
#include"field.h"
#include"global.h"
#include"si_object.h"
#include"userinteraction.h"
#include"weather.h"


Unseen_Elder regist_Unseen_Elder;

Unseen_Elder::Unseen_Elder(QObject* parent):Card(parent)
{
	qRegisterMetaType<Unseen_Elder>("Unseen_Elder");
}

Unseen_Elder::Unseen_Elder(const Unseen_Elder& tcard):Card(tcard)
{

}

void Unseen_Elder::_played_(Row *prow, int order, SI_Object *psrc, SI_String info)
{
	int team=getProperty("team").toInt();
	CardSet* selectRange=new CardSet;
	CardSet* pboard=game->field->board[team];
	const int CONSUME_NUM=3;
	Card* tarCard;
	for(int i=0;i!=CONSUME_NUM;++i)
	{
		selectRange->clear();
		for(list<Card*>::iterator it=pboard->cardSet.begin();it!=pboard->cardSet.end();++it)
			if(this!=(*it))
				selectRange->ins(*it,-1);
		tarCard=game->user[team]->__inputCard(selectRange);
		if(tarCard==NULL) return ;
		emit game->field->_consumeCard(this,tarCard,this,noinfo);
	}

}
