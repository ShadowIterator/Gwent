#include "foglet.h"
#include"game.h"
#include"cardset.h"

Foglet regist_Foglet;

set<Weather*> Foglet::used;

Foglet::Foglet(QObject* parent):Card(parent)
{
	qRegisterMetaType<Foglet>("Foglet");
}

Foglet::Foglet(const Foglet& tcard):Card(tcard)
{
	//used=new set<Weather*>;
	used.clear();
}

void Foglet::__doConnect()
{
	connect(game,SIGNAL(startTurn_(int,int)),this,SLOT(_startTurn_(int,int)));
	connect(game->field,SIGNAL(setWeather_(Row*,Weather*,SI_Object*,SI_String)),this,SLOT(_setWeather_(Row*,Weather*,SI_Object*,SI_String)));
	connect(game->field,SIGNAL(removeWeather_(Row*,SI_Object*,SI_String)),this,SLOT(_removeWeather_(Row*,SI_Object*,SI_String)));
}

void Foglet::_startTurn_(int turnNum, int curTeam)
{
	used.clear();
}

void Foglet::_setWeather_(Row *prow, Weather* pweather, SI_Object *psrc, SI_String info)
{
	int team=getProperty("team").toInt();
	SI_String weatherName=pweather->getProperty("name");
	if(weatherName!="W_Impenetrable_Frog") return ;
	if(used.find(pweather)!=used.end()) return ;
	if(prow->getProperty("team").toInt()!=team^1) return ;
	if(pweather->getProperty("team").toInt()!=team) return ;
	SI_String placeName=place->getProperty("name").section("_",0,0);
	int rowNum=prow->getProperty("name").section("_",2,2).toInt();
	if(placeName=="deck")
	{
		used.insert(pweather);
		emit game->field->_playCard(this,game->field->row[team][rowNum],-1,this,info);
		return ;
	}
	if(placeName=="graveyard")
	{
		bool flag=true;
		CardSet* pdeck=game->field->deck[team];
		for(list<Card*>::iterator it=pdeck->cardSet.begin();it!=pdeck->cardSet.end();++it)
			if((*it)->getProperty("name")=="Foglet")
			{
				flag=false;
				return ;
			}
		if(flag)
		{
			used.insert(pweather);
			emit game->field->_reviveCard(this,game->field->row[team][rowNum],-1,this,info);
			return ;
		}
	}

}

void Foglet::_removeWeather_(Row *prow, SI_Object *psrc, SI_String info)
{
	bool flag=true;
	Weather* pweather;
	SI_String placeName=place->getProperty("name").section("_",0,0);
	if(placeName!="row") return ;
	for(int team=0;team!=MAX_TEAM_NUM;++team)
		for(int k=0;k!=MAX_ROW_NUM;++k)
		{
			pweather=game->field->row[team][k]->weather;
			if(pweather==NULL) continue;
			if(pweather->getProperty("name")!="W_Impenetrable_Frog") continue;
			flag=false;
			break;
		}
	if(flag)
	{
		emit game->field->_destroyCard(this,this,info);
	}
}
