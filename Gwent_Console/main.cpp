#include <QCoreApplication>
#include<ctime>

#include"global.h"
#include"card.h"
#include"cardset.h"
#include"game.h"
#include"si_object.h"
#include"user.h"
#include"userinteraction.h"
#include<QtCore>
int main(int argc, char *argv[])
{
	srand(unsigned(time(NULL)));
	QCoreApplication a(argc, argv);

	Game *pgame=new Game;

	QObject::connect(pgame,SIGNAL(_gameover()),&a,SLOT(quit()));

	emit pgame->_startGame();

	return a.exec();
}
