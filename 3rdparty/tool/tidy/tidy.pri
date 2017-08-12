message(Load Tidy config in  $$PWD/tidy.pri)

isEqual(brand_number, "1"){
project_name = HTMLTOOL
project_desc = clean_html_file_import
project_dir1 = $$BUILD_TREE_PATH
message(project_name = $$project_name)
message(Libs subs compatibel -> $$project_desc ->  $$project_name)
}
# type def problem 
QT += core

DEFINES += TIDYLIB_PATH=FROMCLDSERVICE

DEFINES += NDEBUG THREAD_SAFE=1 TEMP_STORE=2
CONFIG += c++11 release QMAKE_CXXFLAGS_WARN_ON=-w QMAKE_CFLAGS_WARN_ON=-w

DEPENDPATH += $$PWD $$PWD/include
INCLUDEPATH += $$PWD $$PWD/include



win32 {
   DEFINES +=TIDY_WIN32_MLANG_SUPPORT
   HEADERS += $$PWD/win32tc.h     $$PWD/iconvtc.h
   SOURCES += $$PWD/win32tc.c      $$PWD/iconvtc.c
}

# Input
HEADERS += $$PWD/access.h \
           $$PWD/attrdict.h \
           $$PWD/attrs.h \
           $$PWD/charsets.h \
           $$PWD/clean.h \
           $$PWD/config.h \
           $$PWD/entities.h \
           $$PWD/forward.h \
           $$PWD/lexer.h \
           $$PWD/message.h \
           $$PWD/parser.h \
           $$PWD/pprint.h \
           $$PWD/streamio.h \
           $$PWD/tags.h \
           $$PWD/tidy-int.h \
           $$PWD/tmbstr.h \
           $$PWD/utf8.h \
           $$PWD/version.h \
           $$PWD/include/buffio.h \
           $$PWD/include/fileio.h \
           $$PWD/include/platform.h \
           $$PWD/include/tidy.h \
           $$PWD/include/tidyenum.h
SOURCES += $$PWD/access.c \
           $$PWD/alloc.c \
           $$PWD/attrask.c \
           $$PWD/attrdict.c \
           $$PWD/attrget.c \
           $$PWD/attrs.c \
           $$PWD/buffio.c \
           $$PWD/charsets.c \
           $$PWD/clean.c \
           $$PWD/config.c \
           $$PWD/entities.c \
           $$PWD/fileio.c \
           $$PWD/istack.c \
           $$PWD/lexer.c \
           $$PWD/localize.c \
           $$PWD/parser.c \
           $$PWD/pprint.c \
           $$PWD/streamio.c \
           $$PWD/tagask.c \
           $$PWD/tags.c \
           $$PWD/tidylib.c \
           $$PWD/tmbstr.c \
           $$PWD/utf8.c

message(Load Tidy end from  $$PWD/tidy.pri)