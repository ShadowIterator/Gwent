#ifndef COMMANDER_S_HORN_H
#define COMMANDER_S_HORN_H

#include"global.h"
#include"card.h"


class Commander_s_Horn : public Card
{
	Q_OBJECT
public:
	Commander_s_Horn(QObject* parent=0);
	Commander_s_Horn(const Commander_s_Horn& tcard);
public slots:
	void _played_(Row*,int,SI_Object*,SI_String) override;
};
Q_DECLARE_METATYPE(Commander_s_Horn)

#endif // DAGON_H
