#ifndef CONTROLLER_H
#define CONTROLLER_H
#include<QString>
#include<map>
#include"utente.h"

using std::map;

class Controller
{
public:
    Controller();
    virtual ~Controller() = 0;
    virtual bool searchUser(const QString&) =0;
    virtual map<QString,Utente*> findUser(const InfoSearch&) = 0;
    virtual QString tipoUtente() const = 0;
    virtual void updateReteContatti(const QString&) = 0;
    virtual void removeReteContatti(const QString&) = 0;
    virtual bool checkUtenteRete(const QString&) = 0;
    virtual QString getUsername() const = 0;
};

#endif // CONTROLLER_H
