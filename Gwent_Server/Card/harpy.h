#ifndef HARPY_H
#define HARPY_H

#include"global.h"
#include"card.h"


class Harpy : public Card
{
	Q_OBJECT
public:
	Harpy(QObject* parent=0);
	Harpy(const Harpy& tcard);
public slots:
	void _played_(Row*,int,SI_Object*,SI_String) override;
};
Q_DECLARE_METATYPE(Harpy)

#endif // DAGON_H
