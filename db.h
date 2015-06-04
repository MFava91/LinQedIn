#ifndef DB_H
#define DB_H

#include<iostream>
#include<QString>
#include<map>
#include"utente.h"

#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QFile>
#include <QTextStream>

using std::map;

class DB
{
private:
    map<QString,Utente*> dbUtenti; //perchè non ho passato un USERNAME?
public:
    DB();
    void addUtente(Username,Utente*);
    void removeUtete(Username);
    void save();
    void load();
    ~DB(); //DA FARE
    Utente* find(const QString&);

};

#endif // DB_H
