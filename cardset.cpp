#include"cardset.h"

CardSet::CardSet(QObject *parent):SI_Object(parent)
{
	cardSet.clear();
}

void CardSet::reOrder()
{
	vector<Card*> temp;
	temp.assign(cardSet.begin(),cardSet.end());
	std::random_shuffle(temp.begin(),temp.end());
	cardSet.assign(temp.begin(),temp.end());
/*
	list<int> rank(cardSet.size());
	int i=0;
	for()
	std::random_shuffle(cardSet.begin(),cardSet.end());
*/
}

/*
void CardSet::append(const Card& tcard)
{
	cardSet.push_back(&tcard);
}
*/

void CardSet::append(Card* pcard)
{
	cardSet.push_back(pcard);
}

void CardSet::append(Card& tcard)
{
	append(&tcard);
}

void CardSet::erase(Card* pcard)
{
	list<Card*>::iterator it;//=std::find(cardSet.begin(),cardSet.end(),pcard);//cardSet.find(pcard);
	for(it=cardSet.begin();it!=cardSet.end();++it)
		if((*it)==pcard) break;
	if(it!=cardSet.end())
	{
		cardSet.erase(it);
	}
}

void CardSet::erase(Card& tcard)
{
	erase(&tcard);
}

void CardSet::ins(Card* pcard,int order)
{
//
	if(order<0) cardSet.push_back(pcard);
	else if(!order) cardSet.push_front(pcard);
	else cardSet.insert(_getIterator(order),pcard);
}

list<Card*>::iterator CardSet::_getIterator(int index)
{
	if(index<0) return cardSet.end();
	list<Card*>::iterator it=cardSet.begin();
	for(;index&&(it!=cardSet.end());--index) ++it;
	return it;
}
