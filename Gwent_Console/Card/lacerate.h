#ifndef LACERATE_H
#define LACERATE_H

#include"global.h"
#include"card.h"


class Lacerate : public Card
{
	Q_OBJECT
public:
	Lacerate(QObject* parent=0);
	Lacerate(const Lacerate& tcard);
public slots:
	void _played_(Row*,int,SI_Object*,SI_String) override;
};
Q_DECLARE_METATYPE(Lacerate)

#endif // DAGON_H
