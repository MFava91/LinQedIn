#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H

#include"db.h"

class userController
{
private:
    DB* db;
public:
    Utente* user;

    //metodi
    userController(const QString&, DB* = 0);
    void loadUser(const QString&);
    void updateUserInfo(const DatiAnagrafici&);
    void updateUserDiploma(const TitoliStudio&);
    void updateUserLaurea(const QString&, const QString&);
    void updateUserLavoro(const Lavoro&,const Lavoro&);
    void saveDatabase();
    bool searchUser(const QString&);
    bool searchLaurea(const QString&);
};

#endif // USERCONTROLLER_H
