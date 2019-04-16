#ifndef CARDSETWIDGET_H
#define CARDSETWIDGET_H

#include <QDialog>
#include"global.h"
#include"cardset.h"

namespace Ui {
class CardSetWidget;
}

class CardSetWidget : public QWidget
{
	Q_OBJECT

public:
	explicit CardSetWidget(CardSet* tpcardSet,QWidget *parent = 0);
	~CardSetWidget();

private:
	Ui::CardSetWidget *ui;
public:
	QGridLayout* w_mainlayout;
	QGridLayout* w_glayout;
	QWidget* w_mainwidget;
	CardSet* pcardSet;
public:
	void _update();
};

#endif // CARDSETWIDGET_H
