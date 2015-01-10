#include"xmlinfo.h"
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QFile>
#include<iostream>

using std::cout;
using std::endl;
using std::string;

Xmlinfo::Xmlinfo(Info a)
{
    QFile file("/home/mattia/Documenti/Linquedln/info.xml");
    //if (!file.open(QFile::ReadOnly | QFile::Text))
    if (!file.open(QIODevice::WriteOnly))
    {
    cout<<"Read only, The file is in read only mode"<<endl;
    }
    else
    {
        QXmlStreamWriter stream(&file);
        stream.setAutoFormatting(true);
        stream.writeStartDocument();
        stream.writeStartElement("Info");
        stream.writeTextElement("Nome", a.getnome());
        stream.writeTextElement("Cognome", a.getcognome());
        stream.writeTextElement("Email", a.getemail());
        stream.writeEndElement();
        stream.writeEndDocument();
        /*
        QXmlStreamWriter* xmlWriter = new QXmlStreamWriter();
        xmlWriter->setDevice(&file);
        xmlWriter->setAutoFormatting(true);
        xmlWriter.writeStartDocument();
        xmlWriter.writeStartElement("info");
        stream.writeStartElement("bookmark");
             stream.writeAttribute("href", "http://qt.nokia.com/");
             stream.writeTextElement("title", "Qt Home");
             stream.writeEndElement(); // bookmark

        xmlWriter->writeEndElement();
        xmlWriter->writeEndDocument();
        */
    }
}
void Xmlinfo::Xmlread() {
    QFile file("/home/mattia/Documenti/Linquedln/info.xml");
    QXmlStreamReader xml(&file);
    bool open = file.open(QIODevice::ReadOnly | QIODevice::Text);
    if (!open)
    {
        cout << "Couldn't open file" << endl;
        return;
    }
    else
    {
        cout << "File opened OK" << endl;
    }

    while (!xml.atEnd() && !xml.hasError())
    {
        xml.readNext();
        if (xml.isStartElement())
        {
            QString name = xml.name().toString();
            if (name == "Nome" || name == "Cognome" ||
                name == "Email")
            {
                cout << "element name: '" << name.toStdString()  << "'"
                             << ", text: '" << (xml.readElementText()).toStdString()
                             << "'" << endl;
            }
        }
    }
    /*
     * if (xml.hasError())
    {
        cout << "XML error: " << xml.errorString() << endl;
    }
    else if (xml.atEnd())
    {
        cout << "Reached end, done" << endl;
    }
    */
}

