#include "documenthandler.h"
#include "redoc.h"
#include <QFile>

/// rcc -binary inlinefolder.qrc -o inlinefolder.rcc
////  exec DocSpeacker.app/Contents/MacOS/DocSpeacker
///

int main(int argc, char *argv[])
{
  RDoc a(argc, argv);
  QResource::registerResource("./inlinefolder.rcc");
  

  /*
  QFile loadFile(QStringLiteral("./re_application_setting.h"));
  
    if (!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open save file.");
        return 0;
    } else {
		QByteArray saveData = loadFile.readAll();
		qDebug() << "## saveData" << saveData;
		
	}
   */
  
  return a.exec();

}
