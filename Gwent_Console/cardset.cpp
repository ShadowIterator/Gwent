#include"cardset.h"
#include"weather.h"

CardSet::CardSet(QObject *parent):SI_Object(parent)
{
	cardSet.clear();
	fath=NULL;
	score=0;
	weather=NULL;
}

void CardSet::clear()
{
	cardSet.clear();
}

bool CardSet::checkCard(Card *pcard)
{
	for(list<Card*>::iterator it=cardSet.begin();it!=cardSet.end();++it)
		if(*it==pcard) return true;
	return false;
}

Card* CardSet::atIndex(int index)
{
	if(index<0) return NULL;
	list<Card*>::iterator it=cardSet.begin();
	for(;index&&(it!=cardSet.end());--index,++it);
	if(it==cardSet.end()) return NULL;
	return *it;
}

void CardSet::__changeScore(int delta)
{
	score+=delta;
	if(fath!=NULL) fath->__changeScore(delta);
}

void CardSet::reOrder()
{
	vector<Card*> temp;
	temp.assign(cardSet.begin(),cardSet.end());
	std::random_shuffle(temp.begin(),temp.end());
	cardSet.assign(temp.begin(),temp.end());
}

void CardSet::erase(Card* pcard)
{
	if(fath!=NULL) fath->erase(pcard);
	list<Card*>::iterator it;
	for(it=cardSet.begin();it!=cardSet.end();++it)
		if((*it)==pcard) break;
	if(it!=cardSet.end())
	{
		score-=pcard->getProperty("basepower").toInt();
		score-=pcard->getProperty("boostpower").toInt();
		cardSet.erase(it);
	}
}

void CardSet::erase(Card& tcard)
{
	erase(&tcard);
}

void CardSet::ins(Card* pcard,int order)
{
	if(fath!=NULL) fath->ins(pcard,order);
	if(order<0) cardSet.push_back(pcard);
	else if(!order) cardSet.push_front(pcard);
	else cardSet.insert(_getIterator(order),pcard);
	score+=pcard->getProperty("basepower").toInt();
	score+=pcard->getProperty("boostpower").toInt();
}

list<Card*>::iterator CardSet::_getIterator(int index)
{
	if(index<0) return cardSet.end();
	list<Card*>::iterator it=cardSet.begin();
	for(;index&&(it!=cardSet.end());--index) ++it;
	return it;
}

list<Card*>::iterator CardSet::_getIterator(Card *pcard)
{
	list<Card*>::iterator it=cardSet.begin();
	for(;it!=cardSet.end();++it)
		if(*it==pcard) return it;
	return it;
}

#ifdef DEBUG
void CardSet::___print()
{
	qDebug()<<"-------------------------------------";
	qDebug()<<getProperty("name")<<"    "<<"score: "<<score;
	if(weather!=NULL)
		qDebug()<<weather->getProperty("name")<<"  "<<weather->addDamege;
	qDebug()<<"";
	for(list<Card*>::iterator it=cardSet.begin();it!=cardSet.end();++it)
	{
		(*it)->___print();
	}
}

#endif //DEBUG
