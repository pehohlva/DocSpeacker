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

#### try to find out in qt 5.9.2 include <QtDeclarative>
#### QT += declarative
message(Now define BUILD_TREE_PATH to =  $$PWD)

win32 {
    ########## window no pwd  #############
    BUILD_TREE_PATH = $$PWD
    message(Window path  $$BUILD_TREE_PATH)
    CONFIG +=   qt warn_off silent release
}


unix {
    BUILD_TREE_PATH = $$PWD
    message(Unix path  $$BUILD_TREE_PATH)
}

macx {
    BUILD_TREE_PATH = $$PWD
    message(Mac path $$BUILD_TREE_PATH)

}


LIB_TREE_PATH = $$BUILD_TREE_PATH/lib
message(Libs install dir  $$LIB_TREE_PATH)
message(All app and helper tool go to $$BUILD_TREE_PATH/bin )
