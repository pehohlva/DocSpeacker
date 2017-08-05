#include "database_language_tess.h"
#include "textrec.h"

using namespace TracTesserActText;

static QStringList decodeBB(const QString& str ) {

    QString chr;
    QStringList list = QStringList();
    for (int i = 0; i < str.size(); ++i) {
        chr = QString(str[i]);
        QChar fox(str[i]);
        const ushort code = fox.unicode();
        QString s = QString::number(code);
             list << s;
      }
    return list;
}

Class_TessDataLang::Class_TessDataLang() {  }

QString Class_TessDataLang::tessTranslate( const int qtlocale_nr ) {
  return number_go_Name(qtlocale_nr);
}







QString Class_TessDataLang::getLocaleData(const ushort *data, int size)
{
    Q_ASSERT(size > 3);           //// QChar(uint rc) unicode nr.
    return QString::fromRawData(reinterpret_cast<const QChar*>(data), size);
}

uint Class_TessDataLang::take_line( const int qtlocale_nr , int wo ) {

     int i = -1;
     int need =0;
     do
       {
         i++;
         TessSpeack ttra = tra_tess_list[i];
         const uint la = ttra.lang;
         //// qDebug() << "loop-> :" <<  la;
           if (qtlocale_nr == la) {
             const uint db = ttra.dbline;
             //// qDebug() << "take_line -> found line:" <<  db;
             need = db;
             return need;
           }
          }while( i < summsupport_tess_language);

     return need;
}

void Class_TessDataLang::set_language_tess( int id , QString & nt , QString & ctess ) {

  QString name = this->tessTranslate(id);
                QStringList rec = name.split(QRegExp("#"), QString::SkipEmptyParts);
                Q_ASSERT(rec.size() == 2);
                nt=rec.at(1);
                ctess=rec.at(0);
}

QString Class_TessDataLang::number_go_Name(const int i , int wo)  /// 2
{
   const int chunkline = this->take_line(i,0);
   quint32 idx, size;
   idx = fullrangedb * chunkline;
   size = fullrangedb - 2; //max size
   //// qDebug() << "cursor:" <<  idx << " size;" << size;
   QString now = this->getLocaleData(DB::tessy_db_translate + idx,size);
   //// qDebug() << " now:" <<  now;
     if (now.size() > 0) {
      return now;
     }
   return QString();
}




void Class_TessDataLang::writedbline() {
   const int summline = summsupport_tess_language -1;
   ////  fullrangedb; /// from zero
   int i=-1;
   int sizemaxline=1;
   const int filldefault = 50 + 10;
   QChar zero(35);
   const QByteArray linetranslate = QByteArray("").fill(zero.toLatin1(),filldefault);
   QString blob = QString("\n\n\nstatic const ushort tessy_db_translate[] = { \n");
    do {   /// i love do..
        i++;
        TessSpeack ttra = tra_tess_list[i];
        QByteArray x;
        x.resize(0);
        const uint la = ttra.lang;
        const uint db = ttra.dbline;

             QString nt , ctess;
             set_language_native(la,nt,ctess);
             x.append(ctess.toUtf8());
             x.append(zero);
             x.append(nt.toUtf8());
             QStringList datax = decodeBB( QString(x.data()) );

             sizemaxline = qMax(sizemaxline,x.size());
             QStringList bigline;
             bigline.clear();
           if (la < 1) {
              x.resize(0);
              x.fill(zero.toLatin1(),fullrangedb);
              bigline = decodeBB( QString(x.data()) );
           } else {
                  QStringList zu = decodeBB( QString().fill( zero , fullrangedb - datax.size()  ) );
                  bigline << datax << zu;
             }

            blob.append(bigline.join(","));
            blob.append(",");
            blob.append("\n");

     }while( i <  ( summline - 1 ));
     blob.append("};\n");
     RamStream *ram = new RamStream();
     ram->start();
     ram->ramwrite(blob.toLatin1());
     ram->start();
     ram->PutOnFile(__DIRBUILDTESSY__ + "header.h");
     ram->~RamStream();
     if (blob.size() < 3) {
        qCritical() << "Blob not correct database!";
       }
     /// qDebug() <<  blob <<  ".";
     qDebug() << "Ok:" <<  sizemaxline<<  ".";
}




/* only need to generate db private from class  */
void Class_TessDataLang::set_language_native( int id , QString & nt , QString & ctess ) {

  /*  Tesseract has unicode (UTF-8) support, and can recognize more than 100 languages "out of the box".
      download link generator (QString & ctess)     */
  switch(id) {
      /* 8 - Arabic  الْعَرَبيّة  */
      case 8 : nt = QTUTF8decode("\xD8\xA7\xD9\x84\xD9\x92\xD8\xB9\xD9\x8E\xD8\xB1\xD9\x8E\xD8\xA8\xD9\x8A\xD9\x91\xD8\xA9");
               ctess= QStringLiteral("ara");
               break;
      /* 28 - Czech  čeština */
      case 28 : nt = QTUTF8decode("\xC4\x8D\x65\xC5\xA1\x74\x69\x6E\x61");
                ctess= QStringLiteral("ces");
               break;
      /* 29 - Danish dansk */
      case 29 : nt = QTUTF8decode("\x64\x61\x6E\x73\x6B");
               ctess= QStringLiteral("dan");
               break;
      /* 42 - German  deusch */
      case 42 : nt = QTUTF8decode("\x44\x65\x75\x73\x63\x68");
                ctess= QStringLiteral("deu");
              break;
      /* el - 43 - Greek - Greece     ελληνική/0  \xCE\xB5\xCE\xBB\xCE\xBB\xCE\xB7\xCE\xBD\xCE\xB9\xCE\xBA\xCE\xAE */
      case 43 : nt = QTUTF8decode("\xCE\xB5\xCE\xBB\xCE\xBB\xCE\xB7\xCE\xBD\xCE\xB9\xCE\xBA\xCE\xAE");
               ctess= QStringLiteral("ita_old"); //// not having dir get old italian!
               break;
      /* 31 - English  */
      case 31 : nt = QTUTF8decode("\x65\x6E\x67\x6C\x69\x73\x68");
              ctess= QStringLiteral("eng");
              break;
      /* 111 - Spanish castellà */
      case 111 : nt = QTUTF8decode("\x63\x61\x73\x74\x65\x6C\x6C\xC3\xA0");
              ctess= QStringLiteral("spa");
              break;
      /* 36 - Finnish  suomi */
      case 36 : nt = QTUTF8decode("\x73\x75\x6F\x6D\x69");
              ctess= QStringLiteral("fin");
               break;
      /* 37 - French   français */
      case 37 : nt = QTUTF8decode("\x66\x72\x61\x6E\xC3\xA7\x61\x69\x73");
              ctess= QStringLiteral("fra");
              break;
      /* he - 48 - Hebrew      עִברִית/heb  */
      case 48 : nt = QTUTF8decode("\xD7\xA2\xD6\xB4\xD7\x91\xD7\xA8\xD6\xB4\xD7\x99\xD7\xAA");
              ctess= QStringLiteral("heb");
              break;
      /* hi - 49 - Hindi - India     हिन्दी/hin */
      case 49 : nt = QTUTF8decode("\xE0\xA4\xB9\xE0\xA4\xBF\xE0\xA4\xA8\xE0\xA5\x8D\xE0\xA4\xA6\xE0\xA5\x80");
              ctess= QStringLiteral("hin");
              break;
      /* id - 52 - Indonesian - Indonesia   bahasa_indonesia/ind    \x62\x61\x68\x61\x73\x61\x20\x49\x6E\x64\x6F\x6E\x65\x73\x69\x61 */
      case 52 : nt = QTUTF8decode("\x62\x61\x68\x61\x73\x61\x20\x49\x6E\x64\x6F\x6E\x65\x73\x69\x61");
              ctess= QStringLiteral("ind");
              break;
      /* it - 58 - Italian - Italy  italiano/ita   \x69\x74\x61\x6C\x69\x61\x6E\x6F */
      case 58 : nt = QTUTF8decode("\x69\x74\x61\x6C\x69\x61\x6E\x6F");
              ctess= QStringLiteral("ita");
              break;
      /* ja - 59 - Japanese - Japan   日本語/jpn             \xE6\x97\xA5\xE6\x9C\xAC\xE8\xAA\x9E */
      case 59 : nt = QTUTF8decode("\xE6\x97\xA5\xE6\x9C\xAC\xE8\xAA\x9E");
              ctess= QStringLiteral("jpn");
              break;
      /* ko - 66 - Korean - SouthKorea    한국어/kor   \xED\x95\x9C\xEA\xB5\xAD\xEC\x96\xB4 */
      case 66 : nt = QTUTF8decode("\xED\x95\x9C\xEA\xB5\xAD\xEC\x96\xB4");
              ctess= QStringLiteral("kor");
              break;
      /*nb - 85 - NorwegianBokmal - Norway   norsk/nor \x6E\x6F\x72\x73\x6B */
      case 85 : nt = QTUTF8decode("\x6E\x6F\x72\x73\x6B");
             ctess= QStringLiteral("nor");
              break;
      /*nl - 30 - Dutch - Netherlands  Nederlands/nld  \x4E\x65\x64\x65\x72\x6C\x61\x6E\x64\x73 */
      case 30 : nt = QTUTF8decode("\x4E\x65\x64\x65\x72\x6C\x61\x6E\x64\x73");
            ctess= QStringLiteral("nld");
            break;
      /*pl - 90 - Polish - Poland    polski/pol  \x70\x6F\x6C\x73\x6B\x69 */
      case 90 : nt = QTUTF8decode("\x70\x6F\x6C\x73\x6B\x69");
            ctess= QStringLiteral("pol");
            break;
     /*pt - 91 - Portuguese - Brazil+Portigal   português/por   \x70\x6F\x72\x74\x75\x67\x75\xC3\xAA\x73 */
      case 91 : nt = QTUTF8decode("\x70\x6F\x72\x74\x75\x67\x75\xC3\xAA\x73");
            ctess= QStringLiteral("por");
            break;
      /*ro - 95 - Romanian - Romania  română/ron   \x72\x6F\x6D\xC3\xA2\x6E\xC4\x83 */
      case 95 : nt = QTUTF8decode("\x72\x6F\x6D\xC3\xA2\x6E\xC4\x83");
            ctess= QStringLiteral("ron");
            break;
      /*ru - 96 - Russian - Russia   ру́сский/rus     \xD1\x80\xD1\x83\xCC\x81\xD1\x81\xD1\x81\xD0\xBA\xD0\xB8\xD0\xB9 */
      case 96 : nt = QTUTF8decode("\xD1\x80\xD1\x83\xCC\x81\xD1\x81\xD1\x81\xD0\xBA\xD0\xB8\xD0\xB9");
            ctess= QStringLiteral("rus");
            break;
      /*sk - 108 - Slovak - Slovakia  slovenský/slk   \x73\x6C\x6F\x76\x65\x6E\x73\x6B\xC3\xBD */
      case 108 : nt = QTUTF8decode("\x73\x6C\x6F\x76\x65\x6E\x73\x6B\xC3\xBD");
            ctess= QStringLiteral("slk");
            break;
      /*sv - 114 - Swedish - Sweden   svenska/swe     \x73\x76\x65\x6E\x73\x6B\x61 */
      case 114 : nt = QTUTF8decode("\x73\x76\x65\x6E\x73\x6B\x61");
            ctess= QStringLiteral("swe");
            break;
      /*th - 120 - Thai - Thailand   ภาษาไทย/tha         \xE0\xB8\xA0\xE0\xB8\xB2\xE0\xB8\xA9\xE0\xB8\xB2\xE0\xB9\x84\xE0\xB8\x97\xE0\xB8\xA2 */
      case 120 : nt = QTUTF8decode("\xE0\xB8\xA0\xE0\xB8\xB2\xE0\xB8\xA9\xE0\xB8\xB2\xE0\xB9\x84\xE0\xB8\x97\xE0\xB8\xA2");
            ctess= QStringLiteral("tha");
            break;
      /*tr - 125 - Turkish - Turkey   Türkçe/tur        \x54\xC3\xBC\x72\x6B\xC3\xA7\x65 */
      case 125 : nt = QTUTF8decode("\x54\xC3\xBC\x72\x6B\xC3\xA7\x65");
            ctess= QStringLiteral("tur");
            break;
      /*zh - 25 - Chinese - China   汉语/chi_sim  chi_vert chi_tra  chi_tra_vert         \xE6\xB1\x89\xE8\xAF\xAD */
      case 25 : nt = QTUTF8decode("\xE6\xB1\x89\xE8\xAF\xAD");
            ctess= QStringLiteral("chi_sim");
            break;
      /* hu - 50 - Hungarian - Hungary     magyar/hun        \x4D\x61\x67\x79\x61\x72 */
      case 50 : nt = QTUTF8decode("\x4D\x61\x67\x79\x61\x72");
          ctess= QStringLiteral("hun");
          break;
      default:  nt = QStringLiteral("null"); //// not having dir or function
                ctess = QStringLiteral("null"); //// not having dir

      }
}
