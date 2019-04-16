#ifndef CRONE_WEAVESS_H
#define CRONE_WEAVESS_H

#include"global.h"
#include"card.h"


class Crone_Weavess : public Card
{
	Q_OBJECT
public:
	Crone_Weavess(QObject* parent=0);
	Crone_Weavess(const Crone_Weavess& tcard);
public slots:
	void _played_(Row*,int,SI_Object*,SI_String) override;

};
Q_DECLARE_METATYPE(Crone_Weavess)

#endif // DAGON_H
