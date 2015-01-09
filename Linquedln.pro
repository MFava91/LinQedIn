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
    xmlinfo.cpp

HEADERS  += mainwindow.h \
    info.h \
    profilo.h \
    rete.h \
    username.h \
    utente.h \
    xmlinfo.h

FORMS    += mainwindow.ui


