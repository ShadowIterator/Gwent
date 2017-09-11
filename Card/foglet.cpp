#include "foglet.h"
#include"game.h"


Foglet regist_Foglet;

Foglet::Foglet(QObject* parent):Card(parent)
{
	qRegisterMetaType<Foglet>("Foglet");
}

Foglet::Foglet(const Foglet& tcard):Card(tcard)
{

}

