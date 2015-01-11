#include "mainwindow.h"
#include <QApplication>

#include"info.h"
#include"xmlinfo.h"
int main(/*int argc, char *argv[]*/)
{
    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    //return a.exec();
    QString n,c,c2,e;
    n="mario";
    c="rossi";
    c2="menego";
    e="mario@gmail.com";
    Info a(n,c,e,12345);
    Info prova(n,c2,e,34544);
    Xmlinfo b(a);
    Xmlinfo d(prova);
    b.Xmlread();
    return 0;
}
