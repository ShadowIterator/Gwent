#include "inputdialog.h"
#include "ui_inputdialog.h"
#include "game.h"
#include"fieldwidget.h"

InputDialog::InputDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::InputDialog)
{
	ui->setupUi(this);

	data.clear();
	game=new Game;
	game->field->pwidget->show();

	connect(ui->submitButton,SIGNAL(clicked()),this,SLOT(submit_clicked()));
	connect(game->user[ALLY],SIGNAL(_outputInfo(SI_String)),this,SLOT(updateData(SI_String)));

	ui->label->setText("");
}

void InputDialog::submit_clicked()
{
	SI_String cmd=ui->lineEdit->text();
	game->user[ALLY]->ui_cmdExplainer(cmd);
	data=data+"\n"+cmd;
	ui->label->setText(data);
}

void InputDialog::updateData(SI_String str)
{
	data=data+"\n"+str;
	ui->label->setText(data);
}

InputDialog::~InputDialog()
{
	delete ui;
}
