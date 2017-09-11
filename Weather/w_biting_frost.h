#ifndef W_BITING_FROST_H
#define W_BITING_FROST_H

#include"global.h"
#include"weather.h"

class W_Biting_Frost : public Weather
{
	Q_OBJECT
public:
	W_Biting_Frost(QObject* parent=0);
	W_Biting_Frost(const W_Biting_Frost&);
public slots:
	virtual void _startTurn_(int,int) override;
};
Q_DECLARE_METATYPE(W_Biting_Frost)
#endif // W_BITING_FROST_H
