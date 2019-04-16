#ifndef USER_H
#define USER_H

#include"global.h"
#include"si_object.h"

class User:public SI_Object
{
	Q_OBJECT
public:
	User(QObject *parent=0);
};

#endif // USER_H
