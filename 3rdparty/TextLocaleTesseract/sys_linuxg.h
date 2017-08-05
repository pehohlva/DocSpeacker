#ifndef SYS_LINUXG_H
#define SYS_LINUXG_H
#include <QtCore>


#ifndef Q_WS_MAC
#ifdef LINUXOSX_ROOT
//// qFatal("Compiler  read file defined only to Linux!");
#endif
#endif






/*
#if (TARGET_OS_WATCH)
const char *homedir = getenv("HOME");
     if ((homedir == NULL) {
        homedir = getpwuid(getuid())->pw_dir;
     }
#endif
 */






#endif // SYS_LINUXG_H
