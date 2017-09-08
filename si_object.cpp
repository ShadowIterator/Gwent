#include"si_object.h"



SI_Object::SI_Object(QObject* parent):QObject(parent)
{
	properties.clear();
}


SI_String SI_Object::getProperty(const SI_String& propertyName) const
{
	QMap<SI_String,SI_String>::const_iterator it=properties.find(propertyName);
	if(it==properties.end()) return "NoResult";
	return it.value();
}

QMap<SI_String,SI_String>::iterator SI_Object::getBegin()
{
	QMap<SI_String,SI_String>::iterator it=properties.begin();
	return it;
}

QMap<SI_String,SI_String>::iterator SI_Object::getEnd()
{
	return properties.end();
}

void SI_Object::setProperty(const SI_String& propertyName,const SI_String& propertyVal)
{
	//properties[propertyName]=propertyVal;
	properties.insert(propertyName,propertyVal); //if exist,replace
}
