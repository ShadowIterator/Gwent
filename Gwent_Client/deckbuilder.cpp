#include "deckbuilder.h"
#include "ui_deckbuilder.h"
#include"game.h"
#include"cardset.h"
#include"card.h"
#include"cardwidget.h"
#include"cardsetwidget.h"
#include"field.h"
#include"fieldwidget.h"
#include<QFileDialog>

void DeckBuilder::save()
{
	QFileDialog* saveFileDialog=new QFileDialog(this);
	saveFileDialog->setWindowTitle("Save Deck");
	saveFileDialog->setFileMode(QFileDialog::AnyFile);

	SI_String fileName;
	fileName.clear();

	list<Card*>::iterator it;

	fileName=saveFileDialog->getSaveFileName();
	if(fileName.size()>0)
	{
		QFile fdeck(fileName);
		if(!fdeck.open(QIODevice::WriteOnly))
		{
			qFatal("open file failed");
			return ;
		}
		QTextStream fout(&fdeck);
		fout<<"{"<<endl;
		for(it=viewPlace->cardSet.begin();it!=viewPlace->cardSet.end();++it)
		{
			fout<<(*it)->getProperty("name")<<endl;
		}
		fout<<"}";
	}
}

DeckBuilder::DeckBuilder(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::DeckBuilder)
{
	ui->setupUi(this);

	mapper=new QSignalMapper(this);

	game=new Game;

	viewPlace=game->field->row[ENEMY][1];

	QFile fallcard(":/card/src/card/ALLCARD.txt");
	if(!fallcard.open(QIODevice::ReadOnly))
	{
		qFatal("open file failed");
		return ;
	}
	QTextStream fin(&fallcard);
	Card* pcard;
	QString cardName;

	__inputQString(fin,cardName);

	while(cardName!="#")
	{
		pcard=Card::factory(game,cardName);
		game->field->addtoAllCard(pcard);
		pcard->cid=game->field->cardNum;
		game->user[ALLY]->allcard.insert(SI_String::number(pcard->cid),pcard);
		pcard->setPlace(game->field->hand[ALLY],-1);
		connect(pcard->pwidget->w_picbutton,SIGNAL(clicked()),mapper,SLOT(map()));
		mapper->setMapping(pcard->pwidget->w_picbutton,pcard->cid);
		emit game->field->_ui_setPlace(pcard,game->field->hand[ALLY],-1);
		__inputQString(fin,cardName);
	}
	connect(mapper,SIGNAL(mapped(int)),this,SLOT(clicked(int)));
	connect(ui->save,SIGNAL(clicked(bool)),this,SLOT(save()));

	game->field->pwidget->show();
}

void DeckBuilder::clicked(int cid)
{
	Card* pcard=game->user[ALLY]->_ui_getCard(SI_String::number(cid));
	Card* npcard;

	if(pcard->place!=NULL)
	{
		if(pcard->place==game->field->hand[ALLY])
		{
			npcard=Card::factory(game,pcard->getProperty("name"));
			game->field->addtoAllCard(npcard);
			npcard->cid=game->field->cardNum;
			game->user[ALLY]->allcard.insert(SI_String::number(npcard->cid),npcard);
			emit game->field->_ui_setPlace(npcard,game->field->row[ENEMY][1],-1);
			connect(npcard->pwidget->w_picbutton,SIGNAL(clicked()),mapper,SLOT(map()));
			mapper->setMapping(npcard->pwidget->w_picbutton,npcard->cid);

		}
		else if(pcard->place==game->field->row[ENEMY][1])
		{
			game->user[ALLY]->_ui_eraseID(pcard->cid);
			emit game->field->_ui_setPlace(pcard,game->field->hand[ENEMY],-1);
			delete pcard;
		}
	}
}

DeckBuilder::~DeckBuilder()
{
	delete ui;
}
