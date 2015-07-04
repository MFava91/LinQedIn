#include "utentebusiness.h"

UtenteBusiness::UtenteBusiness(const QString& u):UtenteBasic(u){}

UtenteBusiness::UtenteBusiness(const QString& u, const Profilo& p, const Rete& r):
    UtenteBasic(u,p,r){}

map<QString,Utente*> UtenteBusiness::findUsername(const InfoSearch& info, map<QString,Utente*>* db){
    map<QString,Utente*> trovati;
    map<QString,Utente*> basicSearch;
    basicSearch = UtenteBasic::find(info,db);
    for(map<QString,Utente*>::iterator it=basicSearch.begin(); it!=basicSearch.end();++it)
    {
        if(info.getLuogoNascita()!="" && (*it).second->getInfo().getDati().getLuogoNascita() != info.getLuogoNascita())
            continue;
        if(info.getResidenza()!="" && (*it).second->getInfo().getDati().getResidenza() != info.getResidenza())
            continue;
        if(info.getDiploma()!="" && (*it).second->getInfo().getStudi().getDiploma() != info.getDiploma())
            continue;
        if(info.getLauree()!="" && (*it).second->getInfo().getStudi().getLaurea().size()>0){
            bool trovato=false;
            for (int i=0;i<(*it).second->getInfo().getStudi().getLaurea().size() && trovato==false;i++) {
               if(info.getLauree()==(*it).second->getInfo().getStudi().getLaurea()[i])
                   trovato=true;
            }
            if(!trovato)
                continue;
        }
        trovati.insert(std::pair<QString,Utente*>((*it).first,(*it).second));
    }
    return trovati;
}

UtenteBusiness::~UtenteBusiness(){}
