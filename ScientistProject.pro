QT += core
QT -= gui

CONFIG += c++11

TARGET = PerformersProject
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    consoleui.cpp \
    performerservice.cpp \
    performer.cpp \
    dataaccess.cpp \
    scientist.cpp \
    scientistservice.cpp

HEADERS += \
    consoleui.h \
    performerservice.h \
    performer.h \
    dataaccess.h \
    scientist.h \
    scientistservice.h
