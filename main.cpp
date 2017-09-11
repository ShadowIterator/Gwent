#include <QCoreApplication>
#include<ctime>

#include"global.h"
#include"card.h"
#include"cardset.h"
#include"game.h"
#include"si_object.h"
#include"user.h"
#include"userinteraction.h"
int main(int argc, char *argv[])
{
	srand(unsigned(time(NULL)));
	QCoreApplication a(argc, argv);

	Game *pgame=new Game;
	emit pgame->_startGame();
	//pgame->field->___printBoard();
	return a.exec();
}
