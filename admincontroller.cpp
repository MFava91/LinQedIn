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

void AdminController::removeUser(const Username& u){
    db->removeUtete(u);
}



AdminController::~AdminController(){
}
