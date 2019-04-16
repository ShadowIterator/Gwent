#ifndef HARPY_EGG_H
#define HARPY_EGG_H

#include"global.h"
#include"card.h"


class Harpy_Egg : public Card
{
	Q_OBJECT
public:
	Harpy_Egg(QObject* parent=0);
	Harpy_Egg(const Harpy_Egg& tcard);
public slots:
	void _destroyed_(SI_Object*,SI_String) override;
	void _consumed_(Card*,SI_Object*,SI_String) override;
};
Q_DECLARE_METATYPE(Harpy_Egg)

#endif // DAGON_H
