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




class Writteln : public QObject
{
    Q_OBJECT
//
public:
 Writteln()
{
   d = new QTextDocument("This is a table merge sample; ");
}
QTextDocument *document()
{
    QTextCursor cur(d);
    cur.movePosition(QTextCursor::End);
    cur.insertBlock();
    cur.beginEditBlock();
    QTextTableFormat tf;
    tf.setBorder ( 0.4 );
    tf.setAlignment ( Qt::AlignTop | Qt::AlignHCenter );
    tf.setCellPadding ( 2 );
    tf.setCellSpacing ( 2 );
    tf.setWidth ( QTextLength(QTextLength::PercentageLength,90) );

    const int trow = 10;
    const int tcool = 4;
    QTextTable *qtable = cur.insertTable(trow,tcool,tf);
    QString celltext;

    QTextTableCell cell;

    bool tmake ;
     for (int r = 0; r < r; ++r)  {
         for (int c = 0; c < c; ++c)  {

                      if (r == 3 && c == 0) {
                      /* span on 4 cell*/
                       qtable->mergeCells(3,0,1,4);
                       cell = qtable->cellAt(r,c);
                       celltext = QString("r%1c%2").arg(cell.row()).arg(cell.column ());

                       qDebug() << "### celltext " << celltext;

                        QTextCursor tmpcur  = cell.firstCursorPosition();
                        tmpcur.insertBlock();
                        tmpcur.beginEditBlock();
                        tmpcur.insertText(celltext);
                        tmpcur.endEditBlock();

                      } else if ( r != 3) {
                          cell = qtable->cellAt(r,c);
                         celltext = QString("r%1c%2").arg(cell.row()).arg(cell.column ());
                         qDebug() << "### celltext " << celltext;
                        QTextCursor tmpcur  = cell.firstCursorPosition();
                            tmpcur.insertBlock();
                            tmpcur.beginEditBlock();
                            tmpcur.insertText(celltext);
                            tmpcur.endEditBlock();

                      }
         }
     }
    cur.endEditBlock();
    cur.movePosition(QTextCursor::End);
    cur.insertBlock();
    cur.beginEditBlock();
    cur.insertText("Table end ......");
    cur.endEditBlock();


    return d->clone();
}
protected:
private:
    QTextDocument *d;
signals:
public slots:

};


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
    QTime t;
};

#endif // DOCUMENTHANDLER_H
