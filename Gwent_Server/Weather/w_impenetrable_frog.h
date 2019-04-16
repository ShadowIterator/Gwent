#ifndef W_IMPENETRABLE_FROG_H
#define W_IMPENETRABLE_FROG_H

#include"global.h"
#include"weather.h"

class W_Impenetrable_Frog : public Weather
{
	Q_OBJECT
public:
	W_Impenetrable_Frog(QObject* parent=0);
	W_Impenetrable_Frog(const W_Impenetrable_Frog&);
public slots:
	virtual void _startTurn_(int,int) override;
};
Q_DECLARE_METATYPE(W_Impenetrable_Frog)
#endif // W_IMPENETRABLE_FROG_H
