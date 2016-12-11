#-------------------------------------------------
#
# Project created by QtCreator 2016-11-30T17:32:01
#
#-------------------------------------------------

QT       += core gui
QT       += sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjektCPP
TEMPLATE = app


SOURCES += main.cpp\
        school.cpp \
    addfunction.cpp \
    teacher.cpp

HEADERS  += school.h \
    addfunction.h \
    teacher.h

FORMS    += school.ui \
    mainwindow.ui
