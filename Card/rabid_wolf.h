#ifndef RABID_WOLF_H
#define RABID_WOLF_H

#include"global.h"
#include"card.h"


class Rabid_Wolf : public Card
{
	Q_OBJECT
public:
	Rabid_Wolf(QObject* parent=0);
	Rabid_Wolf(const Rabid_Wolf& tcard);
public slots:

};
Q_DECLARE_METATYPE(Rabid_Wolf)

#endif // DAGON_H
