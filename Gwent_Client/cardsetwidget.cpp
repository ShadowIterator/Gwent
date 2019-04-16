#include "cardsetwidget.h"
#include "ui_cardsetwidget.h"
#include "cardwidget.h"
#include"cardset.h"
#include"card.h"
CardSetWidget::CardSetWidget(CardSet* tpcardSet,QWidget *parent) :
	QWidget(parent),
	ui(new Ui::CardSetWidget),
	pcardSet(tpcardSet)
{
	ui->setupUi(this);
	w_glayout=NULL;
	w_mainwidget=NULL;
	w_mainlayout=NULL;
	resize(ROW_WIDTH,ROW_HEIGHT);
	pcardSet->pwidget=this;
}

CardSetWidget::~CardSetWidget()
{
	delete ui;
}

void CardSetWidget::_update()
{
	if(w_mainlayout!=NULL)
		delete w_mainlayout;
	if(w_glayout!=NULL)
		delete w_glayout;
	if(w_mainwidget!=NULL)
		delete w_mainwidget;
	w_glayout=new QGridLayout;
	list<Card*>::iterator it;
	int k;
	pcardSet->___print();
	for(it=pcardSet->cardSet.begin(),k=0;it!=pcardSet->cardSet.end();++it,++k)
	{
		w_glayout->addWidget((*it)->pwidget,0,k,1,1);
		(*it)->pwidget->setParent(this);
		(*it)->pwidget->show();
	}
	w_glayout->setMargin(0);
	w_glayout->setAlignment(Qt::AlignCenter);
	setLayout(w_glayout);
}
