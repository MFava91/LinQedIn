#include "utentebasic.h"

UtenteBasic::UtenteBasic(const QString &u):Utente(u){}

UtenteBasic::UtenteBasic(const QString &u, const Profilo& p, const Rete& r):
    Utente(u,p,r){}


map<QString,Utente*> UtenteBasic::findUsername(const QString& u){

}

UtenteBasic::~UtenteBasic(){}
