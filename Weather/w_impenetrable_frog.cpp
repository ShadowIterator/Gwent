#include "w_impenetrable_frog.h"
#include"cardset.h"
#include"field.h"
#include"game.h"
#include"card.h"
#include"si_object.h"

W_Impenetrable_Frog regist_W_Impenetrable_Frog;

W_Impenetrable_Frog::W_Impenetrable_Frog(QObject* parent):Weather(parent)
{
	qRegisterMetaType<W_Impenetrable_Frog>("W_Impenetrable_Frog");
}

W_Impenetrable_Frog::W_Impenetrable_Frog(const W_Impenetrable_Frog &tweather):Weather(tweather)
{

}

void W_Impenetrable_Frog::_startTurn_(int turnNum, int curTeam)
{
	if(curTeam!=row->getProperty("team").toInt()) return ;
	list<Card*> cardSet;
	cardSet.clear();
	int highPower=-INF;
	int power;
	for(list<Card*>::iterator it=row->cardSet.begin();it!=row->cardSet.end();++it)
	{
		power=(*it)->getProperty("basepower").toInt()+(*it)->getProperty("boostpower").toInt();
		if(power<highPower) continue;
		if(power>highPower)
		{
			highPower=power;
			cardSet.clear();
		}
		cardSet.push_back(*it);
	}
	for(list<Card*>::iterator it=cardSet.begin();it!=cardSet.end();++it)
		emit game->field->_damegeCard(*it,2,this,noinfo);

}
