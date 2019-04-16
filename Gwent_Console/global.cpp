
#include"global.h"

void __inputQString(QTextStream& in,QString& s)
{
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

SI_String __tofileName(const SI_String& cardName)
{
	SI_String rtn=cardName;
	rtn.replace(":","_");

	return rtn;
}

SI_String __toclassName(const SI_String& cardName)
{
	SI_String rtn=cardName;
	rtn.replace(":","_");
	rtn.replace("'","_");
	return rtn;

}
