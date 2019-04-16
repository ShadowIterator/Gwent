#ifndef RALLY_H
#define RALLY_H

#include"global.h"
#include"card.h"


class Rally : public Card
{
	Q_OBJECT
public:
	Rally(QObject* parent=0);
	Rally(const Rally& tcard);
public slots:
	void _played_(Row*,int,SI_Object*,SI_String) override;
};
Q_DECLARE_METATYPE(Rally)

#endif // DAGON_H
