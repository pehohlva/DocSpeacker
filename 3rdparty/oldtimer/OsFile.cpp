//
// C++ Implementation: IMQ  Back-up dir from server 
// usage:
// Author: Peter Hohl <pehohlva@gmail.com>,    26.11.2013
// http://www.freeroad.ch/
// Copyright: See COPYING file that comes with this distribution

#include "OsFile.h"

#if defined(Q_OS_SYMBIAN)
#include <f32file.h>
#elif defined(Q_OS_WIN)  
#include <windows.h>
#elif defined(Q_OS_MAC)
/// separate on conflict
#endif

#if defined(Q_OS_UNIX)
#if !defined(Q_OS_MAC) 
#include <sys/vfs.h>
#endif

#endif

#if defined(Q_OS_MAC)
#include <sys/param.h>
#include <sys/mount.h>
#endif



OsFile& OsFile::operator=(const OsFile& d) {
    namefull = d.namefull;
    type = d.type;
    data = d.data;
    return *this;
}

bool OsFile::saveDest(const QString dest) {
    QFileInfo info(dest);
    if (type == 1) {
        QByteArray chunk = streams();
        QDir dir;
        if (!dir.exists(info.absolutePath())) {
            dir.mkpath(info.absolutePath());
        }
        QFile file(info.absoluteFilePath());
        if (file.open(QFile::WriteOnly)) {
            file.write(chunk, chunk.length()); // write to stderr
            file.close();
            return true;
        }
    }
    return false;
}

void OsFile::set_File(const QString f, int t) {
    namefull = f;
    type = t; /// 1 = file / 2 = symslink / 3 = dir
    if (t == 3) {
        data = "dir";
    }
    if (t == 1) {
        /// file 
        QByteArray item;
        QFile *f = new QFile(namefull);
        if (f->exists()) {
            if (f->open(QIODevice::ReadOnly)) {
                if (f->isReadable()) {
                    while (!f->atEnd()) {
                        QByteArray crk = f->readLine();
                        item.append(crk);
                    }
                    f->close();
                }
            }
        }
        if (item.size() > 0) {
            data = qCompress(item);
        }
    }

}


namespace SystemSecure {

    QString bytesToSize(const qint64 size) {
        if (size < 0)
            return QString();
        if (size < 1024)
            return QObject::tr("%1 B").arg(QString::number(((double) size), 'f', 0));
        if ((size >= 1024) && (size < 1048576))
            return QObject::tr("%1 KB").arg(QString::number(((double) size) / 1024, 'f', 0));
        if ((size >= 1048576) && (size < 1073741824))
            return QObject::tr("%1 MB").arg(QString::number(((double) size) / 1048576, 'f', 2));
        if (size >= 1073741824)
            return QObject::tr("%1 GB").arg(QString::number(((double) size) / 1073741824, 'f', 2));
        return QString();
    }

    qint64 FreespaceonDir(const QString selectdir) {

#if !defined(Q_OS_WIN)
        struct statfs stats;
        statfs(selectdir.toLocal8Bit(), &stats);
        unsigned long long bavail = ((unsigned long long) stats.f_bavail);
        unsigned long long bsize = ((unsigned long long) stats.f_bsize);
        return (qint64) (bavail * bsize);
#else
        // MS recommend the use of GetDiskFreeSpaceEx, but this is not available on early versions
        // of windows 95.  GetDiskFreeSpace is unable to report free space larger than 2GB, but we're 
        // only concerned with much smaller amounts of free space, so this is not a hindrance.
        DWORD bytesPerSector(0);
        DWORD sectorsPerCluster(0);
        DWORD freeClusters(0);
        DWORD totalClusters(0);
        if (::GetDiskFreeSpace(selectdir.utf16(), &bytesPerSector, &sectorsPerCluster, &freeClusters, &totalClusters) == FALSE) {
            qWarning() << "Unable to get free disk space on:" << selectdir;
        }
        return (qint64) ((bytesPerSector * sectorsPerCluster * freeClusters) > boundary);
#endif
        return 0;

        /* 
         * #if defined(Q_OS_SYMBIAN)
        bool result(false);

        RFs fsSession;
        TInt rv;
        if ((rv = fsSession.Connect()) != KErrNone) {
            qDebug() << "Unable to connect to FS:" << rv;
        } else {
            TParse parse;
            TPtrC name(path.utf16(), path.length());

            if ((rv = fsSession.Parse(name, parse)) != KErrNone) {
                qDebug() << "Unable to parse:" << path << rv;
            } else {
                TInt drive;
                if ((rv = fsSession.CharToDrive(parse.Drive()[0], drive)) != KErrNone) {
                    qDebug() << "Unable to convert:" << QString::fromUtf16(parse.Drive().Ptr(), parse.Drive().Length()) << rv;
                } else {
                    TVolumeInfo info;
                    if ((rv = fsSession.Volume(info, drive)) != KErrNone) {
                        qDebug() << "Unable to volume:" << drive << rv;
                    } else {
                        result = (info.iFree > boundary);
                    }
                }
            }

            fsSession.Close();
        } */

    }

}
