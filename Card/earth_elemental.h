#ifndef EARTH_ELEMENTAL_H
#define EARTH_ELEMENTAL_H

#include"global.h"
#include"card.h"


class Earth_Elemental : public Card
{
	Q_OBJECT
public:
	Earth_Elemental(QObject* parent=0);
	Earth_Elemental(const Earth_Elemental& tcard);
public slots:
	virtual void _played_(Row*,int,SI_Object*,SI_String) override;
	void _destroyed_(SI_Object*,SI_String) override;
};
Q_DECLARE_METATYPE(Earth_Elemental)

#endif // DAGON_H
