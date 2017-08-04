#include <QCoreApplication>
#include "textrec.h"
#include "textrecdown.h"
#include "textrechander.h"
#include <QTimer>
#include <QtCore>
#include <iostream>




int main(int argc, char *argv[])
{
  QCoreApplication app(argc, argv);
  QStringList order = app.arguments();
  Echo out(stdout,QIODevice::WriteOnly);

     out << "Value of __DATE__ : " << __DATE__ << endl;
     out << "Value of __TIME__ : " << __TIME__ << endl;

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

  return app.exec();
}
