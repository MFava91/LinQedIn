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

bool AdminController::findUserForUsername(const QString &u){
    user = db->find(u);
    if(user)
        return true;
    return false;
}

bool AdminController::findUserForName(const QString& n, const QString& c){
    utentiTrovati = db->findName(n,c);
    if(!utentiTrovati.empty())
        return true;
    return false;
}

AdminController::~AdminController(){
}
