#ifndef GE_ELS_H
#define GE_ELS_H

#include"global.h"
#include"card.h"


class Ge_els : public Card
{
	Q_OBJECT
public:
	Ge_els(QObject* parent=0);
	Ge_els(const Ge_els& tcard);
public slots:
	virtual void _played_(Row*,int,SI_Object*,SI_String) override;
};
Q_DECLARE_METATYPE(Ge_els)

#endif // DAGON_H
