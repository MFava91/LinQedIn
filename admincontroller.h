#ifndef ADMINCONTROLLER_H
#define ADMINCONTROLLER_H

#include<typeinfo>
#include"db.h"
#include"controller.h"
#include"utenteexecutive.h"
class AdminController : public virtual Controller {
private:
    DB* db;
public:
    UtenteExecutive* user;
    map<QString,Utente*> utentiTrovati;
    AdminController();
    ~AdminController();
    bool searchUser(const QString&);
    void addUser(const QString&, const QString&, const QString&);
    void removeUser(const Username&);
    map<QString,Utente*> findUser(const InfoSearch&);
    Utente* findUserForUsername(const QString&);
    QString searchUserType(const QString&);
    void modifyUserType(const QString&,const QString&);
    virtual QString tipoUtente() const;
    virtual void updateReteContatti(const QString&);
    virtual void removeReteContatti(const QString&);
    virtual bool checkUtenteRete(const QString&);
    virtual QString getUsername() const;
    void saveDatabase();
};

#endif // ADMINCONTROLLER_H
