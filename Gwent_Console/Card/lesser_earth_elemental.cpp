#include "lesser_earth_elemental.h"
#include "game.h"
#include"card.h"
#include"cardset.h"
#include"field.h"
#include"global.h"
#include"si_object.h"
#include"userinteraction.h"
#include"weather.h"


Lesser_Earth_Elemental regist_Lesser_Earth_Elemental;

Lesser_Earth_Elemental::Lesser_Earth_Elemental(QObject* parent):Card(parent)
{
	qRegisterMetaType<Lesser_Earth_Elemental>("Lesser_Earth_Elemental");
}

Lesser_Earth_Elemental::Lesser_Earth_Elemental(const Lesser_Earth_Elemental& tcard):Card(tcard)
{

}
