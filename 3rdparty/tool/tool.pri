
message(Load Tools config start in  $$PWD/tool.pri)


QT += xml core
CONFIG   += qt warn_off silence release
LANGUAGE	= C++
DEFINES += NDEBUG THREAD_SAFE=1 TEMP_STORE=2
CONFIG += c++11 release QMAKE_CXXFLAGS_WARN_ON=-w QMAKE_CFLAGS_WARN_ON=-w
LIBS += -lz
    
    
CONFIG   += qt warn_off silence release
DEPENDPATH += $$PWD $$PWD/include
INCLUDEPATH += $$PWD $$PWD/include

SOURCES += $$PWD/html5.cpp $$PWD/cld/lang/languages.cc

HEADERS += $$PWD/include/html5.h \
        $$PWD/include/port.h \
        $$PWD/include/languages.pb.h \
        $$PWD/include/gzipwriter.h \
        $$PWD/include/gzipreader.h

HEADERS +=  $$PWD/cld/cld_utf8statetable.h \
            $$PWD/cld/basictypes.h \
            $$PWD/include/string_util.h \
            $$PWD/cld/cld_basictypes.h \
            $$PWD/cld/languages.h \
            $$PWD/cld/compact_lang_det.h \
            $$PWD/cld/ext_lang_enc.h \
            $$PWD/cld/letterscript_enum.h \
            $$PWD/cld/unittest_data.h \
            $$PWD/cld/languages.h \
            $$PWD/cld/encodings.pb.h \
            $$PWD/cld/cld_encodings.h


            
message(Load Tools config end in  $$PWD/tool.pri)     
