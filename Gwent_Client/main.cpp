#include "mainwindow.h"
#include <QApplication>
#include"battledialog.h"
#include"cardwidget.h"
#include"cardsetwidget.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.show();

	return a.exec();
}
