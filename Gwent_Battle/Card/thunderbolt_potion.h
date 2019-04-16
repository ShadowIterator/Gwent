#ifndef THUNDERBOLT_POTION_H
#define THUNDERBOLT_POTION_H

#include"global.h"
#include"card.h"


class Thunderbolt_Potion : public Card
{
	Q_OBJECT
public:
	Thunderbolt_Potion(QObject* parent=0);
	Thunderbolt_Potion(const Thunderbolt_Potion& tcard);
public slots:
	void _played_(Row*,int,SI_Object*,SI_String) override;
};
Q_DECLARE_METATYPE(Thunderbolt_Potion)

#endif // DAGON_H
