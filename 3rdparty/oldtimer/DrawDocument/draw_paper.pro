TEMPLATE = app
TARGET = oo
DEPENDPATH += .
INCLUDEPATH += .
CONFIG += qt debug warn_off console
DESTDIR	+= ./
TEMPLATE = app
CONFIG-=app_bundle
HiView_SIGNATURE = HiHV

CONFIG += c++11
CONFIG += QMAKE_CXXFLAGS_WARN_ON=-w QMAKE_CFLAGS_WARN_ON=-w
MOC_DIR = build
RCC_DIR = build
OBJECTS_DIR = build

QT += opengl
QT += gui
QT += widgets core network
QT += xmlpatterns

SOURCES += main.cpp \
    drawdocument.cpp

HEADERS += \
    tooldoc.h \
    drawdocument.h

DISTFILES += \
    codetmp.txt \
    main_blob.txt \
    collo.txt \
    index.html
