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

     out << "Value of __DATE__ : " << __DATE__ << endl;
     out << "Value of __TIME__ : " << __TIME__ << endl;

     TracTesserActText::Class_TessDataLang hi;
     //// hi.writedbline();
     hi.number_go_Name(2);
     hi.number_go_Name(3);
     hi.number_go_Name(4);
     hi.number_go_Name(5);
     hi.number_go_Name(6);


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
