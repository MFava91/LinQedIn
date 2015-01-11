#include"xmlinfo.h"
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QFile>
#include <QTextStream>
#include<iostream>

using std::cout;
using std::endl;
using std::string;

Xmlinfo::Xmlinfo(Info a)
{
    QString path("/home/mattia/Documenti/Linquedln/info.xml");
    QFile file(path);
    qint64 s = file.size();
    if (s > 0) {
        file.open(QFile::ReadWrite);
        if (file.seek(s))
            Q_ASSERT(file.pos() == s);

    } else
        file.open(QFile::WriteOnly);

    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);

    if (s == 0) {
        xmlWriter.writeStartDocument();
    }

    xmlWriter.writeStartElement("info");
    xmlWriter.writeTextElement("Nome", a.getnome());
    xmlWriter.writeTextElement("Cognome", a.getcognome());
    xmlWriter.writeTextElement("Email", a.getemail());
    xmlWriter.writeEndElement();

    if (s == 0) {
        xmlWriter.writeEndDocument();
    }
}



//LEGGE
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

