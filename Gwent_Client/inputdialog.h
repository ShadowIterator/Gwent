#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>
#include"global.h"

namespace Ui {
class InputDialog;
}

class InputDialog : public QDialog
{
	Q_OBJECT

public:
	explicit InputDialog(QWidget *parent = 0);
	~InputDialog();

private:
	Ui::InputDialog *ui;
	Game* game;
	SI_String data;
public slots:
	void submit_clicked();
	void updateData(SI_String);
};

#endif // INPUTDIALOG_H
