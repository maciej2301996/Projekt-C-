#-------------------------------------------------
#
# Project created by QtCreator 2017-01-07T14:50:33
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Dziennik
TEMPLATE = app


SOURCES += main.cpp\
        school.cpp \
    interfaceelement1.cpp \
    interfaceelement2.cpp \
    interfaceelement3.cpp \
    input.cpp \
    funkcje.cpp \
    przyciskclasswindow.cpp \
    lista.cpp \
    logowanie.cpp

HEADERS  += school.h \
    interfaceelement1.h \
    interfaceelement2.h \
    interfaceelement3.h \
    input.h \
    funkcje.h \
    przyciskclasswindow.h \
    lista.h \
    logowanie.h

FORMS    += school.ui
