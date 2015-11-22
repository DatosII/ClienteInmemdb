#-------------------------------------------------
#
# Project created by QtCreator 2015-11-18T19:47:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ClienteInmemdb
TEMPLATE = app


SOURCES += main.cpp \
    wrapperxml.cpp \
    terminal/terminal.cpp \
    adapter.cpp \
    clientinmemdb.cpp

HEADERS  += \
    wrapperxml.h \
    terminal/terminal.h \
    adapter.h \
    clientinmemdb.h
CONFIG += c++11
