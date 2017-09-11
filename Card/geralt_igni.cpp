#include "geralt_igni.h"
#include "game.h"
#include"card.h"
#include"cardset.h"
#include"field.h"
#include"global.h"
#include"si_object.h"
#include"userinteraction.h"
#include"weather.h"


Geralt_Igni regist_Geralt_Igni;

Geralt_Igni::Geralt_Igni(QObject* parent):Card(parent)
{
	qRegisterMetaType<Geralt_Igni>("Geralt:Igni");
}

Geralt_Igni::Geralt_Igni(const Geralt_Igni& tcard):Card(tcard)
{

}

void Geralt_Igni::_played_(Row* prow,int order,SI_Object* psrc,SI_String info)
{
	int teamNum;
	int rowNum;
	const int threshold=25;
	CardSet* tprow;
	game->field->getRowNum(prow,teamNum,rowNum);
	tprow=game->field->row[teamNum^1][rowNum];
	int power;
	int highPower=-INF;
	if(tprow->score>=threshold)
	{
		list<Card*> cardSet;
		cardSet.clear();
		for(list<Card*>::iterator it=tprow->cardSet.begin();it!=tprow->cardSet.end();++it)
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
			emit game->field->_destroyCard(*it,this,noinfo);
	}

}
