#include <QCoreApplication>
#include "textrec.h"
#include "textrecdown.h"
#include "textrechander.h"

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  qRegisterMetaType<Tessy>();
  TextRecDown hello;

  QList<QNetworkInterface> allInterfaces = QNetworkInterface::allInterfaces();
  QNetworkInterface eth;

  foreach(eth, allInterfaces) {
      QList<QNetworkAddressEntry> allEntries = eth.addressEntries();
      QNetworkAddressEntry entry;
      foreach (entry, allEntries) {
          qDebug() << eth.name() << entry.ip().toString() << "/" << entry.netmask().toString();
      }
  }


  return 0;
}
