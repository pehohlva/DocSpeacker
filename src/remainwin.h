#ifndef REMAIN_MAIN_WINDOW_H
#define REMAIN_MAIN_WINDOW_H
#include "documenthandler.h"
#include "re_application_setting.h"
#include <QFileDialog>
#include <QSettings>
#include <QResizeEvent>
#include <QMainWindow>



class MainWin : public QMainWindow
{
  Q_OBJECT
public:
  explicit MainWin(QWidget *parent = 0);
  void closeEvent (QCloseEvent *event);

signals:
    void request_to_close();
    void from_main_new_file();
public slots:
    void request_open_file();
    void setstatustext(QString);
protected:
    void resizeEvent(QResizeEvent *event);
    QMenu* fileMenu;
    QLabel *statusbar; /// to write in
};





#endif
