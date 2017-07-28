#include "remainwin.h"
#include "re_application_setting.h"


MainWin::MainWin(QWidget *parent) : QMainWindow(parent) {

      QMenuBar *menubarre = new QMenuBar(this);
      QStatusBar *sta = new QStatusBar(this);
      statusbar = new QLabel("Application Loading...");
      sta->addWidget(statusbar); /// append progressbar from load
      this->setMenuBar(menubarre);
      this->setStatusBar(sta);

      fileMenu = menubarre->addMenu(tr("&File"));
      QAction *act_file_open = new QAction(QTR("Open Fake File"), this);
      act_file_open->setShortcut(QKeySequence(QKeySequence::Open));
      connect(act_file_open, SIGNAL(triggered()),this, SLOT(request_open_file()));
      fileMenu->addAction(act_file_open);
}

void MainWin::resizeEvent(QResizeEvent *event)
{
  Q_UNUSED(event);
  //// qDebug() << "MainWin::resizeEvent event ";
  QRect screens = this->geometry();
  QSettings settings(_ORGANIZATION_NAME_,_PROGRAM_NAME_);
  //// qDebug() << "### screens.width() " << screens.width();
  settings.setValue("editor/width", screens.width());
  settings.setValue("editor/height", screens.height() );
}

void MainWin::closeEvent (QCloseEvent *event) {
    event->ignore();
    emit request_to_close();
}
void MainWin::setstatustext(QString text ) {
   statusbar->setText(text);
}
void MainWin::request_open_file() {
  //// prepare setting and stop other
  emit from_main_new_file();
}
