#include "utentebusiness.h"

UtenteBusiness::UtenteBusiness(const QString& u):UtenteBasic(u){}

UtenteBusiness::UtenteBusiness(const QString& u, const Profilo& p, const Rete& r):
    UtenteBasic(u,p,r){}

map<QString,Utente*> UtenteBusiness::findUsername(const QString& u){

}

UtenteBusiness::~UtenteBusiness(){}
