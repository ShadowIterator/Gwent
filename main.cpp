#include <QCoreApplication>
#include"battle.h"
int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	FlowControl testVal;
	testVal->test();
	return a.exec();
}
