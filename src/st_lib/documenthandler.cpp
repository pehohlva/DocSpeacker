#include "documenthandler.h"

DocumentHandler::DocumentHandler(QObject *parent) : QObject(parent)
{
  connect(this, SIGNAL(next_steep()),this, SLOT(ready_doc()));
}

void DocumentHandler::openDoc( const QString file ) {
   //// t.start();
   QString next_stream;
   filenamefullpath = file;
   QFuture<void> future = QtConcurrent::run(&basic,&ZipDoc::simple_open,file);
   future.waitForFinished();
   streamtext = basic.get_text(); /// future.result();
   //// qDebug() << "### DocumentHandler result: " <<  streamtext;
   //// qDebug() << "### DocumentHandler::openDoc " <<  t.elapsed();
   emit next_steep();
}

void DocumentHandler::ready_doc() {
  //// qDebug() << "### send DocumentHandler::ready_doc " <<  t.elapsed();
  emit filltext(streamtext);
}
