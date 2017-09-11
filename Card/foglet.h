#ifndef FOGLET_H
#define FOGLET_H

#include"global.h"
#include"card.h"


class Foglet : public Card
{
	Q_OBJECT
public:
	Foglet(QObject* parent=0);
	Foglet(const Foglet& tcard);
public:
	static set<Weather*> used;
public slots:
	void _startTurn_(int,int);
	void _setWeather_(Row*,Weather*,SI_Object*,SI_String);
	void _removeWeather_(Row*,SI_Object*,SI_String);
	void __doConnect() override;
};
Q_DECLARE_METATYPE(Foglet)


#endif // FOGLET_H
