#ifndef RDOC_H
#define RDOC_H
#include "documenthandler.h"
#include <QFileDialog>


#define rdoc  (static_cast<RDoc*>(QCoreApplication::instance()))

class RDoc : public QApplication
{
  Q_OBJECT

public:
    RDoc(int &argc, char **argv );
    bool event (QEvent *event);
    //// void  openDiskFile();

signals:

     void signalFileOpen(QString);
     void readtext();
     void sendstatus(QString);
     void insert_text(QString);

public slots:
     void speechtext(QString);
     void openFile(QString);
     void  openDiskFile();

private:
  DocumentHandler *docs;
  QMainWindow *win;
  QMdiArea *workspace;
  QTextEdit *textEdit;
  QLabel  *StatusApp; //// set text here
  QRect screens;

};

#endif // RDOC_H
