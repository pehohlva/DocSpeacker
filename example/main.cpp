
#include <QApplication>

#include "grabitem.h"
#include "qindexlanguage.h"


#include <stdio.h>
#include <string.h>
#include "include/compact_lang_det.h"
#include "include/ext_lang_enc.h"
#include "include/unittest_data.h"
#include "include/encodings.pb.h"



const char* kTeststr_en =
  "confiscation of goods is assigned as the penalty part most of the courts "
  "consist of members and when it is necessary to bring public cases before a "
  "jury of members two courts combine for the purpose the most important cases "
  "of all are brought jurors or";



int main(int argc, char **argv) {

   /// initScriptMap();
  /// QApplication app( argc, argv );
  QString xxx = QString::fromStdString(kTeststr_en);
  WorldIdiom::QIndexLanguage  fiore;
  qDebug() << "[-" << xxx << "-]";


  const QString xtext = fiore.DetectStructure( kTeststr_en );

  qDebug() << "[-" << xtext << "-]";
  return 0;
  /// return app.exec();
}
