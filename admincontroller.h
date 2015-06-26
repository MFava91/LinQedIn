#ifndef ADMINCONTROLLER_H
#define ADMINCONTROLLER_H

#include"db.h"

class AdminController
{
private:
    DB* db;
public:
    Utente* user;
    AdminController();
    ~AdminController();
    bool searchUser(const QString&);
    void addUser();
    void removeUser(const Username&);
    bool findUserForUsername(const QString&);
    Utente* findUserForName(const QString& =0, const QString& =0);
};

#endif // ADMINCONTROLLER_H
