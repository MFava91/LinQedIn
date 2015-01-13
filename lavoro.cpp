#include "lavoro.h"

Lavoro::Lavoro(const QString& a,const QString& t,const QString& c,const QDate& i,const QDate& f):
    nomeazienda(a),titolo(t),citta(c),inizio(i)
{
    if(!f.isNull())
        fine=f;
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
