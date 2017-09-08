#ifndef DECLARES_H
#define DECLARES_H

#include<QMap>
#include<list>
#include<vector>
#include<QString>
#include<QtCore>
#include<random>
#include<fstream>
#include<string>
#include<iostream>

#define DEBUG


using std::string;
using std::cin;
using std::ifstream;
using std::map;
using std::list;
using std::vector;

class SI_Object;
class CardSet;
class Card;
class Field;
class Operator;

typedef CardSet Row;
typedef QString SI_String;

void __inputQString(QTextStream& in,QString& s);
int Min(int a,int b);
int Max(int a,int b);

#endif // DECLARES_H
