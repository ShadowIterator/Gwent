#ifndef GERALT_IGNI_H
#define GERALT_IGNI_H

#include"global.h"
#include"card.h"


class Geralt_Igni : public Card
{
	Q_OBJECT
public:
	Geralt_Igni(QObject* parent=0);
	Geralt_Igni(const Geralt_Igni& tcard);
public slots:
	void _played_(Row*,int,SI_Object*,SI_String) override;
};
Q_DECLARE_METATYPE(Geralt_Igni)

#endif // DAGON_H
