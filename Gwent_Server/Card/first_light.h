#ifndef FIRST_LIGHT_H
#define FIRST_LIGHT_H

#include"global.h"
#include"card.h"


class First_Light : public Card
{
	Q_OBJECT
public:
	First_Light(QObject* parent=0);
	First_Light(const First_Light& tcard);
public slots:
	void _played_(Row*,int,SI_Object*,SI_String) override;
};
Q_DECLARE_METATYPE(First_Light)

#endif // DAGON_H
