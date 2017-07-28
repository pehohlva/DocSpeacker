#ifndef DOCUMENTHANDLER_H
#define DOCUMENTHANDLER_H

#include "zipdoc.h"
#include <QObject>
#include <qendian.h>
#include <qdebug.h>
#include <qdir.h>
#include <iostream>
#include <QMimeDatabase>
#include <QMimeType>
#include <QtConcurrent>
#include <QMimeType>
#include <QFuture>
#include <QtConcurrentRun>
#include <QDesktopWidget>
#include <QStatusBar>
#include <QMenuBar>
#include <QLabel>
#include <QMainWindow>
#include <QMenu>
#include <QMdiArea>
#include <QTextEdit>
#include <QCoreApplication>
#include "zipdoc.h"
#include <QApplication>
#include <QPlainTextEdit>
#include <iostream>
#include <QEvent>
#include <QtGui>
#include <QTextDocument>
#include <QTextCursor>
#include <QMainWindow>
#include <QtGui>
#include <QTextDocument>
#include <QTextCursor>


/* class to run on QtConcurrent::run to open documents
 * this is the bridge to read documents...
 * & send signal if ready ...
*/

class DocumentHandler : public QObject
{
  Q_OBJECT

public:
  explicit DocumentHandler(QObject *parent = 0 );
  void openDoc( const QString file );

signals:
   void filltext(QString);
   void next_steep();
public slots:
  void ready_doc();
private:
    ZipDoc basic;
    QString streamtext;
    QString filenamefullpath;
    /// QTime t;
};

#endif // DOCUMENTHANDLER_H
