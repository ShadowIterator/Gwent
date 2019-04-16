#ifndef CELAENO_HARPY_H
#define CELAENO_HARPY_H

#include"global.h"
#include"card.h"


class Celaeno_Harpy : public Card
{
	Q_OBJECT
public:
	Celaeno_Harpy(QObject* parent=0);
	Celaeno_Harpy(const Celaeno_Harpy& tcard);
public slots:
	void _played_(Row*,int,SI_Object*,SI_String) override;
};
Q_DECLARE_METATYPE(Celaeno_Harpy)

#endif // DAGON_H
