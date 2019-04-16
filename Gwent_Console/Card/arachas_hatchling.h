#ifndef ARACHAS_HATCHLING_H
#define ARACHAS_HATCHLING_H

#include"global.h"
#include"card.h"


class Arachas_Hatchling : public Card
{
	Q_OBJECT
public:
	Arachas_Hatchling(QObject* parent=0);
	Arachas_Hatchling(const Arachas_Hatchling& tcard);
public slots:
	void _played_(Row*,int,SI_Object*,SI_String) override;
};
Q_DECLARE_METATYPE(Arachas_Hatchling)

#endif // DAGON_H
