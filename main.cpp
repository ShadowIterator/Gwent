#include <QCoreApplication>
#include"battle.h"
int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	FlowControl *testVal=new FlowControl();
	testVal->__init();
	testVal->__test();
	return a.exec();
}
