#ifndef WEATHER_H
#define WEATHER_H

#include"global.h"
#include"si_object.h"
#include"cardset.h"
class Weather:public SI_Object
{
	Q_OBJECT
public:
	CardSet* row;
	Game* game;
	int id;
	int addDamege;
public slots:
	virtual void _startTurn_(int,int);
public:
	Weather(QObject* parent=0);
	Weather(const Weather&);
	virtual ~Weather();
	void __doConnect();
	void setToRow(CardSet*);
	void removeFromRow();
	static Weather* factory(Game*,const SI_String&);
	void __init();
	//virtual __effect()
};

#endif // WEATHER_H
