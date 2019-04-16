#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"battledialog.h"
#include"card.h"
#include<QGridLayout>
#include"cardset.h"
#include"cardsetwidget.h"
#include"field.h"
#include"fieldwidget.h"
#include"game.h"
#include<QLabel>
#include"inputdialog.h"
#include"deckbuilder.h"

void MainWindow::slot_deckbuilder()
{
	DeckBuilder *pdb=new DeckBuilder;
	pdb->show();
}

void MainWindow::slot_startgame()
{
	InputDialog *input=new InputDialog;
	input->show();
}

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	ui->deckbulder->setText("deckbulder");
	ui->startgame->setText("StartGame");

	ui->deckbulder->show();
	ui->startgame->show();

	connect(ui->deckbulder,SIGNAL(clicked(bool)),this,SLOT(slot_deckbuilder()));
	connect(ui->startgame,SIGNAL(clicked(bool)),this,SLOT(slot_startgame()));
}

MainWindow::~MainWindow()
{
	delete ui;
}
