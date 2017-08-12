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
#
QT += gui
QT += gui
QT += widgets core network
 QT += xmlpatterns
QT += opengl
QT += printsupport

SOURCES += main.cpp \
    drawdocument.cpp \
    drawapplication.cpp

HEADERS += \
    tooldoc.h \
    drawdocument.h \
    drawapplication.h

DISTFILES += \
    codetmp.txt \
    main_blob.txt \
    collo.txt \
    index.html



DNSPOP = $$system(which curl)

UNAME = $$system(uname -s)
contains( UNAME, [lD]arwin ):message( This looks like Linux ($$UNAME) to me )

message(..ok qt version. on  ($$UNAME))
message(..ok qt version. on  ($$DNSPOP))








