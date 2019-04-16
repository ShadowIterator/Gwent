#ifndef CARDWIDGET_H
#define CARDWIDGET_H


#include"global.h"
#include <QDialog>

namespace Ui {
class CardWidget;
}

class CardWidget : public QWidget
{
	Q_OBJECT

public:
	explicit CardWidget(Card*,QWidget *parent = 0);
	~CardWidget();

private:
	Ui::CardWidget *ui;
public:
	static SI_String imgDir;
	QPushButton* w_picbutton;
	QGridLayout* w_glayout;
	QIcon icon;
	Card* pcard;
public:
	void setEnabled(bool);
	void setName(SI_String);
	void setPower(int);
public slots:
	void setInfoLabel();
};

#endif // CARDWIDGET_H
