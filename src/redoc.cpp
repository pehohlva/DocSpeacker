#include "redoc.h"
#include <QFileInfo>
#include <QVariant>


RDoc::RDoc( int &argc, char **argv)
     : QApplication(argc,argv)
{
  ///// load all setting here
  QCoreApplication::setOrganizationName("Avasoft");
  QCoreApplication::setOrganizationDomain("avasofter_loop.com");
  QCoreApplication::setApplicationName("DocSpeacker");
  /// QSettings (_ORGANIZATION_NAME_,_PROGRAM_NAME_);
  QSettings settings(_ORGANIZATION_NAME_,_PROGRAM_NAME_);
  win = new MainWin();
  screens = QApplication::desktop()->availableGeometry();
  int largox = screens.width() / 2;
  int altox = screens.height() / 2;
  win->setMinimumHeight(altox);
  win->setMinimumWidth(largox);

  qDebug() << "largo/alto " << largox  << ":" << altox;

  /// openDiskFile
  int swidth = settings.value("editor/width").toInt();
  int sheight = settings.value("editor/height").toInt();
  if (swidth < 10 &&  sheight < 10 ) {
    settings.setValue("editor/width", largox);
    settings.setValue("editor/height", altox);
  } else {
     int wi = settings.value("editor/width").toInt();
     int hi = settings.value("editor/height").toInt();
     win->resize(qMax(wi,largox),qMax(hi,altox));
  }


  screens = QApplication::desktop()->availableGeometry();
  docs = new DocumentHandler(); /// document!


  const int screenactive = this->desktop()->screenCount();
  qDebug() << "screen count " << screenactive;


  //// textEdit = new QTextEdit(workspace);
  ////workspace->addSubWindow(textEdit);
  /// textEdit->setMinimumHeight(300);
  ///// textEdit->setMinimumWidth(largox);
  win->setWindowTitle("Document Call");

  workspace = new QMdiArea();
  win->setCentralWidget(workspace);


  //// http://doc.qt.io/archives/qt-5.5/qmenu.html#setAsDockMenu QKeySequence::Open
  QMenu *macdocks = new QMenu();  //// menu by mac bar icons QKeySequence::Open addAction(const QIcon &icon, const QString &text, Functor functor, const QKeySequence &shortcut = 0)
  macdocks->addAction(QTR("&Mac Exit Test"),this, SLOT(prepare_to_close()));
  QAction *opendialogconfig = new QAction(QTR("&Mac Open Document.."),win);
  //// opendialogconfig->setIcon(win->style()->standardIcon(QStyle::SP_FileIcon));
  //// opendialogconfig->setShortcut(QKeySequence(QKeySequence::Open));
  opendialogconfig->setStatusTip(QTR("Open File *"));
  QObject::connect(opendialogconfig, SIGNAL(triggered()),this, SLOT(openDiskFile()));
  macdocks->addAction(opendialogconfig);
  qt_mac_set_dock_menu(macdocks);


  connect(win, SIGNAL(request_to_close()),this, SLOT(prepare_to_close()));
  connect(win, SIGNAL(from_main_new_file()),this, SLOT(openDiskFile()));

  connect(docs, SIGNAL(filltext(QString)),this, SLOT(speechtext(QString)));
  ///// connect(this, SIGNAL(insert_text(QString)),textEdit, SLOT(setText(QString)));
  connect(this, SIGNAL(signalFileOpen(QString)),this, SLOT(openFile(QString)));
  connect(this, SIGNAL(sendstatus(QString)),win, SLOT(setstatustext(QString)));
  emit insert_text(QTR("Hello world.."));
  emit signalFileOpen(QString("/Users/dev/github/DocSpeacker/stressdoc/demo.doc"));
  win->show();
  win->move((screens.width() / 2) - (win->width() / 2),0);
}

void  RDoc::speechtext(const QString t)
{
  QCoreApplication::processEvents(QEventLoop::AllEvents, 10);

  /*     UI_Speacker *item = new UI_Speacker(win);
                   item->setPlainText(t);
                   workspace->addSubWindow(item);
                   item->show();
    i lost a file in git hystory by a crash  ...  :-( */


  QTextEdit *tex = new QTextEdit(win);
  tex->setMinimumHeight(455);
  tex->setMinimumWidth(400);
  workspace->addSubWindow(tex);
  tex->show();
  tex->setText(t);
}

void  RDoc::openDiskFile()
{
    QSettings settings(_ORGANIZATION_NAME_,_PROGRAM_NAME_);
    QString dirlast = settings.value("editor/lastdir_open").toString();
    if (dirlast.size() ==0)
          dirlast = QDir::homePath();
    /* next alias type QVariantList  */
    QVariantList lastfiles = settings.value("editor/files/db").toList();
    qDebug() << "### openDiskFile " << dirlast;
    QStringList filenames = QFileDialog::getOpenFileNames( win,
        tr("Open File to read"),dirlast, tr("Files (*)"));
        if( !filenames.isEmpty() ) {
			for (int i =0;i<filenames.count();i++) {
				const QString fx = filenames.at(i);
				QFileInfo iofi(fx);
				lastfiles.append(QVariant(fx));
				//// not loast dir 
				settings.setValue("editor/lastdir_open",iofi.absoluteDir().absolutePath());
				this->openFile(fx);
			}
			
		}
	 if ( lastfiles.size() > 0) {
     //// increase list if having ++
     settings.setValue("editor/files/db",lastfiles);
      }
}

void  RDoc::openFile(const QString f)
{
      qDebug() << "### openFile " <<  f;
      ////// emit insert_text(QString("New file incomming %1..").arg(f));
      emit sendstatus(QString("New file incomming %1..").arg(f));
      docs->openDoc(f);
}


void RDoc::prepare_to_close() {
    qDebug() << "### prepare_to_close";
    QMessageBox::StandardButton resBtn = QMessageBox::question(win,QTR("Speacker"),
                                                               QTR("Are you sure to quit?\n"),
                                                               QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
                                                               QMessageBox::Yes);
    const int permission = (int)resBtn;
    if ( permission == 16384 ) {
       QApplication::quit();
       return;
    }
    emit eventLog(QTR("Continue to Speack..."));
}



bool RDoc::event (QEvent *event) {

       //// qDebug() << "### EventApplication event in >>  " << event->type();
       if (event->type() == QEvent::FileOpen)
       {
       // Get the path of the file that we want to open
       const QString  file_path = static_cast<QFileOpenEvent *> (event)->file();
       //// qDebug() << "### file_path: >>  " << file_path;
       emit signalFileOpen(file_path);
       } else {
         // The system requested us to do another thing, so we just follow the rules
         return QApplication::event (event);
       }
       return true;
   }

   void RDoc::loginternal(QString log) {
      qDebug() << "### RDoc::loginternal >>  " << log;
   }
