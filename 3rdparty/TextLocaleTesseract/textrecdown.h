#ifndef TEXTRECDOWN_H
#define TEXTRECDOWN_H

#include <QObject>
#include <QPair>
#include "textrec.h"

typedef QPair<QString,QString> PaarString;
typedef QVector<PaarString > Vector_Ass;
typedef QVector<QLocale> Vector_Qlocal;
typedef QVector<QString> Vector_Qstring;
typedef QTextStream Echo; /// out(stdout)

#define __TESSHEXSEPARATOR__ \
              QByteArray(';')


static inline QString QTUTF8decode( const char* t ) {
   qWarning() << "Not secure here!." << __FUNCTION__<<":" <<  __FILE__ << ":" << __LINE__;
   return QObject::trUtf8(t);
}

/* classe per trasformare le varie lingue in un database solo cosa serve a riconoscere i testi  */

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
  void init_listing();
private:
  void register_Locale();
  void register_LinktoGet();
  /* int id = (int)QLocale::language()  unique -   QString nt native language name -  QString ctess Tesseract dir */
  void set_language_native( int id , QString & nt , QString & ctess );
  void vector_char_from(const QString dir , const QString qtxname ); /// one language accepted char...
  int  sucks_lines_from_file( Vector_Qstring & build , const QString file, const  QString dir );
  Vector_Qstring create_database_from_lang( const QString dir , int format = 0 );
  bool getremoteFile;
  bool append_latin_lang;
  QStringList need_uri_list;
  QStringList fromlatin_dir;
  QStringList fromlatin_qlocs;
  Vector_Qlocal locale_jobs;
  Vector_Qstring localeNameVector;
  Vector_Qstring RootCharAll;
  Vector_Ass localeEnableVector; /// qpair* bcp47Name from qlocale + tess dir key to start a qlocale fast..
  Echo out;
  QTime crono;
};



#endif // TEXTRECDOWN_H
