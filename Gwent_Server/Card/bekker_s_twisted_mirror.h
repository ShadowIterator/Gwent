#ifndef BEKKER_S_TWISTED_MIRROR_H
#define BEKKER_S_TWISTED_MIRROR_H

#include"global.h"
#include"card.h"


class Bekker_s_Twisted_Mirror : public Card
{
	Q_OBJECT
public:
	Bekker_s_Twisted_Mirror(QObject* parent=0);
	Bekker_s_Twisted_Mirror(const Bekker_s_Twisted_Mirror& tcard);
public slots:
	void _played_(Row*,int,SI_Object*,SI_String) override;
};
Q_DECLARE_METATYPE(Bekker_s_Twisted_Mirror)

#endif // DAGON_H
