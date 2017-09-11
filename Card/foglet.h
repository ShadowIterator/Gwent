#ifndef FOGLET_H
#define FOGLET_H

#include"global.h"
#include"card.h"


class Foglet : public Card
{
	Q_OBJECT
public:
	Foglet(QObject* parent=0);
	Foglet(const Foglet& tcard);
};
Q_DECLARE_METATYPE(Foglet)


#endif // FOGLET_H
