
!include(../root.pri) {
message( "root.pri  not found" )
}

#!include( ../3rdparty/tool/tool.pri ) {
#message( "tool.pri not found" )
#}

TEMPLATE = app
TARGET = oo
DEPENDPATH += .
INCLUDEPATH += .
CONFIG += qt debug warn_off console console
DESTDIR	+= ./
TEMPLATE = app
CONFIG-=app_bundle
HiView_SIGNATURE = HiHV


include( ../3rdparty/tool/tool.pri )


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


LIBS += -lz
#DEPENDPATH += $$BUILD_TREE_PATH $$PWD
#INCLUDEPATH += $$BUILD_TREE_PATH $$PWD
DEPENDPATH += $$PWD ../
INCLUDEPATH += $$PWD ../

LIBS += -L../lib -lhtml5

SOURCES += main.cpp \
    qindexlanguage.cpp \
    qlsd2.cpp

HEADERS += \
    grabitem.h \
    qindexlanguage.h \
    qlsd2.h

DISTFILES +=


CURLONBOARD = $$system(which curl)

UNAME = $$system(uname -s)
contains( UNAME, [lD]arwin ):message( This looks like Linux ($$UNAME) to me )







