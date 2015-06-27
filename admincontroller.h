#ifndef ADMINCONTROLLER_H
#define ADMINCONTROLLER_H

#include"db.h"

class AdminController
{
private:
    DB* db;
public:
    Utente* user;
    map<QString,Utente*> utentiTrovati;
    AdminController();
    ~AdminController();
    bool searchUser(const QString&);
    void addUser(const QString&, const QString&, const QString&);
    void removeUser(const Username&);
    bool findUserForUsername(const QString&);
    bool findUserForName(const QString& =0, const QString& =0);
};

#endif // ADMINCONTROLLER_H
