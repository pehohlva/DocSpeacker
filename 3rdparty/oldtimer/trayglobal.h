#ifndef TRAYGLOBAL_H
#define TRAYGLOBAL_H

#include <QMainWindow>
#include <QtCore/QString>
#include <QMessageBox>
#include <QEvent>
#include <QApplication>
#include <QFileOpenEvent>
#include <QtCore/QDir>
#include <QtCore/QObject>
#include <QIcon>
#include <QImage>
#include <QSysInfo>
#include <QAction>
#include <QApplication>
#include <QCheckBox>
#include <QCloseEvent>
#include <QComboBox>
#include <QGridLayout>
#include <QIcon>
#include <QLabel>
#include <QLineEdit>
#include <QMenu>
#include <QMessageBox>
#include <QPixmap>
#include <QPushButton>
#include <QSystemTrayIcon>
#include <QTextEdit>
#include <QWidget>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QImage>
#include <QPixmap>
#include <QLabel>
#include <QComboBox>
#include <QCheckBox>
#include <QColor>
#include <QStringList>






static QIcon createColorIcon( QColor color )
{
    QPixmap pixmap(50, 50);
    pixmap.fill(color);
    return QIcon(pixmap);
}










#endif // TRAYGLOBAL_H
