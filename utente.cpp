#include "utente.h"

Utente::Utente() {
    QString i;
    i=info.getDati().getNome();
}

Utente::Utente(const Username& u):login(u) {}

Utente::Utente(const Username& u, const Profilo& p, const Rete& r):
    login(u),info(p),rete(r) {}

Username Utente::getLogin() const{
    return login;
}

Profilo& Utente::getInfo(){
    return info;
}

Rete Utente::getRete() const {
    return rete;
}

void Utente::aggiungiUtenteRete(const QString &u){
    rete.addFollow(u);
}

void Utente::rimuoviUteteRete(const QString&u){
    rete.removeFollow(u);
}

Utente::~Utente() {}
