#include "selectdialog.h"
#include "ui_selectdialog.h"

SelectDialog::SelectDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::SelectDialog)
{
	ui->setupUi(this);
}

SelectDialog::~SelectDialog()
{
	delete ui;
}
