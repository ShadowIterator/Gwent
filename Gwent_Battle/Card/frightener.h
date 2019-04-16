#ifndef FRIGHTENER_H
#define FRIGHTENER_H

#include"global.h"
#include"card.h"


class Frightener : public Card
{
	Q_OBJECT
public:
	Frightener(QObject* parent=0);
	Frightener(const Frightener& tcard);
public slots:
	void _played_(Row*,int,SI_Object*,SI_String) override;
};
Q_DECLARE_METATYPE(Frightener)

#endif // DAGON_H
