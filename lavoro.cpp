#include "lavoro.h"

Lavoro::Lavoro(){

}

Lavoro::Lavoro(const QString& a,const QString& t,const QString& c,const QDate& i,const QDate& f):
    nomeazienda(a),titolo(t),citta(c),inizio(i)
{
    if(!f.isNull())
        fine=f;
}

Lavoro Lavoro::operator =(const Lavoro& a){
    nomeazienda=a.nomeazienda;
    titolo=a.titolo;
    citta=a.citta;
    inizio=a.inizio;
    fine=a.fine;
    return *this;
}

bool Lavoro::operator ==(const Lavoro& l){
    return (nomeazienda==l.nomeazienda && titolo==l.titolo && citta==l.citta
            && inizio==l.inizio && fine==l.fine);
}

QString Lavoro::getAzienda() const{
    return nomeazienda;
}

QString Lavoro::getTitolo() const{
    return titolo;
}

QString Lavoro::getCitta() const{
    return citta;
}

QDate Lavoro::getInizio() const{
    return inizio;
}

QDate Lavoro::getFine() const{
    return fine;
}
