#ifndef VRAN_WARRIOR_H
#define VRAN_WARRIOR_H

#include"global.h"
#include"card.h"


class Vran_Warrior : public Card
{
	Q_OBJECT
public:
	Vran_Warrior(QObject* parent=0);
	Vran_Warrior(const Vran_Warrior& tcard);
public:
	int counter;
	int loopCircle;
public slots:
	void _played_(Row *, int, SI_Object *, SI_String);
	void _startTurn_(int,int);
public:
	void __doConnect() override;
};
Q_DECLARE_METATYPE(Vran_Warrior)

#endif // DAGON_H
