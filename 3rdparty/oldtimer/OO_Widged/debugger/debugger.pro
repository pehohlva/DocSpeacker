######################################################################
# Automatically generated by qmake (2.01a) ven 5. set 10:01:37 2008
######################################################################

TEMPLATE = app
TARGET = xx
DEPENDPATH += . ../oasis
INCLUDEPATH += . ../oasis

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


DESTDIR	+= ./

MOC_DIR = build/.moc
RCC_DIR = build/.rcc
OBJECTS_DIR = build/.obj
 
DEFINES += _OOREADRELEASE_


QT += xml network

CONFIG +=  qt debug warn_off console

FORMS += main.ui

HEADERS += ZipDebugMain.h
SOURCES += main.cpp ZipDebugMain.cpp

LIBS += -lz
INCLUDEPATH += $$[QT_INSTALL_PREFIX]/src/3rdparty/zlib


QT += printsupport

HEADERS += ../oasis/FoColorName.h \
           ../oasis/GZipReader.h \
           ../oasis/GZipWriter.h \
           ../oasis/OOFormat.h \
           ../oasis/OOReader.h \
           ../oasis/XML_Editor.h
SOURCES += ../oasis/FoColorName.cpp \
           ../oasis/GZip.cpp \
           ../oasis/OOFormat.cpp \
           ../oasis/OOReader.cpp \
           ../oasis/XML_Editor.cpp



















