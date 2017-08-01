#ifndef TEXTRECDOWN_H
#define TEXTRECDOWN_H

#include <QObject>
#include "textrec.h"
#include <QPair>


typedef QPair<QString,QString> PaarString;
typedef QVector<PaarString > Vector_Ass;
typedef QVector<QLocale> Vector_Qlocal;
typedef QVector<QString> Vector_Qstring;

typedef QTextStream outx; /// out(stdout)


static inline QString QTUTF8decode( const char* t ) {
   return QObject::trUtf8(t);
}



class TextRecDown : public QObject
{
  Q_OBJECT
public:
  explicit TextRecDown(QObject *parent = nullptr);

signals:

public slots:
  void execute_remote();
  void beginextract_tess();
  void shutdown();
  void pause_now();
  void onefile_handler();
private:
  void register_Locale();
  void register_LinktoGet();
  /* int id = (int)QLocale::language()  unique -   QString nt native language name -  QString ctess Tesseract dir */
  void set_language_native( int id , QString & nt , QString & ctess );
  void vector_char_from(const QString dir , const QString qtxname ); /// one language accepted char...
  bool getremoteFile;
  bool append_latin_lang;
  QStringList need_uri_list;
  QStringList fromlatin_dir;
  QStringList fromlatin_qlocs;
  Vector_Qlocal locale_jobs;
  Vector_Qstring localeNameVector;
  Vector_Ass localeEnableVector; /// qpair* bcp47Name from qlocale + tess dir key to start a qlocale fast..
  outx out;
  QTime crono;
};

#endif // TEXTRECDOWN_H
