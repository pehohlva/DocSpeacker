#ifndef TEXTREC_H
#define TEXTREC_H
#include "textrec_config.h"

#include "database_language_tess.h"



static QString bytesToSize(const qint64 size) {
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


static bool is_Latin( const QByteArray array ) {
  QByteArray spinn = QString::fromUtf8(array).toLatin1();
  bool latinchunk = false;
  double parts = spinn.size() / (array.size() / 100); /// how many % latin go away!
  if (parts > 92 ) { //// loast data latin
    latinchunk = true;
  }
  return latinchunk;
}




class RamStream
{
  public:
  RamStream()
  :d(new QBuffer())
  {
  d->open(QIODevice::ReadWrite);
  start();
  }
  ~RamStream()
  {
   d->close();
  }
  bool clear()
  {
    d->write(QByteArray());
    return d->bytesAvailable() == 0 ? true : false;
  }
  qint64 ramwrite( QByteArray x ) {
    d->write(x);
    start();
    return d->bytesAvailable();
  }

  void start() {
    d->seek(0);
  }

  QByteArray append_chunk( const QString file ) const {
    QFile f(file);
        if (f.exists()) {
              if (f.open(QFile::ReadOnly)) {
                  const QByteArray ch = f.readAll();
                  f.close();
                return ch;
              }
         }
     return QByteArray();
  }
  //// only text file in stream buffer ram.
  bool appendFile( const QString file , bool latin = true ) {
     QFile f(file);
     bool islatin = false;
        if (f.exists()) {
          if (f.open(QFile::ReadOnly)) {
              const QByteArray ch = f.readAll();
              f.close();
              QByteArray spinn = QString::fromUtf8(ch).toLatin1(); // no latin language lost data!
              const int perc = spinn.size() / (ch.size() / 100); /// how many % latin!
              if ( perc > 92 ) {
                  islatin = true;
                   //// qDebug() <<  "set latin:" << perc << "%->" << file;
                }
                    if ( islatin && latin ) {
                       d->write(ch);
                    }
                    if (!islatin && !latin) {
                       d->write(ch);
                     }
           return islatin;
          }
        } else {
            return false;
        }
  }

  bool LoadFile( const QString file ) {
    if (clear()) {
     QFile f(file);
        if (f.exists()) {
          if (f.open(QFile::ReadOnly)) {
           d->write(f.readAll());
           f.close();
           start();
           return true;
          }
        }
    }
    return false;
  }
  bool PutOnFile( const QString file ) {

    QFileInfo fi(file);
    QDir dir;
         if(!dir.exists(fi.absolutePath())) {
             dir.mkpath(fi.absolutePath());
          }

      QFile f(file);
      start();
      if (f.open(QFile::WriteOnly)) {
        uint bi = f.write(d->readAll());
        f.close();
        start();
        return bi > 0 ? true : false;
      }
   return false;
  }
  //// QDomDocument Dom() { return doc; }
  QBuffer *device() { return d; }
  //// bool isValid() { return doc.setContent(stream(),false,0,0,0);  }
  QByteArray stream() { return d->data(); }
  //// QDomDocument doc;
  QBuffer *d;
};




class Tessy {
public:

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
