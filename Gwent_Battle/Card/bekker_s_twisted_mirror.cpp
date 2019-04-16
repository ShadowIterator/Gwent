#include "bekker_s_twisted_mirror.h"
#include "game.h"
#include"card.h"
#include"cardset.h"
#include"field.h"
#include"global.h"
#include"si_object.h"
#include"userinteraction.h"
#include"weather.h"


Bekker_s_Twisted_Mirror regist_Bekker_s_Twisted_Mirror;

Bekker_s_Twisted_Mirror::Bekker_s_Twisted_Mirror(QObject* parent):Card(parent)
{
	qRegisterMetaType<Bekker_s_Twisted_Mirror>("Bekker's_Twisted_Mirror");
}

Bekker_s_Twisted_Mirror::Bekker_s_Twisted_Mirror(const Bekker_s_Twisted_Mirror& tcard):Card(tcard)
{

}

void Bekker_s_Twisted_Mirror::_played_(Row *prow, int order, SI_Object *psrc, SI_String info)
{
	if(game->field->fullBoard->cardSet.size()<2) return ;

	CardSet* pcardSet=game->field->fullBoard;

	CardSet highSet;
	CardSet lowSet;

	int highBase=-INF;
	int lowBase=INF;

	int highBoost=-INF;
	int lowBoost=INF;

	int base,boost;

	Card* highCard;
	Card* lowCard;

	for(list<Card*>::iterator it=pcardSet->cardSet.begin();it!=pcardSet->cardSet.end();++it)
	{
		base=(*it)->getProperty("basepower").toInt();
		boost=(*it)->getProperty("boostpower").toInt();
		(*it)->___print();
		if(base+boost>=highBase+highBoost)
		{
			if(base+boost>highBase+highBoost)
			{
				highBase=base;
				highBoost=boost;
				highSet.clear();
			}
			//highSet.push_back(*it);
			highSet.ins(*it,-1);
		}
		if(base+boost<=lowBase+lowBoost)
		{
			if(base+boost<lowBase+lowBoost)
			{
				lowBase=base;
				lowBoost=boost;
				lowSet.clear();
			}
			//lowSet.push_back(*it);
			lowSet.ins(*it,-1);
		}
	}

	highSet.reOrder();
	lowSet.reOrder();

	highCard=*(highSet.cardSet.begin());
	lowCard=*(lowSet.cardSet.begin());

	highCard->___print();
	lowCard->___print();
	qDebug()<<"highBase"<<highBase<<endl
		   <<"highBoost"<<highBoost<<endl
		  <<"lowBase"<<lowBase<<endl
		 <<"lowbBoost"<<lowBoost<<endl;
	emit game->field->_adjustBasePower(highCard,lowBase,this,noinfo);
	emit game->field->_adjustBoostPower(highCard,lowBoost,this,noinfo);

	emit game->field->_adjustBasePower(lowCard,highBase,this,noinfo);
	emit game->field->_adjustBoostPower(lowCard,highBoost,this,noinfo);

}
