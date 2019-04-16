#include "fieldwidget.h"
#include "ui_fieldwidget.h"
#include"field.h"
#include"cardsetwidget.h"
#include"cardset.h"

FieldWidget::FieldWidget(Field* tpfield,QWidget *parent) :
	QWidget(parent),
	ui(new Ui::FieldWidget),
	layout(NULL),
	pfield(tpfield)
{
	ui->setupUi(this);
	mapper=new QSignalMapper(this);
	resize(ROW_WIDTH+INFO_WIDTH,11*ROW_HEIGHT);
	for(int team=0;team!=MAX_TEAM_NUM;++team)
		winRound[team]=boardScore[team]=NULL;
	info=0;
	pfield->pwidget=this;
}

FieldWidget::~FieldWidget()
{
	delete ui;
}

void FieldWidget::setinfoLabel(int id)
{
	int team=id/3;
	int rowNum=id%3;
	SI_String sinfo;
	sinfo.clear();
	Row* prow=pfield->row[team][rowNum];
	for(QMap<SI_String,SI_String>::iterator it=prow->properties.begin();it!=prow->properties.end();++it)
	{
		sinfo=sinfo+it.key()+" : "+it.value()+"\n";
	}
	info->setText(sinfo);
}

void FieldWidget::_setup()
{
	if(layout!=NULL)
		delete layout;
	layout=new QGridLayout;
	for(int team=0;team!=MAX_TEAM_NUM;++team)
	{
		for(int k=0;k!=MAX_ROW_NUM;++k)
		{
			pfield->row[team][k]->creatWidget();
			pfield->row[team][k]->setParent(this);
			pfield->row[team][k]->pwidget->show();

			rowScore[team][k]=new QPushButton(this);
			rowScore[team][k]->setEnabled(true);
			rowScore[team][k]->show();
//			rowScore[team][k]->setAlignment(Qt::AlignCenter);
			connect(rowScore[team][k],SIGNAL(clicked(bool)),mapper,SLOT(map()));
			mapper->setMapping(rowScore[team][k],team*3+k);
		}
		pfield->graveyard[team]->creatWidget();
		pfield->graveyard[team]->setParent(this);
		pfield->graveyard[team]->pwidget->show();
		winRound[team]=new QLabel(this);
		winRound[team]->show();
		boardScore[team]=new QLabel(this);
		boardScore[team]->show();

		winRound[team]->setAlignment(Qt::AlignCenter);
		boardScore[team]->setAlignment(Qt::AlignCenter);


	}
	connect(mapper,SIGNAL(mapped(int)),this,SLOT(setinfoLabel(int)));
	info=new QLabel(this);
	pfield->selectArea->creatWidget();
	pfield->selectArea->setParent(this);
	pfield->hand[0]->creatWidget();
	pfield->hand[0]->setParent(this);

	layout->addWidget(pfield->selectArea->pwidget,0,0,1,10);
	layout->addWidget(pfield->graveyard[ENEMY]->pwidget,1,0,1,10);

	layout->addWidget(pfield->row[ENEMY][ROWNUM_FAR]->pwidget,3,0,1,10);
	layout->addWidget(pfield->row[ENEMY][ROWNUM_MIDDLE]->pwidget,4,0,1,10);
	layout->addWidget(pfield->row[ENEMY][ROWNUM_CLOSE]->pwidget,5,0,1,10);
	layout->addWidget(pfield->row[ALLY][ROWNUM_CLOSE]->pwidget,6,0,1,10);
	layout->addWidget(pfield->row[ALLY][ROWNUM_MIDDLE]->pwidget,7,0,1,10);
	layout->addWidget(pfield->row[ALLY][ROWNUM_FAR]->pwidget,8,0,1,10);
	layout->addWidget(pfield->hand[ALLY]->pwidget,9,0,1,10);
	layout->addWidget(pfield->graveyard[ALLY]->pwidget,10,0,1,10);

	layout->addWidget(rowScore[ENEMY][ROWNUM_FAR],3,10,1,1);
	layout->addWidget(rowScore[ENEMY][ROWNUM_MIDDLE],4,10,1,1);
	layout->addWidget(rowScore[ENEMY][ROWNUM_CLOSE],5,10,1,1);
	layout->addWidget(rowScore[ALLY][ROWNUM_CLOSE],6,10,1,1);
	layout->addWidget(rowScore[ALLY][ROWNUM_MIDDLE],7,10,1,1);
	layout->addWidget(rowScore[ALLY][ROWNUM_FAR],8,10,1,1);

	layout->addWidget(winRound[ENEMY],1,10,1,4);
	layout->addWidget(boardScore[ENEMY],2,10,1,4);
	layout->addWidget(info,3,11,6,4);
	layout->addWidget(boardScore[ALLY],9,10,1,4);
	layout->addWidget(winRound[ALLY],10,10,1,4);


	layout->setMargin(0);

	setLayout(layout);
}


void FieldWidget::_update()
{
	if(layout!=NULL)
		delete layout;
	layout=new QGridLayout;
}
