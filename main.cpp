#include <QCoreApplication>
#include<ctime>

#include"global.h"
#include"card.h"
#include"cardset.h"
#include"flowcontrol.h"
#include"si_object.h"
#include"user.h"
#include"userinteraction.h"
int main(int argc, char *argv[])
{
	srand(unsigned(time(NULL)));
	QCoreApplication a(argc, argv);
	Card* pcard=new Card;

	FlowControl *testVal=new FlowControl();
	testVal->__init();
	testVal->__test();
	return a.exec();
}
