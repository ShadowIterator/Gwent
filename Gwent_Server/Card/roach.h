#ifndef ROACH_H
#define ROACH_H

#include"global.h"
#include"card.h"


class Roach : public Card
{
	Q_OBJECT
public:
	Roach(QObject* parent=0);
	Roach(const Roach& tcard);

	void __doConnect() override;
public slots:
	void playCard(Card*,Row*,int,SI_Object*,SI_String); //tar tar_row order (info
};
Q_DECLARE_METATYPE(Roach)

#endif // DAGON_H
