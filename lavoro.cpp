#include "lavoro.h"

Lavoro::Lavoro(const QString& a,const QString& t,const QString& c,const QDate& i,const QDate& f):
    nomeazienda(a),titolo(t),citta(c),inizio(i)
{
    if(!f.isNull())
        fine=f;
}
