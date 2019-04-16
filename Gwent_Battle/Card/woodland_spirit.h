#ifndef WOODLAND_SPIRIT_H
#define WOODLAND_SPIRIT_H

#include"global.h"
#include"card.h"


class Woodland_Spirit : public Card
{
	Q_OBJECT
public:
	Woodland_Spirit(QObject* parent=0);
	Woodland_Spirit(const Woodland_Spirit& tcard);
public slots:
	void _played_(Row*,int,SI_Object*,SI_String) override;
};
Q_DECLARE_METATYPE(Woodland_Spirit)

#endif // DAGON_H
