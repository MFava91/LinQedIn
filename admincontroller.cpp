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

Utente* AdminController::findUserForUsername(const QString &u){
    user = db->find(u);
    return user;
}

map<QString,Utente*> AdminController::findUserForName(const QString& n, const QString& c){
    utentiTrovati = db->findName(n,c);
    return utentiTrovati;
}

QString AdminController::searchUserType(const QString &u){
    Utente* temp=db->find(u);
    return temp->getInfo().getTipoAccount();
}

void AdminController::modifyUserType(const QString &u, const QString&t){
    db->upgradeUtente(u,t);
}

AdminController::~AdminController(){
}
