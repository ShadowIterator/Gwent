#ifndef WILD_HUNT_RIDER_H
#define WILD_HUNT_RIDER_H

#include"global.h"
#include"card.h"


class Wild_Hunt_Rider : public Card
{
	Q_OBJECT
public:
	Wild_Hunt_Rider(QObject* parent=0);
	Wild_Hunt_Rider(const Wild_Hunt_Rider& tcard);
public slots:
	void _played_(Row*,int,SI_Object*,SI_String) override;
	void _destroyed_(SI_Object*,SI_String) override;
	void _setWeather_(Row*,Weather*,SI_Object*,SI_String);
public:
	void __doConnect() override;
};
Q_DECLARE_METATYPE(Wild_Hunt_Rider)

#endif // DAGON_H
