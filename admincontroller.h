#ifndef ADMINCONTROLLER_H
#define ADMINCONTROLLER_H

#include"db.h"
#include"controller.h"

class AdminController : public virtual Controller {
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
    Utente* findUserForUsername(const QString&);
    map<QString,Utente*> findUserForName(const QString& =0, const QString& =0);
    QString searchUserType(const QString&);
    void modifyUserType(const QString&,const QString&);
};

#endif // ADMINCONTROLLER_H
