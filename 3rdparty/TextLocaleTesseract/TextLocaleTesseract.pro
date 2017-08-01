QT += core texttospeech  network xml gui

CONFIG += c++11

TARGET = opnosi
CONFIG += console
CONFIG -= app_bundle

MOC_DIR = build
RCC_DIR = build
OBJECTS_DIR = build

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


CONFIG +=   qt warn_off silent release

ios:QMAKE_CXXFLAGS += -wd4100
ios:QMAKE_CXXFLAGS += -Wno-unused-parameter
ios:QMAKE_CXXFLAGS_WARN_ON = -Wall -Wno-unused-parameter
ios:QMAKE_CXXFLAGS_WARN_ON = -Wall -Wno-parentheses


CONFIG +=   qt warn_off silent release


TEMPLATE = app

SOURCES += main.cpp \
    textrec.cpp \
    textrecdown.cpp \
    textrechander.cpp

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    textrec.h \
    textrecdown.h \
    textrechander.h

DISTFILES += \
    AAsnip.txt \
    maintext.txt
