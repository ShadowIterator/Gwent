
#include"global.h"
void __inputQString(QTextStream& in,QString& s)
{
//	string temp;
//	in>>temp;
//	s=QString::fromStdString(temp);
	in>>s;
}


int Min(int a,int b)
{
	return a<b?a:b;
}

int Max(int a,int b)
{
	return a>b?a:b;
}

