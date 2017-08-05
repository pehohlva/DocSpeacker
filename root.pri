message(Hi Document root.pri file path is here ok.. )
message(DOCUMENT_ROOT_PATH $$PWD)
QT_VERSION = $$[QT_VERSION]
QT_VERSION = $$split(QT_VERSION, ".")
QT_VER_MAJ = $$member(QT_VERSION, 0)
QT_VER_MIN = $$member(QT_VERSION, 1)
QT_VER_PAT = $$member(QT_VERSION, 2)
message(Detect QT Version $$[QT_VERSION]..)
#### this here is only a switch to cpu slow from ide qt Creator and continue build ...
lessThan(QT_VER_MAJ, 5) | lessThan(QT_VER_MIN,8) | lessThan(QT_VER_PAT,1) {
  error(Error I need the version QT 5.9.1 edit line 10 from root.pri ...only cpu save  Version $$[QT_VERSION] was detected. optimum 5.9.9 )
} else {
   message(..ok qt version..)
   message(Version $$[QT_VERSION] was detected)
   message(..ok qt version..)
}



BUILD_TREE_PATH = $$PWD

macx:DEFINES += MACOSX_ROOT
win32:DEFINES += WINOSX_ROOT
unix:DEFINES += LINUXOSX_ROOT



LIB_TREE_PATH = $$BUILD_TREE_PATH/lib
message(Libs install dir  $$LIB_TREE_PATH)
