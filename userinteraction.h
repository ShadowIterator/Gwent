#ifndef USERINTERACTION_H
#define USERINTERACTION_H

#include"global.h"
#include"field.h"

class UserInteraction:public QObject
{
	Q_OBJECT
private:
	Field field;
};


#endif // USERINTERACTION_H
