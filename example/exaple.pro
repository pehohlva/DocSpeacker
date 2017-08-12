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
QT += gui xml
QT += widgets core network
QT += xmlpatterns


# set not 1 to build whitout pdfium module
USEPDFPLAY = 0
contains( USEPDFPLAY , [l1] ):QT += pdfium
contains( USEPDFPLAY , [l1] ):message(..ok load pdfium tool... )
contains( USEPDFPLAY , [l1] ):DEFINES += LOADPDFIUMYES=$(USEPDFPLAY)


SOURCES += main.cpp

HEADERS += \
    grabitem.h

DISTFILES +=





CURLONBOARD = $$system(which curl)

UNAME = $$system(uname -s)
contains( UNAME, [lD]arwin ):message( This looks like Linux ($$UNAME) to me )







