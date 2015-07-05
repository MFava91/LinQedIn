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
#include<QFile>
#include<QMessageBox>
#include<QFileDialog>

#include"utente.h"
using std::map;

class DB
{
private:
    map<QString,Utente*> dbUtenti; //perchè non ho passato un USERNAME?
public:
    DB();
    QString path;
    map<QString,Utente*>* getDb();
    void addUtente(Username,Utente*);
    void addNewUtente(const QString&, const QString&, const QString&);
    void removeUtete(const QString&);
    void updateUtente(Utente*);
    void upgradeUtente(const QString&, const QString&);
    void updateReteFollower(const QString&,const QString&);
    void removeReteFollower(const QString&,const QString&);
    void save();
    void load();
    bool search(const QString&);
    Utente* find(const QString&) const;
    map<QString,Utente*> findUsername(const InfoSearch&) const;
    ~DB(); //DA FARE

};

#endif // DB_H
