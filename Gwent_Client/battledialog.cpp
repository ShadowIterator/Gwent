#include "battledialog.h"
#include "ui_battledialog.h"
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QLabel>
#include<QPushButton>
#include<QGridLayout>
BattleDialog::BattleDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::BattleDialog)
{
	ui->setupUi(this);
	//ui->widget->setGeometry();
	//ui->mainlayout
	QLabel *b[8];
	QLabel *escore;
	QLabel *mscore;
	QLabel *info;
	QGridLayout* layout=new QGridLayout;
	escore=new QLabel();
	info=new QLabel();
	mscore=new QLabel();
//	infoboard->addWidget(escore);
//	infoboard->addWidget(info);
//	infoboard->addWidget(mscore);

	for(int k=0;k!=8;++k)
	{
		//w[i]=new QWidget(this);
		b[k]=new QLabel(this);
		b[k]->setText(QString::number(k));
		//b[k]->setBackgroundRole();
		//board->addWidget(p[k]);
		layout->addWidget(b[k],k,0,1,10);
	}

	escore->setText("escore");
	mscore->setText("mscore");
	info->setText("info");

	layout->addWidget(escore,0,11,3,4);
	layout->addWidget(info,4,11,2,4);
	layout->addWidget(mscore,6,11,3,4);
	setLayout(layout);

}

BattleDialog::~BattleDialog()
{
	delete ui;
}
