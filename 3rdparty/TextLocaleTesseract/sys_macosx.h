#ifndef SYS_MACOSX_H
#define SYS_MACOSX_H

#include <QtCore>
#include <QElapsedTimer>
#include <CoreServices/CoreServices.h>
#include <CoreFoundation/CFBundle.h>
#include <UIKit/UIKit.h>



#define CHECKTIME(x)  \
    QElapsedTimer CONCAT(sb_, __LINE__); \
    CONCAT(sb_, __LINE__).start(); \
    x \
    qDebug() << __FUNCTION__ << ":" << __LINE__ << " Elapsed time: " <<  CONCAT(sb_, __LINE__).elapsed() << " ms.";



/*  // usage of this macro
    CHECKTIME(
    // any code
    for (int i=0; i<1000; i++)
    {
       timeConsumingFunc();
    }
)
http://www.code-q.fi/en/products/q-framework
https://community.kde.org/Guidelines_and_HOWTOs/Build_from_source/Mac#Install_Craft
http://doc.qt.io/qt-4.8/mac-differences.html#limitations
QCoreApplication::applicationDirPath()
  */



#ifdef Q_WS_MAC

    CFURLRef appUrlRef = CFBundleCopyBundleURL(CFBundleGetMainBundle());
    CFStringRef macPath = CFURLCopyFileSystemPath(appUrlRef,
                                           kCFURLPOSIXPathStyle);
    const char *pathPtr = CFStringGetCStringPtr(macPath,
                                           CFStringGetSystemEncoding());
    qDebug("Path = %s", pathPtr);
    CFRelease(appUrlRef);
    CFRelease(macPath);

#endif




#endif // SYS_MACOSX_H
