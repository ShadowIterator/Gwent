#ifndef SELECTDIALOG_H
#define SELECTDIALOG_H

#include <QDialog>

namespace Ui {
class SelectDialog;
}

class SelectDialog : public QDialog
{
	Q_OBJECT

public:
	explicit SelectDialog(QWidget *parent = 0);
	~SelectDialog();

private:
	Ui::SelectDialog *ui;
};

#endif // SELECTDIALOG_H
