#ifndef UNSEEN_ELDER_H
#define UNSEEN_ELDER_H

#include"global.h"
#include"card.h"


class Unseen_Elder : public Card
{
	Q_OBJECT
public:
	Unseen_Elder(QObject* parent=0);
	Unseen_Elder(const Unseen_Elder& tcard);
public slots:
	void _played_(Row*,int,SI_Object*,SI_String) override;
};
Q_DECLARE_METATYPE(Unseen_Elder)

#endif // DAGON_H
