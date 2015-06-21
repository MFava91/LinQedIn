#-------------------------------------------------
#
# Project created by QtCreator 2015-01-09T12:00:48
#
#-------------------------------------------------

QT       += core gui
LIBS += -lGL

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Linquedln
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    info.cpp \
    profilo.cpp \
    rete.cpp \
    username.cpp \
    utente.cpp \
    datianagrafici.cpp \
    titolistudio.cpp \
    competenzelavorative.cpp \
    lavoro.cpp \
    utentebasic.cpp \
    utentebusiness.cpp \
    utenteexecutive.cpp \
    db.cpp \
    adminwindow.cpp \
    userwindow.cpp \
    usercontroller.cpp \
    userinfowindow.cpp \
    userschoolwindow.cpp \
    laureawindow.cpp

HEADERS  += mainwindow.h \
    info.h \
    profilo.h \
    rete.h \
    username.h \
    utente.h \
    datianagrafici.h \
    titolistudio.h \
    competenzelavorative.h \
    lavoro.h \
    utentebasic.h \
    utentebusiness.h \
    utenteexecutive.h \
    db.h \
    adminwindow.h \
    userwindow.h \
    usercontroller.h \
    userinfowindow.h \
    userschoolwindow.h \
    laureawindow.h

FORMS    += mainwindow.ui


