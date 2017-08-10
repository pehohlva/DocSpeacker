
#include <QApplication>
#include "drawdocument.h"



int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  DrawDoument xx;
  xx.show();

  return a.exec();
}
