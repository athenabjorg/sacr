#-------------------------------------------------
#
# Project created by QtCreator 2016-12-12T20:53:09
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sacr
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    computer.cpp \
    consoleui.cpp \
    dataaccess.cpp \
    relation.cpp \
    scientist.cpp \
    scientistservice.cpp \
    service.cpp

HEADERS  += mainwindow.h \
    computer.h \
    consoleui.h \
    dataaccess.h \
    relation.h \
    scientist.h \
    scientistservice.h \
    service.h

FORMS    += mainwindow.ui

DISTFILES += \
    sacr.pro.user
