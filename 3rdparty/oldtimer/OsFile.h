//
// C++ Implementation: IMQ  Back-up dir from server 
// usage:
// Author: Peter Hohl <pehohlva@gmail.com>,    26.11.2013
// http://www.freeroad.ch/
// Copyright: See COPYING file that comes with this distribution

#ifndef OSFILE_H
#define	OSFILE_H

#include <QCoreApplication>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QStringList>
#include <QTimer>
#include <QUrl>
#include <QDir>
#include <QDate>
#include <QDateTime>
#include <QFileInfo>
#include <QFile>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkDiskCache>
#include <QTextStream>
#include <QMetaType>
#include <QPair>
#include <QtCore>


class OsFile {
public:

    enum {
        MAGICNUMBER = 0xA0B0C0D0, VERSION = 50
    };
    OsFile() {
        
    }
    OsFile& operator=(const OsFile& d);

    operator QVariant() const {
        return QVariant::fromValue(*this);
    }
    void set_File(const QString f, int t);

    void set_NameSimslink(const QString n) {
        if (type == 2) {
            data = n.toLocal8Bit();
        }
    }
    QString name() {
        return namefull;
    }
    int modus() {
        return type;
    }
    QByteArray streams() {
        if (type == 1) {
            return qUncompress(data);
        } else {
            return data;
        }
    }
    bool saveDest( const QString dest );
    int type; /// 1 = file / 2 = symslink / 3 = dir
    QString namefull;
    QByteArray data; /* qCompress */

};

inline QDebug operator<<(QDebug debug, OsFile& udoc) {
    debug.nospace() << "OsFile(name."
            << udoc.namefull << ",type:"
            << udoc.type << ",size()"
            << udoc.data.size() << ")";
    return debug.space();
}
/// writteln to file

inline QDataStream& operator<<(QDataStream& out, const OsFile& udoc) {
    out << udoc.namefull;
    out << udoc.type;
    out << udoc.data;
    return out;
}
/// read out from file!!

inline QDataStream& operator>>(QDataStream& in, OsFile& udoc) {
    in >> udoc.namefull;
    in >> udoc.type;
    in >> udoc.data;
    return in;
}

//// qRegisterMetaType<OsFile>(); 
Q_DECLARE_METATYPE(OsFile);



/// SystemSecure::freespaceonHome()
namespace SystemSecure {
    QString bytesToSize(const qint64 size);
    qint64 FreespaceonDir(const QString selectdir);
    static inline QString freespaceonHome() {
        return bytesToSize(FreespaceonDir(QDir::homePath()));
    }
}




#endif	/* OSFILE_H */

