#ifndef __PORTSYSTEMCONVERT__
#define __PORTSYSTEMCONVERT__

#include <QtCore/qglobal.h>
#include <QtGlobal>
#include <qlist.h>
#include <qhash.h>
#include <qfile.h>
#include <qbytearray.h>
#include <qstring.h>
#include <qchar.h>
#include <qvector.h>
#include <qdebug.h>
#include <QStringList>
#include <QtCore/qglobal.h>
#include <QtGlobal>
#include <stdio.h>      /* printf */
#include <assert.h>
#include "qtextstream.h"
#include "datalanghelp.h"
#include "datamodelqchar.h"



/* Q_OS_AIX
Q_OS_ANDROID
Q_OS_BSD4
Q_OS_BSDI
Q_OS_CYGWIN
Q_OS_DARWIN - Darwin-based OS such as OS X and iOS, including any open source version(s) of Darwin.
Q_OS_DGUX
Q_OS_DYNIX
Q_OS_FREEBSD
Q_OS_HPUX
Q_OS_HURD
Q_OS_IOS
Q_OS_IRIX
Q_OS_LINUX
Q_OS_LYNX
Q_OS_MAC - Darwin-based OS distributed by Apple, which currently includes OS X and iOS, but not the open source version.
Q_OS_NETBSD
Q_OS_OPENBSD
Q_OS_OSF
Q_OS_OSX
Q_OS_QNX
Q_OS_RELIANT
Q_OS_SCO
Q_OS_SOLARIS
Q_OS_ULTRIX
Q_OS_UNIX
Q_OS_UNIXWARE
Q_OS_WIN32 - 32-bit and 64-bit versions of Windows (not on Windows CE).
Q_OS_WIN64
Q_OS_WIN - all supported versions of Windows. That is, if Q_OS_WIN32, Q_OS_WIN64 or Q_OS_WINCE is defined.
Q_OS_WINCE
Q_OS_WINPHONE
Q_OS_WINRT */

/* #ifdef W_OS_LINUX
  std::cout << "Linux version";
#elif defined(W_OS_CYGWIN)
  std::cout << "Cygwin version";
#else
#error "We don't support that version yet..."
#endif */

/* Use Q_WS_x where x is one of:

 MACX     - Mac OS X
 MAC9     - Mac OS 9
 QWS      - Qt for Embedded Linux
 WIN32    - Windows
 X11      - X Window System
 S60      - Symbian S60
 PM       - unsupported
 WIN16    - unsupported */

/* Use Q_OS_x with x being one of:

 DARWIN   - Darwin OS (synonym for Q_OS_MAC)
 SYMBIAN  - Symbian
 MSDOS    - MS-DOS and Windows
 OS2      - OS/2
 OS2EMX   - XFree86 on OS/2 (not PM)
 WIN32    - Win32 (Windows 2000/XP/Vista/7 and Windows Server 2003/2008)
 WINCE    - WinCE (Windows CE 5.0)
 CYGWIN   - Cygwin
 SOLARIS  - Sun Solaris
 HPUX     - HP-UX
 ULTRIX   - DEC Ultrix
 LINUX    - Linux
 FREEBSD  - FreeBSD
 NETBSD   - NetBSD
 OPENBSD  - OpenBSD
 BSDI     - BSD/OS
 IRIX     - SGI Irix
 OSF      - HP Tru64 UNIX
 SCO      - SCO OpenServer 5
 UNIXWARE - UnixWare 7, Open UNIX 8
 AIX      - AIX
 HURD     - GNU Hurd
 DGUX     - DG/UX
 RELIANT  - Reliant UNIX
 DYNIX    - DYNIX/ptx
 QNX      - QNX
 QNX6     - QNX RTP 6.1
 LYNX     - LynxOS
 BSD4     - Any BSD 4.4 system
 UNIX     - Any UNIX BSD/SYSV system */

//// googl format int translate

#ifdef COMPILER_MSVC
#define GG_LONGLONG(x) x##I64
#define GG_ULONGLONG(x) x##UI64
#else
#define GG_LONGLONG(x) x##LL
#define GG_ULONGLONG(x) x##ULL
#endif

// Per C99 7.8.14, define __STDC_CONSTANT_MACROS before including <stdint.h>
// to get the INTn_C and UINTn_C macros for integer constants.  It's difficult
// to guarantee any specific ordering of header includes, so it's difficult to
// guarantee that the INTn_C macros can be defined by including <stdint.h> at
// any specific point.  Provide GG_INTn_C macros instead.

#define GG_INT8_C(x)    (x)
#define GG_INT16_C(x)   (x)
#define GG_INT32_C(x)   (x)
#define GG_INT64_C(x)   GG_LONGLONG(x)

#define GG_UINT8_C(x)   (x ## U)
#define GG_UINT16_C(x)  (x ## U)
#define GG_UINT32_C(x)  (x ## U)
#define GG_UINT64_C(x)  GG_ULONGLONG(x)

// It's possible for functions that use a va_list, such as StringPrintf, to
// invalidate the data in it upon use.  The fix is to make a copy of the
// structure before using it and use that copy instead.  va_copy is provided
// for this purpose.  MSVC does not provide va_copy, so define an
// implementation here.  It is not guaranteed that assignment is a copy, so the
// StringUtil.VariableArgsFunc unit test tests this capability.
#if defined(COMPILER_GCC)
#define GG_VA_COPY(a, b) (va_copy(a, b))
#elif defined(COMPILER_MSVC)
#define GG_VA_COPY(a, b) (a = b)
#endif

// Define an OS-neutral wrapper for shared library entry points
#if defined(OS_WIN)
#define API_CALL __stdcall
#else
#define API_CALL
#endif




#define BTRACE QTextStream stream(stdin)




/// using namespace std;
//// = "nonefileset"
static inline void print_number(int* myInt, char *fi ) {

  assert (myInt!=NULL);
  printf("\nNumber extract is: %d , Include File %s must check...",myInt,fi);
}

#ifdef W_OS_LINUX
  TRACE() << "Linux version";






#elif defined(W_OS_CYGWIN)






TRACE() << "Cygwin version";
#elif defined(Q_OS_MAC)


/*  qDebug() << "before debug input dialog";
QString debugText = QInputDialog::getText(NULL, "Input debug text", "Your input:");
qDebug() << "got text" << debugText; */



#else
#error "We don't support that version yet..."
#endif */



#endif /* __PORTSYSTEMCONVERT__ */
