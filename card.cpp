#include"card.h"
#include"cardset.h"

CardSet* Card::getPlace() const
{
	return place;
}



void Card::__readInfo(QTextStream &in)
{
	string temp;
	SI_String propertyName;
	SI_String propertyVal;

//	in>>propertyName;
//	cin>>propertyName;
//	in>>temp;
//	propertyName=QString::fromStdString(temp);
	__inputQString(in,propertyName);
	while(propertyName!="}")
	{
		//in>>propertyVal;
		//in>>temp
		__inputQString(in,propertyVal);
		//properties[propertyName]=propertyVal;
		//properties["ori_"+propertyName]=propertyVal;

		//properties.insert(propertyName,propertyVal);
		//properties.insert("ori_"+propertyName,propertyVal);
		setProperty(propertyName,propertyVal);
		setProperty("ori_"+propertyName,propertyVal);
		__inputQString(in,propertyName);
	}

}

int Card::getOrder() const
{
	int rtn=0;
	for(list<Card*>::iterator it=place->cardSet.begin();it!=place->cardSet.end();++it,++rtn)
		if((*it)==this) return rtn;
	return -1;
}

void Card::setPlace(CardSet *pcardSet, int order)
{
	if(place!=NULL)
		place->erase(this);
	place=pcardSet;
	if(order==-1) place->append(this);
	else place->ins(this,order);
}

Card::Card(QObject* parent):SI_Object(parent)
{
	place=NULL;
}
