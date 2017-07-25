#include "rdoc.h"

RDoc::RDoc( int &argc, char **argv)
     : QApplication(argc,argv)
{
  win = new QMainWindow();
  screens = QApplication::desktop()->availableGeometry();
  docs = new DocumentHandler(); /// document!

  const int largox = screens.width() / 2;
  const int altox = screens.height() / 10 * 9;


  QMenuBar *menuBar = new QMenuBar(win);
  QStatusBar *statusbar = new QStatusBar(win);
  StatusApp = new QLabel("App Loading ..... ");
  statusbar->addWidget(StatusApp);
  win->setMenuBar(menuBar);
  win->setStatusBar(statusbar);
  //// http://doc.qt.io/archives/qt-5.5/qmenu.html#setAsDockMenu
  QMenu *macdocks = new QMenu();  //// menu by mac bar icons
  macdocks->addAction(tr("&Mac Exit Test"),this, SLOT(quit()));
  macdocks->addSeparator();
  qt_mac_set_dock_menu(macdocks);
  const int screenactive = this->desktop()->screenCount();
  qDebug() << "screen count " << screenactive;


  //// textEdit = new QTextEdit(workspace);
  ////workspace->addSubWindow(textEdit);
  /// textEdit->setMinimumHeight(300);
  ///// textEdit->setMinimumWidth(largox);
  win->setWindowTitle("Document Call");


  workspace = new QMdiArea();
  win->setCentralWidget(workspace);

  win->setMinimumHeight(altox);
  win->setMinimumWidth(largox);

  win->show();
  connect(docs, SIGNAL(filltext(QString)),this, SLOT(speechtext(QString)));
  ///// connect(this, SIGNAL(insert_text(QString)),textEdit, SLOT(setText(QString)));
  connect(this, SIGNAL(signalFileOpen(QString)),this, SLOT(openFile(QString)));
  connect(this, SIGNAL(sendstatus(QString)),StatusApp, SLOT(setText(QString)));
  emit insert_text(QString("Hello world.."));
  emit signalFileOpen(QString("/Users/dev/github/DocSpeacker/stressdoc/demo.doc"));

}

void  RDoc::speechtext(const QString t)
{
  QCoreApplication::processEvents(QEventLoop::AllEvents, 10);
  //// qDebug() << "### speechtext going " << t;
  //// textEdit->setText(t);
  QTextEdit *tex = new QTextEdit();
  tex->setMinimumHeight(455);
  tex->setMinimumWidth(400);
  workspace->addSubWindow(tex);
  tex->show();
  tex->setText(t);
}

void  RDoc::openFile(const QString f)
{
      qDebug() << "### openFile " <<  f;
      emit insert_text(QString("New file incomming %1..").arg(f));
      emit sendstatus(QString("New file incomming %1..").arg(f));
      docs->openDoc(f);
}

bool RDoc::event (QEvent *event) {

       qDebug() << "### EventApplication event in >>  " << event->type();
       if (event->type() == QEvent::FileOpen)
       {
       // Get the path of the file that we want to open
       const QString  file_path = static_cast<QFileOpenEvent *> (event)->file();
       emit signalFileOpen(file_path);
       } else {
         // The system requested us to do another thing, so we just follow the rules
         return QApplication::event (event);
       }
       return true;
   }

