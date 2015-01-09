#include "info.h"

Info::Info(const string& n,const string& c,const string& e) : nome(n),cognome(c),email(e) {}

string Info::getnome() const {
    return nome;
}

string Info::getcognome() const {
    return cognome;
}

string Info::getemail() const {
    return email;
}
