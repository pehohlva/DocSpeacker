#include <QCoreApplication>
#include "textrec.h"
#include "textrecdown.h"
#include "textrechander.h"

#include <iostream>
#include <vector>
#include <clocale>
#include <cwchar>

void print_as_wide(const char* mbstr)
{
    std::mbstate_t state = std::mbstate_t();
    int len = 1 + std::mbsrtowcs(NULL, &mbstr, 0, &state);
    std::vector<wchar_t> wstr(len);
    std::mbsrtowcs(&wstr[0], &mbstr, wstr.size(), &state);
    std::wcout << "Wide string: " << &wstr[0] << '\n'
               << "The length, including '\\0': " << wstr.size() << '\n';
}


int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  qRegisterMetaType<Tessy>();
  TextRecDown hello;
     ////// const char* mbstr = u8"z\u00df\u6c34  \U0001f402"; // 🍌🍌🍌🍌🍌🍌🍌🍌🍌    //// \U0001f34c  \U0001F34C

  QTimer::singleShot(0, &hello, SLOT(onefile_handler()));
      ///// QString str = QString::fromUtf8(mbstr);

      ///// qDebug() <<  "uncoso:"  << str;

      //// std::setlocale(LC_ALL, "en_US.utf8");  //// "\uD83C\uDF4C"
      //// const char* mbstr = u8"z\u00df\u6c34  \U0001F34D\U0001F1F9"; // or u8"zß水🍌"  //// \U0001f34c  \U0001F34C
      //// print_as_wide(mbstr);




     //// return 0;


  /*
  QList<QNetworkInterface> allInterfaces = QNetworkInterface::allInterfaces();
  QNetworkInterface eth;

  foreach(eth, allInterfaces) {
      QList<QNetworkAddressEntry> allEntries = eth.addressEntries();
      QNetworkAddressEntry entry;
      foreach (entry, allEntries) {
          qDebug() << eth.name() << entry.ip().toString() << "/" << entry.netmask().toString();
      }
  }

  */
     return a.exec();
}


