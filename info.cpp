#include "info.h"

Info::Info(const QString& n,const QString& c,const QString& e,const int& t) : nome(n),cognome(c),email(e), telefono(t) {}

QString Info::getnome() const {
    return nome;
}

QString Info::getcognome() const {
    return cognome;
}

QString Info::getemail() const {
    return email;
}

int Info::gettelefono() const {
    return telefono;
}
