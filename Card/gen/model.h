#ifndef ~_H
#define ~_H

#include"global.h"
#include"card.h"


class @ : public Card
{
	Q_OBJECT
public:
	@(QObject* parent=0);
	@(const @& tcard);
public slots:

};
Q_DECLARE_METATYPE(@)

#endif // DAGON_H
