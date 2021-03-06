#ifndef UTENTE_H
#define UTENTE_H
#include<map>
#include"rete.h"
#include"profilo.h"
#include"infosearch.h"
using std::map;

class Utente
{
private:
    Username login;
    Profilo info;
    Rete rete;
public:
    Utente();
    Utente(const Username&);
    Utente(const Username&, const Profilo&, const Rete&);
    Username getLogin() const;
    Profilo& getInfo();
    Rete getRete() const;
    void aggiungiUtenteRete(const QString&);
    void rimuoviUteteRete(const QString&);
    virtual map<QString,Utente*> find(const InfoSearch&,map<QString,Utente*>*) =0;
    virtual ~Utente() =0;
};


#endif // UTENTE_H
