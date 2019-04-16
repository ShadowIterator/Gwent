#ifndef CRONE_BREWESS_H
#define CRONE_BREWESS_H

#include"global.h"
#include"card.h"


class Crone_Brewess : public Card
{
	Q_OBJECT
public:
	Crone_Brewess(QObject* parent=0);
	Crone_Brewess(const Crone_Brewess& tcard);
public slots:
	void _played_(Row*,int,SI_Object*,SI_String) override;

};
Q_DECLARE_METATYPE(Crone_Brewess)

#endif // DAGON_H
