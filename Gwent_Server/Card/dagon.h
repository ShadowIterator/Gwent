#ifndef DAGON_H
#define DAGON_H

#include"global.h"
#include"card.h"


class Dagon : public Card
{
	Q_OBJECT
public:
	Dagon(QObject* parent=0);
	Dagon(const Dagon& tcard);
public slots:
	virtual void _played_(Row*,int,SI_Object*,SI_String) override;
};
Q_DECLARE_METATYPE(Dagon)

#endif // DAGON_H
