#ifndef BATTLEDIALOG_H
#define BATTLEDIALOG_H

#include <QDialog>

namespace Ui {
class BattleDialog;
}

class BattleDialog : public QDialog
{
	Q_OBJECT

public:
	explicit BattleDialog(QWidget *parent = 0);
	~BattleDialog();

private:
	Ui::BattleDialog *ui;
};

#endif // BATTLEDIALOG_H
