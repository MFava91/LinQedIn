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
    /*
    QString nome,cognome,email,lnascita,residenza,nome2;
    QDate dnascita(1992,2,1);
    nome="Enrico";
    nome2="CERYYYYYYYYYYYYYYYY";
    cognome="Infinity";
    email="einfinity@houncazzoenorme.com";
    lnascita="TrevisoLammoda";
    residenza="CazzoVoglio";
    DatiAnagrafici a(nome,cognome,email,dnascita,lnascita,residenza);
    DatiAnagrafici a2(nome2,cognome,email,dnascita,lnascita,residenza);


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
    Profilo p,p2;
    p.datiPersonali=a;
    p.studi=b;
    p.curriculum=c;

    p2.datiPersonali=a2;
    p2.studi=b;
    p2.curriculum=c;

    QString user,user2;
    user="Infinityplusplus";
    user2="MONAAAAAAAAAAAAA";
    Username us(user);
    Username us2(user2);

    Utente u,u2;
    u.info=p;
    u.login=us;

    u2.info=p2;
    u2.login=us2;
    u.rete.addFollow(us2);
    Username us3("mariomariomario");
    u.rete.addFollow(us3);


    Utente *punt=&u;
    Utente *punt2=&u2;
    */
    //SCRIVO NEL DB

    DB db;
    /*
    db.addUtente(u.login,punt);
    db.addUtente(u2.login,punt2);
    //db.removeUtete(u.login);
    set<QString>::const_iterator it=u.rete.getFollow().begin();
    QString prova=*it;
    */
    db.load();
    db.save();

    return 0;
}
