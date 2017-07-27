#-------------------------------------------------
#
# Project created by QtCreator 2017-07-24T17:25:19
#
#-------------------------------------------------

QT       += core gui xml concurrent pdfium

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DocSpeacker
TEMPLATE = app

# CONFIG-=app_bundle
macx {
HiView_SIGNATURE = HiHV

CONFIG += c++11
CONFIG += QMAKE_CXXFLAGS_WARN_ON=-w QMAKE_CFLAGS_WARN_ON=-w
LIBS += -lz
cache()
MOC_DIR = build
RCC_DIR = build
OBJECTS_DIR = build

INCLUDEPATH +=st_lib/
LIBS += -L ./st_lib/ -l_docrec
INCLUDEPATH += $$[QT_INSTALL_PREFIX]/src/3rdparty/zlib
#
ICON = docspeacker.icns
QMAKE_INFO_PLIST = Info.plist.template
OTHER_FILES += Info.plist.template


RC_FILE = docspeacker.icns


TARGET = DocSpeacker

#Info_plist.target   =   Info.plist # exec console ./DocSpeacker.app/Contents/MacOS/DocSpeacker
#Info_plist.depends  =   Info.plist.template DocSpeacker.app/Contents/Info.plist
#Info_plist.commands =   @$(DEL_FILE) $${TARGET}.app/Contents/Info.plist$$escape_expand(\n\t) \
         #               @$(SED) -e "s,@EXECUTABLE@,$$TARGET,g" -e "s,@VERSION@,$$MODULE_VERSION,g" -e "s,@TYPEINFO@,$$HiView_SIGNATURE,g" -e "s,@ICON@,$$basename(ICON),g" Info.plist.template > $${TARGET}.app/Contents/Info.plist
#QMAKE_EXTRA_TARGETS +=  Info_plist
#PRE_TARGETDEPS      +=  $$Info_plist.target

}


SOURCES += main.cpp redoc.cpp remainwin.cpp
HEADERS += redoc.h remainwin.h re_application_setting.h

DISTFILES += docspeacker.icns \
    pkginfo \
    Info.plist.template

RESOURCES += inlinefolder.qrc
