#ifndef ADMINCONTROLLER_H
#define ADMINCONTROLLER_H

#include"db.h"

class AdminController
{
private:
    DB* db;
public:
    AdminController();
    ~AdminController();
    bool searchUser(const QString&);
    void addUser();
    void removeUser(const Username&);
};

#endif // ADMINCONTROLLER_H
