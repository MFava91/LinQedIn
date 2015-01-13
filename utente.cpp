#include "utente.h"

Utente::Utente() {
    QString i;
    i=info.datiPersonali.getNome();
}

Utente::Utente(const Username& u):login(u) {}

Utente::~Utente() {}
