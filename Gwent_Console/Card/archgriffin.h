#ifndef ARCHGRIFFIN_H
#define ARCHGRIFFIN_H

#include"global.h"
#include"card.h"


class Archgriffin : public Card
{
	Q_OBJECT
public:
	Archgriffin(QObject* parent=0);
	Archgriffin(const Archgriffin& tcard);
public slots:
	void _played_(Row*,int,SI_Object*,SI_String) override;

};
Q_DECLARE_METATYPE(Archgriffin)

#endif // DAGON_H
