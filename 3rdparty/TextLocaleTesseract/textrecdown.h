#ifndef TEXTRECDOWN_H
#define TEXTRECDOWN_H

#include <QObject>
#include "textrec.h"



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
private:
  /* int id = (int)QLocale::language()  unique -   QString nt native language name -  QString ctess Tesseract dir */
  void set_language_native( int id , QString & nt , QString & ctess );
  QVector<QLocale> locale_jobs;
  QVector<QString> localeNameVector;
};

#endif // TEXTRECDOWN_H
