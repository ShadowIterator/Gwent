#include <QCoreApplication>
#include<ctime>
#include"battle.h"
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
