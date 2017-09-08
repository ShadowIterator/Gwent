#ifndef FLOWCONTROL_H
#define FLOWCONTROL_H


#include"global.h"
#include"field.h"

class FlowControl:public QObject
{
public:
	Field field;
	int curTeam;
public:
	FlowControl(QObject* parent=0);
	void __init();
	void __test();
};

#endif // FLOWCONTROL_H
