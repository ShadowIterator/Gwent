#include "harpy_hatchling.h"
#include "game.h"
#include"card.h"
#include"cardset.h"
#include"field.h"
#include"global.h"
#include"si_object.h"
#include"userinteraction.h"
#include"weather.h"


Harpy_Hatchling regist_Harpy_Hatchling;

Harpy_Hatchling::Harpy_Hatchling(QObject* parent):Card(parent)
{
	qRegisterMetaType<Harpy_Hatchling>("Harpy_Hatchling");
}

Harpy_Hatchling::Harpy_Hatchling(const Harpy_Hatchling& tcard):Card(tcard)
{

}
