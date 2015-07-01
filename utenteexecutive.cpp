#include "utenteexecutive.h"

UtenteExecutive::UtenteExecutive(const QString& u):UtenteBusiness(u){}

UtenteExecutive::UtenteExecutive(const QString& u, const Profilo& p, const Rete& r):
    UtenteBusiness(u,p,r){}

map<QString,Utente*> UtenteExecutive::findUsername(const QString& u){

}

UtenteExecutive::~UtenteExecutive(){
}

