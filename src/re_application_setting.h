#ifndef RE_APPLICATION_SETTING_H
#define RE_APPLICATION_SETTING_H

#include <QFileDialog>
#include <QSettings>
#include <QResizeEvent>
#include <QMessageBox>
#include <QApplication>
#include <QMenu>
#include <QPushButton>
#include <QWidgetAction>
#include <QProgressBar>
#include <QSystemTrayIcon>
#include <QStyle>
#include <QTextEdit>
#include <QPlainTextEdit>
#include <QString>
#include <QKeySequence>
#include <QObject>
#include <QDebug>
#include <QDesktopWidget>
#include <QIcon>
#include <QPushButton>
#include <QLabel>
#include <QCursor>
#include <QEvent>
#include <QPoint>
#include <QDialog>
#include <QWidget>
#include <QTimer>
#include <QCloseEvent>
#include <QMainWindow>
#include <QMessageBox>
#include <QFileinfo>
#include <QDir>
#include <QKeySequence>

static inline QString QTR( const QString t ) {
   QString newone("QTR:");
   return newone.append(t);
}

#define  WEBAGENTNAME "Google"
#define _PROGRAM_NAME_ QString("DocSpeacker")
#define _PROGRAM_NAME_DOMAINE_ QString("qt.io")
#define _ORGANIZATION_NAME_ QString("Avasoft")
#define _PROGRAM_VERSION_ QString("version 0.2.1 / go git")
#define _PROGRAM_OWNER_ QString("version 0.2.1")
#define _PROGRAM_TITLE_ QString("DocSpeacker version 0.2")
#define Q_WORKS_PEND QString("open")
#define _PROGRAM_SHORT_NAME QString("docspeacker02")
#define TUMNAIL_SIZE 120
#define DOCREAD_LIMIT 80

/*
QSettings settings(_ORGANIZATION_NAME_,_PROGRAM_NAME_);

QCoreApplication::setOrganizationName(_ORGANIZATION_NAME_);
  QCoreApplication::setOrganizationDomain(_PROGRAM_NAME_DOMAINE_);
  QCoreApplication::setApplicationName(_PROGRAM_NAME_); */

#define WORK_CACHEDIR \
               QString( "%1/.%2/" ).arg(QDir::homePath(),_PROGRAM_SHORT_NAME)



#endif
