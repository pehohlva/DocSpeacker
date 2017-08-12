!include($$PWD/tidy/tidy.pri) {
message( "tidy.pri not found" )
}
message(Load Tools config start in  $$PWD/tool.pri)

message(Load Tidy config in  $$PWD/tidy.pri)

# Input only on static lib all binding
brand_number = 0

QT += xml core
CONFIG   += qt warn_off silence release staticlib
LANGUAGE	= C++
DEFINES += NDEBUG THREAD_SAFE=1 TEMP_STORE=2
CONFIG += c++11 release QMAKE_CXXFLAGS_WARN_ON=-w QMAKE_CFLAGS_WARN_ON=-w
LIBS += -lz
    
    
CONFIG   += qt warn_off silence release
LANGUAGE	= C++
LIBS += -lz
DEPENDPATH += $$PWD $$PWD/include
INCLUDEPATH += $$PWD $$PWD/include



SOURCES += $$PWD/html5.cpp $$PWD/cld/lang/languages.cc $$PWD/cld/basicore_cld.cpp

# stay calm html5_global.h datalanguage.h is generated! but core from qlocale & association
HEADERS += $$PWD/include/html5.h \
        $$PWD/include/port.h \
        $$PWD/include/datalanguage.h \ 
        $$PWD/include/languages.pb.h \ 
        $$PWD/include/datamodelqchar.h \
        $$PWD/include/gzipwriter.h \
        $$PWD/include/gzipreader.h \
        $$PWD/include/datalanghelp.h

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
            $$PWD/cld/cld_encodings.h
            
            
message(Load Tools config end in  $$PWD/tool.pri)     