#ifndef CARANTHIR_H
#define CARANTHIR_H

#include"global.h"
#include"card.h"


class Caranthir : public Card
{
	Q_OBJECT
public:
	Caranthir(QObject* parent=0);
	Caranthir(const Caranthir& tcard);
public slots:
	void _played_(Row*,int,SI_Object*,SI_String) override;
};
Q_DECLARE_METATYPE(Caranthir)

#endif // DAGON_H
