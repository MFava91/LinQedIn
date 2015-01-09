#include"xmlinfo.h"
#include <QXmlStreamWriter>
#include<iostream>

using std::cout;
using std::endl;

Xmlinfo::Xmlinfo()
{
}
/*
void GenerateXML::CreateXMLFile()
{
    QFile file("c://contacts.xml");
    //if (!file.open(QFile::ReadOnly | QFile::Text))
    if (!file.open(QIODevice::WriteOnly))
    {
    cout<<"Read only", "The file is in read only mode"<<endl;
    }
    else
    {
        QXmlStreamWriter* xmlWriter = new QXmlStreamWriter();
        xmlWriter->setDevice(&file);
        xmlWriter->writeStartDocument();
        xmlWriter->writeStartElement("persons");
        QMapIterator<QString, QString> i(firstname);
        QMapIterator<QString, QString> j(surname);
        QMapIterator<QString, QString> k(phoneNumber);

        while (i.hasNext() && j.hasNext() && k.hasNext())
        {
            i.next(); j.next();	k.next();
            xmlWriter->writeStartElement("person");
            xmlWriter->writeAttribute(i.key(), i.value());
            xmlWriter->writeAttribute(j.key(), j.value());
            xmlWriter->writeAttribute(k.key(), k.value());
            xmlWriter->writeCharacters ("kamlesh");
            xmlWriter->writeEndElement();

        }

        xmlWriter->writeEndElement();
        xmlWriter->writeEndDocument();
    }
}

GenerateXML::~GenerateXML()
{

}
*/
