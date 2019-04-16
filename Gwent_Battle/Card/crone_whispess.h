#ifndef CRONE_WHISPESS_H
#define CRONE_WHISPESS_H

#include"global.h"
#include"card.h"


class Crone_Whispess : public Card
{
	Q_OBJECT
public:
	Crone_Whispess(QObject* parent=0);
	Crone_Whispess(const Crone_Whispess& tcard);
public slots:
	void _played_(Row*,int,SI_Object*,SI_String) override;

};
Q_DECLARE_METATYPE(Crone_Whispess)

#endif // DAGON_H
