#include "documenthandler.h"
#include "rdoc.h"

int main(int argc, char *argv[])
{
  RDoc a(argc, argv);
  QResource::registerResource("./inlinefolder.rcc");
  return a.exec();
  /// rcc -binary inlinefolder.qrc -o inlinefolder.rcc
}
