#include "textrecdown.h"

#include <QTextToSpeech>
#include <QVector>
#include <QLocale>
#include <QVector>
#include <QVectorIterator>
#include <QMap>
#include "textrechander.h"

#include "textrec.h"


TextRecDown::TextRecDown(QObject *parent) : QObject(parent)
{
  QTime myTimer;
  myTimer.start();
  QTextStream out(stdout);

     TextRecHander *regmanager = new TextRecHander(this);
     if ( regmanager->is_networkAccessible()  ) {
         out << "networkAccessible is ok..\n";
       } else {
         out << "networkAccessible is down :-(.\n";
       }

     const QString porto = "https://raw.githubusercontent.com/tesseract-ocr/langdata/master/por/desired_characters";
     regmanager->get_remote_file(porto);


     QVector<QString> localeVector;
     QVector<int> localeids;
       int steps=-1;
       foreach (const QLocale &locale, localein ) {
               steps++;
               localeVector.insert(steps,locale.bcp47Name());
         }

       const int xmany = localeVector.size();
       qSort( localeVector );
       out << "Found tot:" << xmany << " item.\n";
       QVectorIterator<QString> i(localeVector); {
       while (i.hasNext())   {
             const  QString smname = QString( i.next() );  ///  = ;
             QLocale curr(smname);
             QString nativename;
             QString tesseract_ocr_dir;
             QString country = QLocale::countryToString(curr.country());
             int nr = (int)curr.language();
             if (localeids.indexOf(nr) ==-1) {
                  localeids.prepend(nr);
                    this->set_language_native(nr,nativename,tesseract_ocr_dir);
                    /// Tessy record;
                    //// record.set(nr,nativename,tesseract_ocr_dir);
                    ///// locale_full.insert(nr,record);
                    /// qDebug() << record;


                    out << country <<  " / ";
                    out << tesseract_ocr_dir <<  " - ";
                    out << nr <<  " - ";
                    out << nativename <<  "\n";


               }

         }
       }



           out << "(" << myTimer.elapsed() <<  ") time \n";
           out.flush();

}


void TextRecDown::register_Locale() {

  QTextStream out(stdout);
  QTextToSpeech *tess = new QTextToSpeech(this);
  locale_jobs.clear();
  locale_jobs = tess->availableLocales();

  QVector<QString> localeNameVector;
  QVector<int> locale_id_ref;
  int steps=-1;  // begin to sort order name
    foreach (const QLocale &locale, locale_jobs ) {
            int nr = (int)locale.language();
            //// unique language!!!
              if (locale_id_ref.indexOf(nr) ==-1) {
                 locale_id_ref.prepend(nr);
                 steps++;
                 localeNameVector.insert(steps,locale.bcp47Name());
              }


      }

    const int xmany = localeNameVector.size();
    qSort( localeNameVector );
    out << "Found tot:" << xmany << " item.\n";


}

/* int id = (int)QLocale::language()  unique -   QString nt native language name -  QString ctess Tesseract dir */
void TextRecDown::set_language_native( int id , QString & nt , QString & ctess ) {

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
               ctess= QStringLiteral("null"); //// not having dir
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


/*
https://mothereff.in/utf-8
id - 52 - Indonesian - Indonesia   bahasa_indonesia/ind    \x62\x61\x68\x61\x73\x61\x20\x49\x6E\x64\x6F\x6E\x65\x73\x69\x61
it - 58 - Italian - Italy  italiano/ita   \x69\x74\x61\x6C\x69\x61\x6E\x6F
ja - 59 - Japanese - Japan   日本語/jpn             \xE6\x97\xA5\xE6\x9C\xAC\xE8\xAA\x9E
ko - 66 - Korean - SouthKorea    한국어/kor   \xED\x95\x9C\xEA\xB5\xAD\xEC\x96\xB4
nb - 85 - NorwegianBokmal - Norway   norsk/nor \x6E\x6F\x72\x73\x6B
nl - 30 - Dutch - Netherlands  Nederlands/nld  \x4E\x65\x64\x65\x72\x6C\x61\x6E\x64\x73
nl-BE - 30 - Dutch - Belgium   Nederlands/nld  \x4E\x65\x64\x65\x72\x6C\x61\x6E\x64\x73
pl - 90 - Polish - Poland    polski/pol  \x70\x6F\x6C\x73\x6B\x69
pt - 91 - Portuguese - Brazil   português/por   \x70\x6F\x72\x74\x75\x67\x75\xC3\xAA\x73
pt-PT - 91 - Portuguese - Portugal  português/por   \x70\x6F\x72\x74\x75\x67\x75\xC3\xAA\x73
ro - 95 - Romanian - Romania  română/ron   \x72\x6F\x6D\xC3\xA2\x6E\xC4\x83
ru - 96 - Russian - Russia   ру́сский/rus     \xD1\x80\xD1\x83\xCC\x81\xD1\x81\xD1\x81\xD0\xBA\xD0\xB8\xD0\xB9
sk - 108 - Slovak - Slovakia  slovenský/slk   \x73\x6C\x6F\x76\x65\x6E\x73\x6B\xC3\xBD
sv - 114 - Swedish - Sweden   svenska/swe     \x73\x76\x65\x6E\x73\x6B\x61
th - 120 - Thai - Thailand   ภาษาไทย/tha         \xE0\xB8\xA0\xE0\xB8\xB2\xE0\xB8\xA9\xE0\xB8\xB2\xE0\xB9\x84\xE0\xB8\x97\xE0\xB8\xA2
tr - 125 - Turkish - Turkey   Türkçe/tur        \x54\xC3\xBC\x72\x6B\xC3\xA7\x65
zh - 25 - Chinese - China   汉语/chi_sim  chi_vert chi_tra  chi_tra_vert         \xE6\xB1\x89\xE8\xAF\xAD
zh-HK - 25 - Chinese - HongKong   汉语/chi_sim  chi_vert chi_tra  chi_tra_vert         \xE6\xB1\x89\xE8\xAF\xAD
zh-TW - 25 - Chinese - Taiwan    汉语/chi_sim  chi_vert chi_tra  chi_tra_vert         \xE6\xB1\x89\xE8\xAF\xAD

fi - 36 - Finnish - Finland      suomi/fin             \x73\x75\x6F\x6D\x69
fr - 37 - French - France      français/fra     \x66\x72\x61\x6E\xC3\xA7\x61\x69\x73
fr-CA - 37 - French - Canada   français/fra     \x66\x72\x61\x6E\xC3\xA7\x61\x69\x73
he - 48 - Hebrew - Israel     עִברִית/heb          \xD7\xA2\xD6\xB4\xD7\x91\xD7\xA8\xD6\xB4\xD7\x99\xD7\xAA
hi - 49 - Hindi - India     हिन्दी/hin      \xE0\xA4\xB9\xE0\xA4\xBF\xE0\xA4\xA8\xE0\xA5\x8D\xE0\xA4\xA6\xE0\xA5\x80
hu - 50 - Hungarian - Hungary     magyar/hun        \x4D\x61\x67\x79\x61\x72

ar-SA - 8 - Arabic - SaudiArabia  arabic/ara  <big>الْعَرَبيّة</big> -> \xD8\xA7\xD9\x84\xD9\x92\xD8\xB9\xD9\x8E\xD8\xB1\xD9\x8E\xD8\xA8\xD9\x8A\xD9\x91\xD8\xA9
cs - 28 - Czech - CzechRepublic   čeština/ces   \xC4\x8D\x65\xC5\xA1\x74\x69\x6E\x61
da - 29 - Danish - Denmark     dansk/dan    \x64\x61\x6E\x73\x6B
de - 42 - German - Germany     deusch/deu     \x44\x65\x75\x73\x63\x68
el - 43 - Greek - Greece     ελληνική/0             \xCE\xB5\xCE\xBB\xCE\xBB\xCE\xB7\xCE\xBD\xCE\xB9\xCE\xBA\xCE\xAE
en - 31 - English - UnitedStates    english/eng       \x65\x6E\x67\x6C\x69\x73\x68
en-AU - 31 - English - Australia     english/eng    \x65\x6E\x67\x6C\x69\x73\x68
en-GB - 31 - English - UnitedKingdom   english/eng   \x65\x6E\x67\x6C\x69\x73\x68
en-IE - 31 - English - Ireland   english/eng        \x65\x6E\x67\x6C\x69\x73\x68
en-IN - 31 - English - India   english/eng          \x65\x6E\x67\x6C\x69\x73\x68
en-ZA - 31 - English - SouthAfrica   english/eng    \x65\x6E\x67\x6C\x69\x73\x68
es - 111 - Spanish - Spain    castellà/spa          \x63\x61\x73\x74\x65\x6C\x6C\xC3\xA0
es-AR - 111 - Spanish - Argentina  castellà/spa      \x63\x61\x73\x74\x65\x6C\x6C\xC3\xA0
es-MX - 111 - Spanish - Mexico    castellà/spa       \x63\x61\x73\x74\x65\x6C\x6C\xC3\xA0


*/

}
