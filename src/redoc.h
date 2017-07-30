#ifndef RDOC_H
#define RDOC_H
#include "documenthandler.h"
#include "remainwin.h"
#include "re_application_setting.h"

#include "re_speacker.h"


#define rdoc  (static_cast<RDoc*>(QCoreApplication::instance()))

class RDoc : public QApplication
{
  Q_OBJECT

public:
    RDoc(int &argc, char **argv );
    bool event (QEvent *event);
    //// void  openDiskFile();

signals:
     void eventLog(QString);
     void signalFileOpen(QString);
     void readtext();
     void sendstatus(QString);
     void insert_text(QString);


public slots:
     void speechtext(QString);
     void openFile(QString);
     void loginternal(QString);
     void openDiskFile();
     void prepare_to_close();

private:
  
  DocumentHandler *docs;
  MainWin *win;
  QMdiArea *workspace;
  QTextEdit *textEdit;
  QLabel  *StatusApp; //// set text here
  QRect screens;

};

#endif // RDOC_H
