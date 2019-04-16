#ifndef DECKBUILDER_H
#define DECKBUILDER_H

#include <QDialog>
#include<QSignalMapper>
#include"global.h"
namespace Ui {
class DeckBuilder;
}

class DeckBuilder : public QDialog
{
	Q_OBJECT

public:
	explicit DeckBuilder(QWidget *parent = 0);
	~DeckBuilder();

private:
	Ui::DeckBuilder *ui;

public:
	Game* game;
	QSignalMapper* mapper;
	CardSet* viewPlace;
public slots:
	void clicked(int);
	void save();
};

#endif // DECKBUILDER_H
