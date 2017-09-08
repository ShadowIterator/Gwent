#ifndef SI_OBJECT_H
#define SI_OBJECT_H

#include"global.h"

class SI_Object:public QObject
{
	Q_OBJECT
//private:
//public:
public:
	QMap<SI_String,SI_String> properties; //no "place"
public:
	//SI_Object();
	SI_Object(QObject *parent=0);
	SI_String getProperty(const SI_String&) const;

	QMap<SI_String,SI_String>::iterator getBegin();
	QMap<SI_String,SI_String>::iterator getEnd();

public slots:
	void setProperty(const SI_String&,const SI_String&);
#ifdef DEBUG

	void ___print_properties()
	{
		for(QMap<SI_String,SI_String>::iterator it=properties.begin();it!=properties.end();++it)
		{
			qDebug()<<it.key()<<" : "<<it.value()<<endl;
		}
	}

#endif //DEBUG
};



#endif // SI_OBJECT_H
