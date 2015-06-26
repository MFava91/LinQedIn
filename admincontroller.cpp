#include "admincontroller.h"

AdminController::AdminController()
{
    user=0;
    db = new DB();
    db->load();
}

bool AdminController::searchUser(const QString &u){
    bool trovato;
    trovato=db->search(u);
    return trovato;
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


AdminController::~AdminController(){
}
