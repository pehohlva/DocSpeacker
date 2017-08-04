
#include <QList>
#include <QMap>
#include <QTextStream>
#include <QString>
#include <QStringList>
#include <QDir>
#include <QTime>
#include <QDebug>
#include <QCoreApplication>

#include <QFuture>
#include <QtConcurrent>

#include <ostream>
using namespace std;

/* FOREGROUND */
#define RST  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define FRED(x) KRED x RST
#define FGRN(x) KGRN x RST
#define FYEL(x) KYEL x RST
#define FBLU(x) KBLU x RST
#define FMAG(x) KMAG x RST
#define FCYN(x) KCYN x RST
#define FWHT(x) KWHT x RST

#define BOLD(x) "\x1B[1m" x RST
#define UNDL(x) "\x1B[4m" x RST


static volatile int tot_file;
static volatile int xmatrix;

/*
    Utility function that rotate 1./2-3\4| inside console by wait..
*/
static QString looproad( int dist ) {

  if ( dist == 1 ) {
      return QString(QChar(822));
  }
  if ( dist == 2 ) {
      return QString(QChar(92));
  }
  if ( dist == 3 ) {
      return QString(QChar(124));
  }
  if ( dist == 4 ) {
      return QString(QChar(47));
  }
  return QString(QChar(35));
}

/*
    Utility function that recursivily searches for files.
*/
QStringList findFiles(const QString &startDir, QStringList filters)
{
    QStringList names;
    QDir dir(startDir);
    QTextStream out(stdout);

    foreach (QString file, dir.entryList(filters, QDir::Files)) {
            //// qDebug() << "||| file: " << file;
            names += startDir + '/' + file;
            xmatrix++;
                if (xmatrix == 5) {
                  xmatrix = 1;
                }
            QString cop = file;
            cop.resize(4);
            out << "\033[93m" << looproad(xmatrix) << "\033[0m" <<  " " << cop.toUpper() << "  .....\r";
        }

    foreach (QString subdir, dir.entryList(QDir::AllDirs | QDir::NoDotAndDotDot)) {
            names += findFiles(startDir + '/' + subdir, filters);
        }
    return names;
}


int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);

    QString initdir = QString("/usr/local");
    QStringList xfilter;
    xfilter << "*.h" << "*.txt" << "*.pro";
    QStringList fu_files_found;


    int warmsfiles = 0;
    qDebug() << "finding files init ...";
    {
    QTime time;
    time.start();
    fu_files_found.clear();
    fu_files_found = QtConcurrent::run(findFiles, initdir , xfilter);
    tot_file = fu_files_found.count();
    qDebug() << tot_file << "files";
    warmsfiles = time.elapsed();
    qDebug() << "finding files misec:" << warmsfiles;
    }


}
