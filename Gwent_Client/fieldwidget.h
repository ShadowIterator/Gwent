#ifndef FIELDWIDGET_H
#define FIELDWIDGET_H

#include <QDialog>
#include"global.h"
#include"field.h"
namespace Ui {
class FieldWidget;
}

class FieldWidget : public QWidget
{
	Q_OBJECT

public:
	explicit FieldWidget(Field*,QWidget *parent = 0);
	~FieldWidget();
private:
	Ui::FieldWidget *ui;

public:
	Field* pfield;
	QLabel* winRound[MAX_TEAM_NUM];
	QLabel* boardScore[MAX_TEAM_NUM];
	QLabel* info;
	QPushButton* rowScore[MAX_TEAM_NUM][MAX_ROUND_NUM];
	QGridLayout* layout;
	void _update();
	void _setup();
	QSignalMapper* mapper;
public slots:
	void setinfoLabel(int);
};

#endif // FIELDWIDGET_H
