#ifndef TORRENTIAL_RAIN_H
#define TORRENTIAL_RAIN_H

#include"global.h"
#include"weather.h"

class W_Torrential_Rain:public Weather
{
	Q_OBJECT
public:
	W_Torrential_Rain(QObject* parent=0);
	W_Torrential_Rain(const W_Torrential_Rain&);
public slots:
	virtual void _startTurn_(int,int) override;
};
Q_DECLARE_METATYPE(W_Torrential_Rain)

#endif // TORRENTIAL_RAIN_H
