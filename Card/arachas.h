#ifndef ARACHAS_H
#define ARACHAS_H

#include"global.h"
#include"card.h"


class Arachas : public Card
{
	Q_OBJECT
public:
	Arachas(QObject* parent=0);
	Arachas(const Arachas& tcard);
public slots:
	void _played_(Row*,int,SI_Object*,SI_String) override;
};
Q_DECLARE_METATYPE(Arachas)

#endif // DAGON_H
