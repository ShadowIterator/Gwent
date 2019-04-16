#ifndef TORRENTIAL_RAIN_H
#define TORRENTIAL_RAIN_H

#include"global.h"
#include"card.h"


class Torrential_Rain : public Card
{
	Q_OBJECT
public:
	Torrential_Rain(QObject* parent=0);
	Torrential_Rain(const Torrential_Rain& tcard);
public slots:
	void _played_(Row*,int,SI_Object*,SI_String) override;
};
Q_DECLARE_METATYPE(Torrential_Rain)

#endif // DAGON_H
