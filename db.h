#ifndef DB_H
#define DB_H

#include<iostream>
#include<QString>
#include<map>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QFile>
#include <QTextStream>
#include<typeinfo>

#include"utente.h"
using std::map;

class DB
{
private:
    map<QString,Utente*> dbUtenti; //perchè non ho passato un USERNAME?
public:
    DB();
    map<QString,Utente*>* getDb();
    void addUtente(Username,Utente*);
    void addNewUtente(const QString&, const QString&, const QString&);
    void removeUtete(Username);
    void updateUtente(Utente*);
    void upgradeUtente(const QString&, const QString&);
    void updateReteFollower(const QString&,const QString&);
    void removeReteFollower(const QString&,const QString&);
    void save();
    void load();
    bool search(const QString&);
    Utente* find(const QString&) const;
    map<QString,Utente*> findName(const QString&, const QString&) const;
    ~DB(); //DA FARE

};

#endif // DB_H
