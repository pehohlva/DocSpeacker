#include "documenthandler.h"
#include "rdoc.h"

int main(int argc, char *argv[])
{
  RDoc a(argc, argv);
  return a.exec();
}
