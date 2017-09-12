#ifndef ARACHAS_BEHEMOTH_H
#define ARACHAS_BEHEMOTH_H

#include"global.h"
#include"card.h"


class Arachas_Behemoth : public Card
{
	Q_OBJECT
public:
	Arachas_Behemoth(QObject* parent=0);
	Arachas_Behemoth(const Arachas_Behemoth& tcard);
public slots:
	void _consumeCard_(Card*,Card*,SI_Object*,SI_String);
public:
	virtual void __doConnect() override;
};
Q_DECLARE_METATYPE(Arachas_Behemoth)

#endif // DAGON_H
