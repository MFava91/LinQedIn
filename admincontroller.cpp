#include "admincontroller.h"
#include"utentebasic.h"
#include"utentebusiness.h"
#include"utenteexecutive.h"

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
    db->removeUtete(u.getUsername());
}

map<QString,Utente*> AdminController::findUser(const InfoSearch& info){
    return db->findUsername(info);
}

Utente* AdminController::findUserForUsername(const QString &u){
    return db->find(u);
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

QString AdminController::tipoUtente() const{
    return "Admin";
}

void AdminController::updateReteContatti(const QString&){}
void AdminController::removeReteContatti(const QString&) {}
bool AdminController::checkUtenteRete(const QString&){}

QString AdminController::getUsername() const{
    return "Admin";
}

void AdminController::saveDatabase(){
    db->save();
}

AdminController::~AdminController(){
}
