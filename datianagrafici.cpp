#include "datianagrafici.h"

DatiAnagrafici::DatiAnagrafici() {}
DatiAnagrafici::DatiAnagrafici(const QString& n,const QString& c,const QString& e,const QDate& d,const QString& l,const QString& r):nome(n),cognome(c),email(e),dataNascita(d),luogoNascita(l),residenza(r){}

QString DatiAnagrafici::getNome() const {
    return nome;
}

QString DatiAnagrafici::getCognome() const {
    return cognome;
}

QString DatiAnagrafici::getEmail() const {
    return email;
}

QDate DatiAnagrafici::getDataNascita() const {
    return dataNascita;
}


QString DatiAnagrafici::getLuogoNascita() const {
    return luogoNascita;
}

QString DatiAnagrafici::getResidenza() const {
    return residenza;
}

void DatiAnagrafici::setNome(const QString& x) {
    nome=x;
}
void DatiAnagrafici::setCognome(const QString& x) {
    cognome=x;
}
void DatiAnagrafici::setEmail(const QString& x) {
    email=x;
}
void DatiAnagrafici::setDataNascita(const QDate& x) {
    dataNascita=x;
}
void DatiAnagrafici::setLuogoNascita(const QString& x) {
    luogoNascita=x;
}
void DatiAnagrafici::setResidenza(const QString& x) {
    residenza=x;
}

