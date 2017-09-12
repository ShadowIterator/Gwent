#ifndef DECLARES_H
#define DECLARES_H

#include<set>
#include<QMap>
#include<list>
#include<vector>
#include<QString>
#include<QtCore>
#include<random>
#include<fstream>
#include<string>
#include<iostream>
#include<QMetaType>

#define DEBUG


using std::string;
using std::cin;
using std::set;
using std::ifstream;
using std::map;
using std::list;
using std::vector;

class SI_Object;
class CardSet;
class Card;
class Weather;
class Field;
class FlowControl;
class Game;

typedef CardSet Row;
typedef QString SI_String;

const SI_String noinfo="";

void __inputQString(QTextStream& in,QString& s);
int Min(int a,int b);
int Max(int a,int b);
SI_String __tofileName(const SI_String&);
SI_String __toclassName(const SI_String&);

const int MAX_ROUND_NUM=3;
const int INF=999;
const int MAX_TEAM_NUM=2;
const int MAX_ROW_NUM=3;
const int MAX_CARD_NUM=400;
const int SPELL=0;
const int MINION=1;

const int ROWNUM_CLOSE=0;
const int ROWNUM_MIDDLE=1;
const int ROWNUM_FAR=2;

const int FLAG_CLOSE=1<<ROWNUM_CLOSE;
const int FLAG_MIDDLE=1<<ROWNUM_MIDDLE;
const int FLAG_FAR=1<<ROWNUM_FAR;

#endif // DECLARES_H
