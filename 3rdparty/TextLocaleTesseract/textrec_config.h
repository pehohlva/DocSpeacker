#ifndef TESSAPPONFIGCORE_H
#define TESSAPPONFIGCORE_H

#include <QtAlgorithms>
#include <QString>
#include <QChar>
#include <QStringList>
#include <QDebug>
#include <QtAlgorithms>
#include <QString>
#include <QList>
#include <QtCore>
#include <QDir>
#include <QtGlobal>
#include <QtAlgorithms>
#include <QString>
#include <QChar>
#include <QStringList>
#include <QDebug>
#include <QtAlgorithms>
#include <QString>
#include <QList>
#include <QtCore>

const int SUPPOSDASSRTNOTLOADEXITTOME1 = 7653168;

namespace TracTesserActText {
   // conflict on QLocale #include <QtCore/qglobal.h> /qglobal.h

const int MINIMUM_CHAR_UNIQUE_FOR_LANGUAGE = 5;
/* define range from unicode Nr.  Latin status 3.8.2017 */

const int LATIN_BASIC_START_POINT = 1;  // Latin Basic
const int LATIN_BASIC_STOP_POINT = 128; // after ~ tilde

const int LATIN_EXTA_START_POINT = 192;  // Latin Extended-A Major alphabets	Latin Czech Dutch Polish Turkish German Italian Lithuanian Latvian
const int LATIN_EXTA_STOP_POINT = 383;

const int LATIN_EXTB_START_POINT = 1025;  // Latin Extended-B Major alphabets	Africa alphabet Pan-Nigerian Americanist Khoisan Pinyin Romanian
const int LATIN_EXTB_STOP_POINT = 1110;

const int LATIN_MAXSUPPOSE_POINT = 2305;

/* Alphabetic Presentation Forms is a Unicode block containing standard ligatures for the Latin, Armenian, and Hebrew scripts.
 */
const int LATIN_EXTE_START_POINT = 64256; // Latin Extended-E  Armenian (5 char.) Hebrew (46 char.) Latin (7 char.)
                                          // alert Latin Extended-E old german char i hope qt unicode is category script ok..
const int LATIN_EXTE_STOP_POINT = 65533;  // at end from all unicode list??


#define __APPNAME__ \
              QString("TessRecoText")

#define __EXTTESSAPP__ \
              QString(".tess")

//// QString(QString(QDir::home()) + QString("/"))

#define _USERHOME_ \
               QString("/Users/dev/")

#define __DIRBASICTESSY__ \
              _USERHOME_ + QString("Applications/Language/Tess/")

#define __DIRBUILDTESSY__ \
               _USERHOME_ +  QString(".tess/language/")




static QString html_encode(const QString& str, int modus = 1) {

    QString chr;
    QStringList list = QStringList();
    for (int i = 0; i < str.size(); ++i) {
        chr = QString(str[i]);
        QChar fox(str[i]);
        const ushort code = fox.unicode();
        QString s = QString::number(code);
          if (modus == 1) {
             list << "&#" + s + ";";
          } else {
             list << s;
          }

    }

      if (modus == 1) {
        return list.join("");
      } else {
        return list.join(" , ");
      }

}

static QString lang_encode(const QString& str ) {
   return html_encode(str,2);
}


typedef QPair<QString,QString> RootScript;
typedef QVector<RootScript > Locale_Script;








#define CHECKTIME(x)  \
    QElapsedTimer CONCAT(sb_, __LINE__); \
    CONCAT(sb_, __LINE__).start(); \
    x \
    qDebug() << __FUNCTION__ << ":" << __LINE__ << " Elapsed time: " <<  CONCAT(sb_, __LINE__).elapsed() << " ms.";




/*  // usage of this macro
    CHECKTIME(
    // any code
    for (int i=0; i<1000; i++)
    {
       timeConsumingFunc();
    }
)
  */





}

#endif
