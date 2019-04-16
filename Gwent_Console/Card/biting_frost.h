#ifndef BITING_FROST_H
#define BITING_FROST_H

#include"global.h"
#include"card.h"


class Biting_Frost : public Card
{
	Q_OBJECT
public:
	Biting_Frost(QObject* parent=0);
	Biting_Frost(const Biting_Frost& tcard);
public slots:
	void _played_(Row*,int,SI_Object*,SI_String) override;
};
Q_DECLARE_METATYPE(Biting_Frost)

#endif // DAGON_H
