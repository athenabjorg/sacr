QT += core
QT -= gui
QT += core gui sql

CONFIG += c++11

TARGET = ScientistProject
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    consoleui.cpp \
    scientist.cpp \
    dataaccess.cpp \
    computer.cpp \
    service.cpp \
    relation.cpp

HEADERS += \
    consoleui.h \
    dataaccess.h \
    scientist.h \
    computer.h \
    service.h \
    relation.h
