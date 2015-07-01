#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H

#include"db.h"
#include"controller.h"

class userController : public virtual Controller{
private:
    DB* db;
public:
    Utente* user;
    map<QString,Utente*> utentiTrovati;
    //metodi
    userController(const QString&);
    void loadUser(const QString&);
    void updateUserInfo(const DatiAnagrafici&);
    void updateUserDiploma(const TitoliStudio&);
    void updateUserLaurea(const QString&, const QString&);
    void updateUserLavoro(const Lavoro&,const Lavoro&);
    void saveDatabase();
    bool searchUser(const QString&);
    bool searchLaurea(const QString&);
    map<QString,Utente*> findUser(const QString& =0, const QString& =0, const QString& =0);
    ~userController();
};

#endif // USERCONTROLLER_H
