TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    info.cpp \
    profilo.cpp \
    rete.cpp \
    username.cpp \
    utente.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    info.h \
    profilo.h \
    rete.h \
    username.h \
    utente.h

