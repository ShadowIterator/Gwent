#ifndef HARPY_HATCHLING_H
#define HARPY_HATCHLING_H

#include"global.h"
#include"card.h"


class Harpy_Hatchling : public Card
{
	Q_OBJECT
public:
	Harpy_Hatchling(QObject* parent=0);
	Harpy_Hatchling(const Harpy_Hatchling& tcard);
public slots:

};
Q_DECLARE_METATYPE(Harpy_Hatchling)

#endif // DAGON_H
