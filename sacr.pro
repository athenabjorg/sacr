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
    dataaccess.cpp \
    relation.cpp \
    scientist.cpp \
    service.cpp \
    addscientistwindow.cpp \
    addcomputerwindow.cpp \
    addrelationwindow.cpp \
    computerwindow.cpp \
    scientistwindow.cpp \
    usermanual.cpp \
    updatescientistwindow.cpp

HEADERS  += mainwindow.h \
    computer.h \
    dataaccess.h \
    relation.h \
    scientist.h \
    service.h \
    addscientistwindow.h \
    addcomputerwindow.h \
    addrelationwindow.h \
    scientistwindow.h \
    computerwindow.h \
    usermanual.h \
    updatescientistwindow.h

FORMS    += mainwindow.ui \
    addscientistwindow.ui \
    addcomputerwindow.ui \
    addrelationwindow.ui \
    scientistwindow.ui \
    computerwindow.ui \
    usermanual.ui \
    updatescientistwindow.ui

DISTFILES +=
