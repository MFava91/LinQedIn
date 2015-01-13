#include "mainwindow.h"
#include <QApplication>

#include"utente.h"
#include"xmlinfo.h"
#include"db.h"
int main(/*int argc, char *argv[]*/)
{
    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    //return a.exec();
    /*QString n,c,c2,e;
    n="mario";
    c="rossi";
    c2="menego";
    e="mario@gmail.com";
    Info a(n,c,e,12345);
    Info prova(n,c2,e,34544);
    Xmlinfo b(a);
    Xmlinfo d(prova);
    b.Xmlread();
    */
    //PROVA SCRITTURA SU FILE XML
    QString nome,cognome,email,lnascita,residenza;
    QDate dnascita(1992,2,1);
    nome="Enrico";
    cognome="Infinity";
    email="einfinity@houncazzoenorme.com";
    lnascita="TrevisoLammoda";
    residenza="CazzoVoglio";
    DatiAnagrafici a(nome,cognome,email,dnascita,lnascita,residenza);

    QString diploma,laurea;
    diploma="infinito";
    laurea="tutte";
    TitoliStudio b(diploma,laurea);

    QString azienda,titolo,citta;
    QDate inizio(2012,1,1);
    QDate fine(2012,1,2);
    azienda="infinitech";
    titolo="CEO";
    citta="Treviso";
    Lavoro l(azienda,titolo,citta,inizio,fine);
    CompetenzeLavorative c(l);
    Profilo p;
    p.datiPersonali=a;
    p.studi=b;
    p.curriculum=c;

    QString user;
    user="Infinityplusplus";
    Username us(user);

    Utente u;
    u.info=p;
    u.login=us;
    Utente *punt=&u;

    //SCRIVO NEL DB
    DB db;
    db.addUtente(u.login,punt);
    db.save();
    return 0;
}
