######################################################################
# Automatically generated by qmake (2.01a) mar 10. gio 01:03:47 2008
######################################################################

TEMPLATE = app
TARGET = xx
DEPENDPATH += . 
INCLUDEPATH += .

DESTDIR	+= ./

QT += core gui

CONFIG += c++11
CONFIG += qt warn_off  release

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG   +=  qt thread warn_off silent release console
DEFINES += GIT_VERSION=$$system(git describe --always)
DEFINES += "QT_DEPRECATED_SINCE=0x0500"


# Input
HEADERS += QUnitMargin.h 
SOURCES += main.cpp \
           QUnitMargin.cpp
