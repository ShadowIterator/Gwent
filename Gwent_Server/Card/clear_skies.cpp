#include "clear_skies.h"
#include "game.h"
#include"card.h"
#include"cardset.h"
#include"field.h"
#include"global.h"
#include"si_object.h"
#include"userinteraction.h"
#include"weather.h"


Clear_Skies regist_Clear_Skies;

Clear_Skies::Clear_Skies(QObject* parent):Card(parent)
{
	qRegisterMetaType<Clear_Skies>("Clear_Skies");
}

Clear_Skies::Clear_Skies(const Clear_Skies& tcard):Card(tcard)
{

}

void Clear_Skies::_played_(Row *prow, int order, SI_Object *psrc, SI_String info)
{
	for(int team=0;team!=MAX_TEAM_NUM;++team)
		for(int k=0;k!=MAX_ROW_NUM;++k)
			emit game->field->_removeWeather(game->field->row[team][k],this,noinfo);
}

