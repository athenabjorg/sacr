QT += core
QT -= gui

CONFIG += c++11

TARGET = ScientistProject
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    consoleui.cpp \
    scientistservice.cpp \
    scientist.cpp \
    dataaccess.cpp \

HEADERS += \
    consoleui.h \
    dataaccess.h \
    scientist.h \
    scientistservice.h
