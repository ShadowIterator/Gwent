#include"flowcontrol.h"

FlowControl::FlowControl(QObject *parent):QObject(parent)
{

}

void FlowControl::__init()
{
//	ifstream fin("data.txt");
	QFile file("D:\\THU\\QT_Dir\\Gwent_Battle\\data.txt");
	if(!file.open(QIODevice::ReadOnly))
	{
		qFatal("open file failed");
		return ;
	}
	QTextStream fin(&file);
	QString temp;
	__inputQString(fin,temp);
	//fin>>temp;
	//Card* pcard=new Card;
	Card* pcard;
	field.cardNum=0;
	field.deck[0].cardSet.clear();
	while(temp!="#")
	{
		//Card*& pcard=field.allCard[(field.cardNum)++];
		pcard=field.allCard[(field.cardNum)++]=new Card;
		pcard->__readInfo(fin);
		pcard->setProperty("team","0");
		pcard->setPlace(&(field.deck[0]),-1);
		__inputQString(fin,temp);
		if(field.cardNum>=10) break;
	}
	while(temp!="#")
	{
		pcard=field.allCard[(field.cardNum)++]=new Card;
		pcard->__readInfo(fin);
		pcard->setProperty("team","1");
		pcard->setPlace(&(field.deck[1]),-1);
		__inputQString(fin,temp);
	}
//	field.___printBoard();


	qDebug()<<"INIT_OVER----------"<<endl<<endl<<endl;
}

void FlowControl::__test()
{
//-----test---------
	QString noinfo=QString::fromStdString("");
	emit field._drawCard(0,NULL,noinfo);
	emit field._drawCard(0,NULL,noinfo);
//	field.hand[0].___print();
	emit field._drawCard(1,NULL,noinfo);
//	field.hand[1].___print();
//	emit field._playCard(*(field.hand[0].cardSet.begin()),&(field.row[0][1]),0,NULL,noinfo);
//	field.___printBoard();bb
//	field.row[0][1].___print();

	list<Card*>::iterator it=field.hand[0].cardSet.begin();
	emit field._adjustArmor(*it,3,NULL,noinfo);
//	field.hand[0].___print();

	++it;
	emit field._boostCard(*it,4,NULL,noinfo);
//	field.hand[0].___print();

	emit field._adjustArmor(*it,3,NULL,noinfo);
	field.hand[0].___print();

//	emit field._damegeCard(*it,15,NULL,noinfo);
	emit field._weakenCard(*it,2,NULL,noinfo);
	field.hand[0].___print();

	qDebug()<<"*******"<<endl;
	field.graveyard[0].___print();

	emit field._exileCard(*it,NULL,noinfo);
	field.graveyard[0].___print();
	field.exiled[0].___print();

	emit field._weakenCard(*it,5,NULL,noinfo);
	field.exiled[0].___print();
	field.graveyard[0].___print();
/*
	field.deck[1].___print();
	qDebug()<<"*******************"<<endl;
	field.deck[1].reOrder();
	field.deck[1].___print();
*/
}
