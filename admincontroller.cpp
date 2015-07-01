#include "admincontroller.h"

AdminController::AdminController()
{
    db = new DB();
    db->load();
}

bool AdminController::searchUser(const QString &u){
    bool trovato;
    trovato=db->search(u);
    return trovato;
}

void AdminController::addUser(const QString &u, const QString &n, const QString &c){
    db->addNewUtente(u,n,c);
}

void AdminController::removeUser(const Username& u){
    db->removeUtete(u);
}

map<QString,Utente*> AdminController::findUser(const QString& u, const QString& n, const QString& c){
    utentiTrovati = db->findName(n,c);
    return utentiTrovati;
}

QString AdminController::searchUserType(const QString &u){
    Utente* temp=db->find(u);
    if(typeid(*temp) == typeid(UtenteBasic))
        return "Basic";
    if(typeid(*temp) == typeid(UtenteBusiness))
        return "Business";
    if(typeid(*temp) == typeid(UtenteExecutive))
        return "Executive";
}

void AdminController::modifyUserType(const QString &u, const QString&t){
    db->upgradeUtente(u,t);
}

AdminController::~AdminController(){
}
