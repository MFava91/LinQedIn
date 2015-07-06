#include "infosearch.h"

InfoSearch::InfoSearch(const QString& user, const QString& n, const QString& c,
                       const QString& ln, const QString& r, const QString& d,
                       const QString& l,const QString& w, const QString& t):
    username(user),nome(n),cognome(c),
    luogoNascita(ln),residenza(r),diploma(d),
    laurea(l),lavoro(w),titolo(t){}

void InfoSearch::setUsername(const QString& user){
    username = user;
}

void InfoSearch::setNome(const QString& n){
    nome = n;
}

void InfoSearch::setCognome(const QString& c){
    cognome = c;
}

void InfoSearch::setLuogoNascita(const QString& ln){
    luogoNascita = ln;
}

void InfoSearch::setResidenza(const QString& r){
    residenza = r;
}

void InfoSearch::setDiploma(const QString& d){
    diploma = d;
}

void InfoSearch::setLaurea(const QString& l){
    laurea = l;
}

void InfoSearch::setAzienda(const QString& w){
    lavoro = w;
}

void InfoSearch::setTitolo(const QString &t){
    titolo = t;
}

QString InfoSearch::getUsername() const{
    return username;
}

QString InfoSearch::getNome() const{
    return nome;
}

QString InfoSearch::getCognome() const{
    return cognome;
}

QString InfoSearch::getLuogoNascita() const{
    return luogoNascita;
}

QString InfoSearch::getResidenza() const{
    return residenza;
}

QString InfoSearch::getDiploma() const{
    return diploma;
}

QString InfoSearch::getLauree() const{
    return laurea;
}

QString InfoSearch::getAzienda() const{
    return lavoro;
}

QString InfoSearch::getTitolo() const{
    return titolo;
}
