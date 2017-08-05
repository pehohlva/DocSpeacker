#include <QCoreApplication>
#include "textrec.h"
#include "textrecdown.h"
#include "textrechander.h"
#include <QTimer>
#include <QtCore>
#include <iostream>
#include "database_language_tess.h"
#include"textrec_config.h"


int main(int argc, char *argv[])
{
   //// Echo out(stdout,QIODevice::WriteOnly);

#ifndef HELPERTOOLFORFILE_DB
qFatal("config not load HELPERTOOLFORFILE_DB here only tool helper to create file...");
#else
qDebug() << "HELPERTOOLFORFILE_DB";
#endif

QTextStream out(stdout,QIODevice::WriteOnly);

#ifdef Q_OS_MAC
out << "Hi MAC OSX User: " << __DATE__ << endl; /// mac play this
#endif

#ifdef WINOSX_ROOT
out << "Hi Window User: " << __DATE__ << endl;
#endif

#ifndef Q_OS_MAC
#ifdef LINUXOSX_ROOT
   out << "Hi Linux User: " << __DATE__ << endl; /// mac play this??
#endif
#endif


  QCoreApplication app(argc, argv);
  QStringList order = app.arguments();
  //// QStringList dirlistener = app.arguments();
  QLocale sys;
  sys.c();
  
  QStringList il = sys.uiLanguages();
   int pointer =-1;
    do {
          pointer++;
          QString nameb;
          nameb = QLocale::countryToString(reinterpret_cast<QLocale::Country>(pointer));
          out << "value:" << nameb << endl;
          
	  } while( pointer <  257);

      return 0; 

  
    ////TextRecDown hello;
    ///  QTimer::singleShot(0, &hello, SLOT(init_listing()));

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
