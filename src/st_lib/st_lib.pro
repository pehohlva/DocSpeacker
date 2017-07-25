#-------------------------------------------------
#
# Project created by QtCreator 2017-07-24T17:25:19
#
#-------------------------------------------------

message( “Only for Mac OS X convert document specific. ” )

QT       += core gui xml concurrent pdfium
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = _docrec
TEMPLATE = lib
CONFIG += staticlib
CONFIG += c++11 release QMAKE_CXXFLAGS_WARN_ON=-w QMAKE_CFLAGS_WARN_ON=-w
LIBS += -lz
MOC_DIR = buildlib
RCC_DIR = buildlib
OBJECTS_DIR = buildlib
INCLUDEPATH += $$[QT_INSTALL_PREFIX]/src/3rdparty/zlib
DEFINES += QT_DEPRECATED_WARNINGS
# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += zipdoc.cpp \
           documenthandler.cpp 

HEADERS += zipdoc.h \
        gzipreader.h \
        gzipwriter.h \
        documenthandler.h 


