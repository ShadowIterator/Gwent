#include "w_torrential_rain.h"
#include"cardset.h"
#include"field.h"
#include"game.h"

W_Torrential_Rain regist_W_Torrential_Rain;

W_Torrential_Rain::W_Torrential_Rain(QObject* parent):Weather(parent)
{
	qRegisterMetaType<W_Torrential_Rain>("W_Torrential_Rain");
}

W_Torrential_Rain::W_Torrential_Rain(const W_Torrential_Rain& tweather):Weather(tweather)
{

}

void W_Torrential_Rain::_startTurn_(int turnNum, int curTeam)
{
	if(curTeam!=row->getProperty("team").toInt()) return ;
	CardSet tar(*row);
	tar.reOrder();
	int damege=addDamege+1;
	list<Card*>::iterator it=tar.cardSet.begin();
	if(it!=tar.cardSet.end())
		emit game->field->_damegeCard(*it,damege,this,noinfo);
	++it;
	if(it!=tar.cardSet.end())
		emit game->field->_damegeCard(*it,damege,this,noinfo);
}
