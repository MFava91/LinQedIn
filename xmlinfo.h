#ifndef XMLINFO_H
#define XMLINFO_H

#include"info.h"

class Xmlinfo
{
public:
    Xmlinfo(Info);
    void Xmlread();
};

/*
class GenerateXML : public QMainWindow
{
    Q_OBJECT

public:
    GenerateXML(QWidget *parent = 0);
    ~GenerateXML();
    void CreateXMLFile();

private:
    Ui::GenerateXMLClass ui;
    QMap<QString,QString> firstname;
    QMap<QString,QString> surname;
    QMap<QString,QString> phoneNumber;
};
*/

#endif // XMLINFO_H
