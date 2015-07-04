#include "utenteexecutive.h"

UtenteExecutive::UtenteExecutive(const QString& u):UtenteBusiness(u){}

UtenteExecutive::UtenteExecutive(const QString& u, const Profilo& p, const Rete& r):
    UtenteBusiness(u,p,r){}

map<QString,Utente*> UtenteExecutive::find(const InfoSearch& info, map<QString,Utente*>* db){
    map<QString,Utente*> trovati;
    map<QString,Utente*> businessSearch;
    businessSearch = UtenteBusiness::find(info,db);
    for(map<QString,Utente*>::iterator it=businessSearch.begin(); it!=businessSearch.end();++it)
    {
        if((info.getAzienda()!="" || info.getTitolo()!="") && (*it).second->getInfo().getLavori().getEsperienze().size()>0){
            bool trovato=false;
            for (int i=0;i<(*it).second->getInfo().getLavori().getEsperienze().size() && trovato==false;i++) {
               if(info.getAzienda()!="" && info.getTitolo()=="" && info.getAzienda()==(*it).second->getInfo().getLavori().getEsperienze()[i].getAzienda())
                   trovato=true;
               if(info.getAzienda()=="" && info.getTitolo()!="" && info.getTitolo()==(*it).second->getInfo().getLavori().getEsperienze()[i].getTitolo())
                   trovato=true;
               if(info.getAzienda()!="" && info.getTitolo()!="" && info.getAzienda()==(*it).second->getInfo().getLavori().getEsperienze()[i].getAzienda() &&
                       info.getTitolo()==(*it).second->getInfo().getLavori().getEsperienze()[i].getTitolo())
                   trovato=true;
            }
            if(!trovato)
                continue;
        }
        trovati.insert(std::pair<QString,Utente*>((*it).first,(*it).second));
    }
    return trovati;
}

UtenteExecutive::~UtenteExecutive(){
}

