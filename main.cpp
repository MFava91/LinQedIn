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
    QString n,c,e;
    n="mario";
    c="rossi";
    e="mario@gmail.com";
    Info a(n,c,e,12345);
    Xmlinfo b(a);
    return 0;
}
