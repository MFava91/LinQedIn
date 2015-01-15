#include "utente.h"


Utente::Utente() {
    QString i;
    i=info.datiPersonali.getNome();
}

Utente::Utente(const Username& u):login(u) {}

void Utente::upaddFollow(Utente u){
    rete.addFollow(u.login);
    u.rete.addFollower(login);
}

void Utente::upremoveFollow(Utente u){
    rete.removeFollow(u.login);
    u.rete.removeFollower(login);
}

//Utente::~Utente() {}
