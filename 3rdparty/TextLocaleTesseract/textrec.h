#ifndef TEXTREC_H
#define TEXTREC_H

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
#include <QLoggingCategory>


class Tessy {
public:

    /*
    enum {
        MAGICNUMBER = 0xA0B0C0D0, VERSION = 50
    };
    */

    Tessy() {
      filenametess = QStringLiteral("error!");
      name_native = QStringLiteral("error!");
      type =0;
      data = QByteArray("Long Word.");
    }
    Tessy& operator=(const Tessy& d);

    operator QVariant() const {
        return QVariant::fromValue(*this);
    }
    //// void set_File(const QString f, int t);
    QString name_tess() {
        return filenametess;
    }
    int mlanguage() {
        return type;
    }

    QByteArray streams() {
      return data;
    }
    QString set( const int id,QString n,QString t) {
        type = id;
        name_native= n;
        filenametess= t;
    }

    QString name_native; //// language name in this
    QString filenametess;  /// bcp47Name from qt... + .tessy
    int type; //// unique id qlocale.language() as int
    QByteArray data;
};

//// Tessy end

inline QDebug operator<<(QDebug debug, Tessy& udoc) {
    debug.nospace() << "Tessy(name_native."
            << udoc.name_native << ",filenametess:"
            << udoc.filenametess << ",type:"
            << udoc.type << ",size()"
            << udoc.data.size() << ")";
    return debug.space();
}

inline QDataStream& operator<<(QDataStream& out, const Tessy& udoc) {
    out << udoc.name_native;
    out << udoc.filenametess;
    out << udoc.type;
    out << udoc.data;
    return out;
}

/// read out from file!!

inline QDataStream& operator>>(QDataStream& in, Tessy& udoc) {
    in >> udoc.name_native;
    in >> udoc.filenametess;
    in >> udoc.type;
    in >> udoc.data;
    return in;
}

Q_DECLARE_METATYPE(Tessy);





/*

class LanguageTess {
public:

    enum {
        MAGICNUMBER = 0xA0B0C0D0, VERSION = 21
    };

    LanguageTess() {

    }
    LanguageTess& operator=(const LanguageTess& d);

    operator QVariant() const {
        return QVariant::fromValue(*this);
    }
    void set_File(const QString f, int t);

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
    QByteArray data;

};

 */


class TextRec
{
public:
  TextRec();
};

#endif // TEXTREC_H
