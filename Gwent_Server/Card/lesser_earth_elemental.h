#ifndef LESSER_EARTH_ELEMENTAL_H
#define LESSER_EARTH_ELEMENTAL_H

#include"global.h"
#include"card.h"


class Lesser_Earth_Elemental : public Card
{
	Q_OBJECT
public:
	Lesser_Earth_Elemental(QObject* parent=0);
	Lesser_Earth_Elemental(const Lesser_Earth_Elemental& tcard);
public slots:

};
Q_DECLARE_METATYPE(Lesser_Earth_Elemental)

#endif // DAGON_H
