#include <QCoreApplication>
#include "textrec.h"
#include "textrecdown.h"
#include "textrechander.h"
#include <QTimer>
#include <QtCore>
#include <iostream>
#include "database_language_tess.h"
#include"textrec_config.h"
/*

struct TessLocale
{
    int lang;
    int coun;
};
//// LocaleListItem item = g_locale_list[index.row() - 2];
*/

int main(int argc, char *argv[])
{
  QCoreApplication app(argc, argv);
  QStringList order = app.arguments();
  Echo out(stdout,QIODevice::WriteOnly);
  TracTesserActText::TessLocale item = TracTesserActText::t_locale_list[10];
  const int summlang = TracTesserActText::tottesslocale;
  int pointer = 1;
  int smp_block_data = 27*3*sizeof(unsigned short);
     out << "Value of smp_block_data : " << smp_block_data << endl;
     out << "Value of sizeof(uint) : " << sizeof(uint) << endl;
     out << "Value of sizeof(unsigned short) : " << sizeof(unsigned short) << endl;
     out << "Value of __TIME__ : " << __TIME__ << endl;

     TracTesserActText::Class_TessDataLang hi;
     //// set_language_tess( int id , QString & nt , QString & ctess )
     QString name = hi.tessTranslate(8);
                   QStringList itemline = name.split(QRegExp("#"), QString::SkipEmptyParts);
     out << "Value name->size:name->str : " << name.size() << ":" << name << endl;
     out << "Value : " << name.size() << ":" << itemline.at(0)  << "-" << itemline.at(1) << endl;
     out << "Value of __DATE__ : " << __DATE__ << endl;
     out << "Value of __TIME__ : " << __TIME__ << endl;

     return 0;

  return app.exec();
}


/* tmp data:
     out << "value of data is :" << summlang << endl;

     QLocale locale;
     do {
          pointer++;
          TracTesserActText::TessLocale p = TracTesserActText::t_locale_list[pointer];
          locale = QLocale((QLocale::Language)p.lang, (QLocale::Country)p.coun);
          out << "lo :" << p.coun << "-" << locale.textDirection() <<  " co:" << locale.bcp47Name() << " - "  << locale.languageToString((QLocale::Language)p.lang) << " ." << endl;
     }while( pointer <  (summlang - 1 ));

     ...........................................

     if (order.size() >= 2 ) {
         TextRecDown *hello = new TextRecDown();
         const QString domake = order.at(1);
             if (domake == "-d") {
                     hello->execute_remote();
                     /// QTimer::singleShot(3, &hello, SLOT(execute_remote()));
             } else if (domake == "-g") {
                      hello->onefile_handler();
                      //// QTimer::singleShot(3, &hello, SLOT(onefile_handler()));
               } else if (domake == "-l") {
                      hello->onefile_handler();
                      //// QTimer::singleShot(3, &hello, SLOT(init_listing()));
               } else {
                 return 0;
               }
       } else {
         out << "Download file arg = -d / build unique language file arg = -g"<< endl;
         out << "Build database to search language item arg = -l"<< endl;
         return 0;
       }





*/
