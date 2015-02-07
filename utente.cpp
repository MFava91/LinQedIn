#include "utente.h"

Utente::Utente() {
    QString i;
    i=info.getDati().getNome();
}

Utente::Utente(const Username& u):login(u) {}

Username Utente::getLogin() const{
    return login;
}

Profilo Utente::getInfo() const{
    return info;
}

Rete Utente::getRete() const {
    return rete;
}

//Utente::~Utente() {}
