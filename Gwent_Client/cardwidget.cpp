#include "cardwidget.h"
#include "ui_cardwidget.h"
#include"si_object.h"
#include"card.h"
#include"game.h"
#include"field.h"
#include"fieldwidget.h"
SI_String CardWidget::imgDir=":/img/src/img/";

CardWidget::CardWidget(Card* tpcard,QWidget *parent) :
	QWidget(parent),
	ui(new Ui::CardWidget),
	pcard(tpcard)
{
	ui->setupUi(this);

	pcard->pwidget=this;

	w_picbutton=new QPushButton(this);
	w_glayout=new QGridLayout;

	w_glayout->addWidget(w_picbutton,0,0,-1,-1);
	w_glayout->setMargin(0);

	icon.addFile(imgDir+pcard->getProperty("img"));
	w_picbutton->setIcon(icon);
	w_picbutton->setIconSize(size());
	w_picbutton->setFlat(true);
	w_glayout->setMargin(0);
	setLayout(w_glayout);

	connect(w_picbutton,SIGNAL(clicked()),this,SLOT(setInfoLabel()));
}

void CardWidget::setInfoLabel()
{
	SI_String info;
	info.clear();
	for(QMap<SI_String,SI_String>::iterator it=pcard->properties.begin();it!=pcard->properties.end();++it)
	{
		if(it.key().section("_",0,0)=="ori") continue;
		info=info+it.key()+" : "+it.value()+"\n";
	}
	info=info+"cid : "+SI_String::number(pcard->cid);
	pcard->game->field->pwidget->info->setText(info);
}

CardWidget::~CardWidget()
{
	delete ui;
}

void CardWidget::setEnabled(bool flag)
{
	w_picbutton->setEnabled(flag);
}

void CardWidget::setName(SI_String tname)
{
}

void CardWidget::setPower(int power)
{
}
