#include "textrecdown.h"

#include <QTextToSpeech>
#include <QVector>
#include <QLocale>
#include <QVector>
#include <QVectorIterator>
#include <QMap>
#include "textrechander.h"
#include <QLatin1Char>
#include "textrec.h"


TextRecDown::TextRecDown(QObject *parent) : QObject(parent) ,
                        getremoteFile(false),
                        append_latin_lang(true),
                        out(stdout,QIODevice::WriteOnly)
{
    out.setCodec("UTF-8");
    crono.start();
    this->register_Locale();
    this->register_LinktoGet();
    out << "init class -> time(" << crono.elapsed() <<  ") time \n";
    out.flush();
    this->pause_now();
}

void TextRecDown::pause_now() {
  out << "\n";
  out << "\n Pause print time elapsed(" << (crono.elapsed() / 1000) <<  ".sec) time \n";
  out << "\n";
  out.flush();
  QTimer::singleShot(2000,this, SLOT(pause_now()));
}

void TextRecDown::shutdown() {
  //// exit or other!
  QCoreApplication::quit();
}

void TextRecDown::execute_remote() {
  GetTessyFile *tesremote = new GetTessyFile();
   if (need_uri_list.size() > 3) {
      tesremote->doDownList(need_uri_list);
          connect(tesremote, SIGNAL(jobtessReady()),this,SLOT(onefile_handler()));
    } else {
       out << "Unable to find url list ... wrong params in:" << __FUNCTION__ << " \n";
       out.flush();
       this->shutdown();
     }
}



void TextRecDown::vector_char_from( const QString dir ) {

     Vector_Qstring UniqueChar;
     UniqueChar.clear();
     RamStream *xram = new RamStream();
     QString f_letter = __DIRBASICTESSY__ + QString("@key@/desired_characters").replace("@key@",dir);
     QString dest_letter = __DIRBUILDTESSY__ + QString("@key@/desired_characters").replace("@key@",dir) + __EXTTESSAPP__; //// other DIR!!!
     QString ftraning = __DIRBASICTESSY__ + QString("@key@/@key@.training_text").replace("@key@",dir); ////  training text
     out << "Generate language:" << dir << "\n";
     out.flush();

     xram->LoadFile(f_letter);
     const QString chunk = QString(xram->stream().data());
     QByteArray xn;
     xram->clear();
     xram->LoadFile(ftraning);
     const QString trtext = QString(xram->stream().data());
     xram->clear();
     if (chunk.size() > 0 ) {
            //// handle char from desired_characters lang!!!!
            QStringList lines = chunk.split("\n",QString::SkipEmptyParts);  /// split line
                    for(int index = 1;index < lines.length();index++)  {
                      const QString data = QString(lines.at(index)).trimmed(); //// get char letter by in loop ok
                      QByteArray gos(data.toUtf8());  //// by in loop ok
                      const QString item(gos.toHex(';').toUpper().data());
                          if (!UniqueChar.contains(item.trimmed()) && data.size() < 2) {
                              UniqueChar.prepend(item.trimmed());
                          }
                     }


       }
         //// append new char if find in training_text
         if (trtext.size() > 0 ) {
             QStringList listwo = trtext.split(QRegExp("\\s+"), QString::SkipEmptyParts);
             QSet<QString> stringnx = QSet<QString>::fromList(listwo);
             foreach (const QString &value, stringnx) {
                 const int co = value.size();
                 if (co > 0 ) {
                       for(int index = 0;index < co;index++)  {
                            const QString letter(value.at(index));
                            QByteArray gos(letter.trimmed().toUtf8());  //// by in loop ok
                            const QString item(gos.toHex(';').toUpper().data());
                              if (!UniqueChar.contains(item.trimmed()) && letter.size() < 2) {
                                UniqueChar.prepend(item.trimmed());
                              }
                         }
                   }
               }

         }


      qDebug() << "desidered  chunk.size():" <<  chunk.size();
      qDebug() << "text training:" << trtext.size();
      qDebug() << "D:" << dir <<  "-UniqueChar->:" << UniqueChar.size();

      if ( UniqueChar.size() < 55 ) {
          qDebug() << "Need text to language ->" << dir << "!!!!!";
        }


      qSort(UniqueChar);
      foreach (const QString &value, UniqueChar ) {
                       QString linehex = value;
                       QString c = linehex.remove(QChar(';'));
                       QByteArray cap = QByteArray::fromHex( c.toUtf8() );
                       const QString letter(cap.data());
                       xn.append(value);
                       xn.append(QByteArray("|"));
                       xn.append(letter.toUtf8());
                       xn.append(QByteArray("\n")); //// line end!
                       /////  qDebug() << "w:" << value << "-" << letter;
        }

      xram->clear();
      xram->ramwrite(xn);
      xram->PutOnFile(dest_letter);
      xram->clear();
      UniqueChar.clear();
}



void TextRecDown::onefile_handler() {
     /// const QString dir= QString("pol");
     CHECKTIME(
                 //// generate all 579  ms.
                 if (localeEnableVector.size() > 0 ) {
                         //// generate all desired_characters argument
                        foreach (const PaarString &coppia, localeEnableVector ) {
                           const QString di = coppia.second;
                           const QString dx = coppia.first;
                           this->vector_char_from(di);  //// to fast!!!
                      }
                   }
         )
     /*
     RamStream *xram = new RamStream();
     xram->LoadFile(f_tra);
     const QString chutx = QString(xram->stream().data());
     xram->clear();
     Vector_Qstring UniqueChar;
     QStringList listwo = chutx.split(QRegExp("\\s+"), QString::SkipEmptyParts);
     QSet<QString> stringnx = QSet<QString>::fromList(listwo);
     foreach (const QString &value, stringnx) {
         const int co = value.size();
         if (co > 0 ) {
               for(int index = 0;index < co;index++)  {
                    QString letter(value.at(index));
                    if (!UniqueChar.contains(letter)) {
                        UniqueChar.prepend(letter);
                      }
                 }
           }
         ////  qDebug() << "s:" << co << "-" << value;
       }
     qSort(UniqueChar);
       QByteArray xn;
       foreach (const QString &x, UniqueChar ) {
           QByteArray gos(x.toUtf8());
           xn.append(gos.toHex(';').toUpper());
           xn.append(QByteArray("|"));
           xn.append(x.toUtf8());
           xn.append(QByteArray("\n")); //// line end!
         }
       qDebug() << "->" << QString(xn.constData());
 */


     /*
      * qDebug() << "Found letter:" << UniqueChar.size() << "\n";
         qDebug() << stringnx.size() << "<->" << listwo.size() <<  "\n";
     QByteArray o("DDD   الْعَرَبيّة");
     out <<  "display hex:" << o.toHex(';').toUpper() << "\n";
     */
     out <<  "\n";
     out <<  "\n";
     out <<  "\n";
     out.flush();

    this->shutdown();
}

//// search all uniode used...
///  need all QString("@key@/desired_characters") file
void TextRecDown::beginextract_tess() {
     need_uri_list.clear();
     RamStream *xram = new RamStream();
     //// RamStream *boxram_nolatin = new RamStream();
     /// QStringList latinkey;
     //// QStringList notlatinkey;
     QByteArray latinX;
     QByteArray nolatinX;
     foreach (const PaarString &coppia, localeEnableVector ) {
                 const QString dir = coppia.second;
                 const QString dx = coppia.first;
                 ///// QString filede = __DIRBASICTESSY__ + QString("@key@/desired_characters").replace("@key@",dir);
                 QString filede = __DIRBASICTESSY__ + QString("@key@/@key@.training_text").replace("@key@",dir);
                 QFileInfo fi(filede);
                   if (fi.exists()) {
                              if (fromlatin_dir.contains(dir)) {
                                 latinX.append(xram->append_chunk(filede));
                              } else {
                                 nolatinX.append(xram->append_chunk(filede));
                               }
                     /// qDebug() <<  "file need ok:" << filede;
                   } else {
                       qDebug() <<  "lost file :-( :" << filede;
                     }

     }
     xram->clear();
     out <<  "chunker latinX:" << latinX.size() << " latinok:" << is_Latin(latinX) << "\n";
     QString txter = QString(latinX.data());
     //// out <<  "chunker latinA" << latinX.size();
     //// out <<  "chunker latinT" << txter.size();
     txter.resize(500);
     /////7out <<  "txter :" << txter.replace("\n"," ");

     QVector<int> uniquechar;
     for (int i = 0; i < latinX.length(); i++) {
              const char lex = latinX.at(i);
             //// const QByteArray lett = ;
             QLatin1Char vox(lex);   /// #include <QLatin1Char> QChar
             int le = vox.unicode();
               if (uniquechar.indexOf(le) ==-1) {
                   const QString resm(lex);
                   //// qDebug() <<  "rec:" << resm.size() << "-" << resm;
                   uniquechar.prepend(le);
               }

       }
     out << "UUUUXXXX  unique chars found size: " << uniquechar.size() <<    "\n";
     out <<  "chunker latinX:.training_text uniquechar"  << latinX.size() <<  "\n";
     qSort(uniquechar);
     out.flush();
     this->shutdown();
}

/*  registra i QLocale (sopportati da QTextToSpeech) solo la lingua
 * per tradurre le cartelle dei rispettivi testi e unicodici (unicode) */
void TextRecDown::register_Locale() {

  QTextStream out(stdout);
  fromlatin_dir.clear();
  fromlatin_qlocs.clear();
  ///// all discovery from latin by @key@.training_text
  fromlatin_dir << "pol" <<  "fin" <<  "dan" << "nor" <<  "por" <<  "ron" <<  "nld" <<  "spa" <<  "ind" <<  "deu" <<  "fra" <<  "swe" << "ita" << "eng";
  fromlatin_qlocs <<  "pl" <<  "fi" <<  "da" << "nb" <<  "pt-PT" <<  "ro" <<  "nl-BE" <<  "es-AR" <<  "id" << "de" <<  "fr-CA" <<  "sv" <<  "it" <<  "en";
  QTextToSpeech *tess = new QTextToSpeech(this);
  locale_jobs.clear();
  localeEnableVector.clear();
  localeNameVector.clear();
  locale_jobs = tess->availableLocales();
  QVector<int> locale_id_ref;
  int steps=-1;  // begin to sort order name
    foreach (const QLocale &locale, locale_jobs ) {
            int nr = (int)locale.language();
            //// unique language!!!
              if (locale_id_ref.indexOf(nr) ==-1) {
                 locale_id_ref.prepend(nr);
                 steps++;
                 QString nativename;
                 QString tesseract_ocr_dir; ////
                 this->set_language_native(nr,nativename,tesseract_ocr_dir);
                 localeEnableVector.prepend(qMakePair(locale.bcp47Name(),tesseract_ocr_dir)); //// QVector<QPair<QString,QString> >
                 localeNameVector.insert(steps,locale.bcp47Name());
              }
      }
    //// usefull latin text to identify chars ...
    if (append_latin_lang) {
        steps++;
        localeNameVector.insert(steps,QString("Latin_EU"));
        localeEnableVector.prepend(qMakePair(QString("Latin_EU"),QString("lat")));
      }
    steps = 0;
    const int xmany = localeNameVector.size();
    qSort( localeNameVector );
    out << "Found tot language support to speeck:" << xmany << " item.\n";
    out.flush();
}

/*  Genera i link dei file lingua da scaricare onde riconoscere quale lingua contiene quali caratteri
 * su https://github.com/tesseract-ocr/langdata i quali si aggiornano spesso ....
 * in fondo aggiorna solo QStringList need_uri_list; da avere in caso si vuole aggiornare ...
 * questi file danno la possibilita da riconoscere i testi da classificare nella lingua giusta
 */
void TextRecDown::register_LinktoGet() {

   need_uri_list.clear();
   const QString baseuri = QString("https://raw.githubusercontent.com/tesseract-ocr/langdata/master/");
   const int summ_support = localeNameVector.size(); /// only name
   const int summ_support2 = localeEnableVector.size(); /// pair chain
   if (  summ_support !=  summ_support2  ) {
       out << "Error wrong summ of item:" << summ_support << "?. on function " << __FUNCTION__ << " \n";
       out.flush();
       return;
     }
   out <<  "conc summ of item :" << summ_support << "-" << summ_support2 << "\n";
   foreach (const PaarString &coppia, localeEnableVector ) {
               QString key = coppia.first;
               QString dir = coppia.second;
                /// Conditional ternary operator latin or not
                QString lat =  fromlatin_dir.contains(dir) == true?  "latin" : "No latin";
                out << lat << "list:" << key << "-" << dir << "\n";
                if (dir !="null") {
                QString page1 = baseuri + QString("@key@/@key@.training_text");  //// testi nativi con lunge frasi..
                page1.replace("@key@",dir);
                QString page2 = baseuri +  QString("@key@/@key@.unicharambigs");   //// magari inutile al mio scopo
                page2.replace("@key@",dir);
                QString page3 = baseuri + QString("@key@/@key@.word.bigrams");   //// array di parole composte
                page3.replace("@key@",dir);
                QString page4 = baseuri + QString("@key@/desired_characters");   /// caratteri desiderati
                page4.replace("@key@",dir);
                QString page5 = baseuri + QString("@key@/@key@.wordlist");   //// lista di parole uniche
                page5.replace("@key@",dir);
                //// la frequenza delle parole usate in quella lingua com una statistica ...
                ///  utile per generare array delle parole piu usate da trovare nei testi @key@.training_text.bigram_freqs
                QString page6 = baseuri + QString("@key@/@key@.training_text.bigram_freqs");
                page6.replace("@key@",dir);
                /// training_text.bigram_freqs
                need_uri_list << page6 <<  page5 << page4 << page3 << page2 << page1;
                  }
     }
     out <<  "Job dowload uri summ:" << need_uri_list.size() << "\n";
     out.flush();
}

/* QLocale nom dispone della lingua nativa italiano figura come italian o tedesco german
 * qui si associa italian italiano e german deutsch mettendo il prefisso da scaricare i file di aiuto riconoscimento ocr
 * utili al riconoscimento della lingua.... arabic diventa لْعَرَبيّة per esempio ecc...
 * int id = (int)QLocale::language()  unique -   QString nt native language name -  QString ctess Tesseract dir */
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
