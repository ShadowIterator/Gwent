#include "rabid_wolf.h"
#include "game.h"
#include"card.h"
#include"cardset.h"
#include"field.h"
#include"global.h"
#include"si_object.h"
#include"userinteraction.h"
#include"weather.h"


Rabid_Wolf regist_Rabid_Wolf;

Rabid_Wolf::Rabid_Wolf(QObject* parent):Card(parent)
{
	qRegisterMetaType<Rabid_Wolf>("Rabid_Wolf");
}

Rabid_Wolf::Rabid_Wolf(const Rabid_Wolf& tcard):Card(tcard)
{

}
