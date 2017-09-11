#include "$.h"
#include "game.h"
#include"card.h"
#include"cardset.h"
#include"field.h"
#include"global.h"
#include"si_object.h"
#include"userinteraction.h"
#include"weather.h"


@ regist_@;

@::@(QObject* parent):Card(parent)
{
	qRegisterMetaType<@>("@");
}

@::@(const @& tcard):Card(tcard)
{

}
