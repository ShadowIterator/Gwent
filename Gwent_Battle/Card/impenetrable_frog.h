#ifndef IMPENETRABLE_FROG_H
#define IMPENETRABLE_FROG_H

#include"global.h"
#include"card.h"


class Impenetrable_Frog : public Card
{
	Q_OBJECT
public:
	Impenetrable_Frog(QObject* parent=0);
	Impenetrable_Frog(const Impenetrable_Frog& tcard);
public slots:
	void _played_(Row*,int,SI_Object*,SI_String) override;
};
Q_DECLARE_METATYPE(Impenetrable_Frog)

#endif // DAGON_H
