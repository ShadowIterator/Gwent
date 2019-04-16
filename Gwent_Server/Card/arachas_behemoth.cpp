#include "arachas_behemoth.h"
#include "game.h"
#include"card.h"
#include"cardset.h"
#include"field.h"
#include"global.h"
#include"si_object.h"
#include"userinteraction.h"
#include"weather.h"


Arachas_Behemoth regist_Arachas_Behemoth;

Arachas_Behemoth::Arachas_Behemoth(QObject* parent):Card(parent)
{
	qRegisterMetaType<Arachas_Behemoth>("Arachas_Behemoth");
}

Arachas_Behemoth::Arachas_Behemoth(const Arachas_Behemoth& tcard):Card(tcard)
{

}

void Arachas_Behemoth::__doConnect()
{
	connect(game->field,SIGNAL(consumeCard_(Card*,Card*,SI_Object*,SI_String)),this,SLOT(_consumeCard_(Card*,Card*,SI_Object*,SI_String)));
}

void Arachas_Behemoth::_consumeCard_(Card *psrcCard, Card *ptarCard, SI_Object *psrc, SI_String info)
{
	int team=getProperty("team").toInt();
	if(place==NULL) return ;
	if(place->getProperty("name").section("_",0,0)!="row") return ;
	if(team!=psrcCard->getProperty("team").toInt()) return ;
	int tarRowNum=rand()%MAX_ROW_NUM;
	CardSet* tarRow=game->field->row[team][tarRowNum];
	int tarOrder=rand()%(tarRow->cardSet.size()+1);
	Card* pArachas_Hatchling=Card::factory(game,"Arachas_Hatchling");
	pArachas_Hatchling->setup(team,game);
	game->field->addtoAllCard(pArachas_Hatchling);

	emit game->field->_playCard(pArachas_Hatchling,tarRow,tarOrder,this,noinfo);

	if(getProperty("shield")=="true")
	{
		emit game->field->_adjustProperty(this,"shield","false",this,noinfo);
		return ;
	}

	int basePower=getProperty("basepower").toInt();
	int tarBoostPower=getProperty("boostpower").toInt()-1;
	emit game->field->_adjustBoostPower(this,tarBoostPower,this,noinfo);
	if(tarBoostPower+basePower<=0)
		emit game->field->_destroyCard(this,this,noinfo);
	emit game->field->damegeCard_(this,1,this,noinfo);
}
