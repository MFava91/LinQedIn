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
    virtual map<QString,Utente*> findUser(const QString& =0, const QString& =0, const QString& =0) = 0;
};

#endif // CONTROLLER_H
