#ifndef LAVORO_H
#define LAVORO_H

#include<QString>
#include<QDate>

class Lavoro
{
private:
    QString nomeazienda;
    QString titolo;
    QString citta;
    QDate inizio;
    QDate fine;
public:
    Lavoro(const QString&,const QString&,const QString&,const QDate&,const QDate&);
};

#endif // LAVORO_H
