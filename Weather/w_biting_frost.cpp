#include "w_biting_frost.h"
#include"cardset.h"
#include"field.h"
#include"game.h"
#include"card.h"
#include"si_object.h"

W_Biting_Frost regist_W_Biting_Frost;

W_Biting_Frost::W_Biting_Frost(QObject* parent):Weather(parent)
{
	qRegisterMetaType<W_Biting_Frost>("W_Biting_Frost");
}

W_Biting_Frost::W_Biting_Frost(const W_Biting_Frost &tweather):Weather(tweather)
{

}

void W_Biting_Frost::_startTurn_(int turnNum, int curTeam)
{
	if(curTeam!=row->getProperty("team").toInt()) return ;
	list<Card*> cardSet;
	cardSet.clear();
	int lowPower=INF;
	int power;
	for(list<Card*>::iterator it=row->cardSet.begin();it!=row->cardSet.end();++it)
	{
		power=(*it)->getProperty("basepower").toInt()+(*it)->getProperty("boostpower").toInt();
		if(power>lowPower) continue;
		if(power<lowPower)
		{
			lowPower=power;
			cardSet.clear();
		}
		cardSet.push_back(*it);
	}
	for(list<Card*>::iterator it=cardSet.begin();it!=cardSet.end();++it)
		emit game->field->_damegeCard(*it,2,this,noinfo);
}
