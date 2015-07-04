#include "utentebasic.h"

UtenteBasic::UtenteBasic(const QString &u):Utente(u){}

UtenteBasic::UtenteBasic(const QString &u, const Profilo& p, const Rete& r):
    Utente(u,p,r){}


map<QString,Utente*> UtenteBasic::find(const InfoSearch& info,map<QString, Utente*>* db){
    map<QString,Utente*> trovati;
    for(map<QString,Utente*>::iterator it=db->begin(); it!=db->end();++it)
    {
        if(info.getUsername()!="" && (*it).first != info.getUsername())
            continue;
        if(info.getNome()!="" && (*it).second->getInfo().getDati().getNome() != info.getNome())
            continue;
        if(info.getCognome()!="" && (*it).second->getInfo().getDati().getCognome() != info.getCognome())
            continue;
        trovati.insert(std::pair<QString,Utente*>((*it).first,(*it).second));
    }
    return trovati;
}

UtenteBasic::~UtenteBasic(){}
