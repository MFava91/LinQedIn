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
    map<QString,Utente*> dbUtenti;
public:
    DB();
    void addUtente(Username,Utente*);
    void removeUtete(Username);
    void save();
    /*void load() {}
    void save() const {}
    Utente* find(Username u){
        return new Utente(u);
    }
    */
};

#endif // DB_H
