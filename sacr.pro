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
    service.cpp \
    addscientistwindow.cpp \
    addcomputerwindow.cpp \
    addrelationwindow.cpp \
    scientistwindow.cpp \
    computerwindow.cpp

HEADERS  += mainwindow.h \
    computer.h \
    consoleui.h \
    dataaccess.h \
    relation.h \
    scientist.h \
    scientistservice.h \
    service.h \
    addscientistwindow.h \
    addcomputerwindow.h \
    addrelationwindow.h \
    scientistwindow.h \
    computerwindow.h

FORMS    += mainwindow.ui \
    addscientistwindow.ui \
    addcomputerwindow.ui \
    addrelationwindow.ui \
    scientistwindow.ui \
    computerwindow.ui

DISTFILES +=
