#ifndef CLEAR_SKIES_H
#define CLEAR_SKIES_H

#include"global.h"
#include"card.h"


class Clear_Skies : public Card
{
	Q_OBJECT
public:
	Clear_Skies(QObject* parent=0);
	Clear_Skies(const Clear_Skies& tcard);
public slots:
	void _played_(Row*,int,SI_Object*,SI_String) override;
};
Q_DECLARE_METATYPE(Clear_Skies)

#endif // DAGON_H
