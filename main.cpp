#include "mainwindow.h"
#include <QApplication>
#include <QStyle>
#include <QDesktopWidget>
#include "utente.h"
#include"db.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-w.width()) / 2;
    int y = (screenGeometry.height()-w.height()) / 2;
    w.move(x, y);
    w.show();
    return a.exec();
}

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
    //DatiAnagrafici a2(nome2,cognome,email,dnascita,lnascita,residenza);


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
    Profilo p(a,b,c);

    QString user;
    user="mario";
    Username us(user);

    Utente u;
    u.info=p;
    u.login=us;

    Username us3("mariomariomario");
    u.rete.addFollow(us3);

    Utente *punt=&u;
    //SCRIVO NEL DB

    DB db;
    db.addUtente(u.login,punt);
    //db.removeUtete(u.login);
//    set<QString>::const_iterator it=u.rete.getFollow().begin();
//    QString prova=*it;
//    db.load();
    db.save();

    return 0;
}
*/
