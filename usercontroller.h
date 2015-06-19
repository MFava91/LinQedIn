#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H

#include"db.h"

class userController
{
public:
    Utente* user;
    DB* db;

    //metodi
    userController(const QString&, DB* = 0);
    void loadUser(const QString&);
    void updateUserInfo(const DatiAnagrafici&);
};

#endif // USERCONTROLLER_H
