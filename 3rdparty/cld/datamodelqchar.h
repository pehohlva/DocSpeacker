/*
 * datamodelqchar.h
 * 
 * Copyright 2017 dev <phohlva@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#ifndef DATAMODELQCHARASSLANGUAGETYPE_H
#define DATAMODELQCHARASSLANGUAGETYPE_H

#include <QLocale>
#include <QDate>
#include <QChar>

#include <qlist.h>
#include <qhash.h>
#include <qfile.h>
#include <qbytearray.h>
#include <qstring.h>
#include <qchar.h>
#include <qvector.h>
#include <qdebug.h>
#include <QStringList>
#include <QElapsedTimer>


/* usage from this 
 * 
 * 	   CHECKTIME(       
 *                     QString detect_text();  /// in QStringList result.. from latin i use the chrome cls
		               QStringList result;
		               RangeClass *unicodedata = new RangeClass();
		               unicodedata->getPercentageScript(detect_text,result);
		                          qDebug() << "[-" << result << "-]";
		         
		   )
		   *  */



#define CONCAT_(x,y) x##y
#define CONCAT(x,y) CONCAT_(x,y)

#define CHECKTIME(x)  \
    QElapsedTimer CONCAT(sb_, __LINE__); \
    CONCAT(sb_, __LINE__).start(); \
    x \
    qDebug() << __FUNCTION__ << ":" << __LINE__ << " Elapsed time: " <<  CONCAT(sb_, __LINE__).elapsed() << " ms.";
    

struct Scrpt {
        QChar::Script script;
        const char *name;
    };


struct HitScript
{
    HitScript(std::string n , int i ,int p)
        :name(n),idscript(i),percento(p)
    {}
    QString print() {
		QString sepa(",");
		QString result = QString::fromStdString(name) + sepa + QString::number(idscript) + sepa + QString("%") + QString::number(percento);
		return result;
	}
    std::string name;
    int idscript;
    int percento;
};

static QHash<QByteArray, QChar::Script> scriptMap;

static void initScriptMap()
{
    struct Scrpt {
        QChar::Script script;
        const char *name;
    } scripts[] = {
        // general
        { QChar::Script_Unknown,                "Unknown" },
        { QChar::Script_Inherited,              "Inherited" },
        { QChar::Script_Common,                 "Common" },
        // pre-4.0
        { QChar::Script_Latin,                  "Latin" },
        { QChar::Script_Greek,                  "Greek" },
        { QChar::Script_Cyrillic,               "Cyrillic" },
        { QChar::Script_Armenian,               "Armenian" },
        { QChar::Script_Hebrew,                 "Hebrew" },
        { QChar::Script_Arabic,                 "Arabic" },
        { QChar::Script_Syriac,                 "Syriac" },
        { QChar::Script_Thaana,                 "Thaana" },
        { QChar::Script_Devanagari,             "Devanagari" },
        { QChar::Script_Bengali,                "Bengali" },
        { QChar::Script_Gurmukhi,               "Gurmukhi" },
        { QChar::Script_Gujarati,               "Gujarati" },
        { QChar::Script_Oriya,                  "Oriya" },
        { QChar::Script_Tamil,                  "Tamil" },
        { QChar::Script_Telugu,                 "Telugu" },
        { QChar::Script_Kannada,                "Kannada" },
        { QChar::Script_Malayalam,              "Malayalam" },
        { QChar::Script_Sinhala,                "Sinhala" },
        { QChar::Script_Thai,                   "Thai" },   // 120 language 
        { QChar::Script_Lao,                    "Lao" },
        { QChar::Script_Tibetan,                "Tibetan" },
        { QChar::Script_Myanmar,                "Myanmar" },
        { QChar::Script_Georgian,               "Georgian" },
        { QChar::Script_Hangul,                 "Hangul" },   /// korea 26 language 
        { QChar::Script_Ethiopic,               "Ethiopic" },
        { QChar::Script_Cherokee,               "Cherokee" },
        { QChar::Script_CanadianAboriginal,     "CanadianAboriginal" },
        { QChar::Script_Ogham,                  "Ogham" },
        { QChar::Script_Runic,                  "Runic" },
        { QChar::Script_Khmer,                  "Khmer" },
        { QChar::Script_Mongolian,              "Mongolian" },
        { QChar::Script_Hiragana,               "Hiragana" },
        { QChar::Script_Katakana,               "Katakana" },
        { QChar::Script_Bopomofo,               "Bopomofo" },
        { QChar::Script_Han,                    "Han" },
        { QChar::Script_Yi,                     "Yi" },
        { QChar::Script_OldItalic,              "OldItalic" },
        { QChar::Script_Gothic,                 "Gothic" },
        { QChar::Script_Deseret,                "Deseret" },
        { QChar::Script_Tagalog,                "Tagalog" },
        { QChar::Script_Hanunoo,                "Hanunoo" },
        { QChar::Script_Buhid,                  "Buhid" },
        { QChar::Script_Tagbanwa,               "Tagbanwa" },
        { QChar::Script_Coptic,                 "Coptic" },
        // 4.0
        { QChar::Script_Limbu,                  "Limbu" },
        { QChar::Script_TaiLe,                  "TaiLe" },
        { QChar::Script_LinearB,                "LinearB" },
        { QChar::Script_Ugaritic,               "Ugaritic" },
        { QChar::Script_Shavian,                "Shavian" },
        { QChar::Script_Osmanya,                "Osmanya" },
        { QChar::Script_Cypriot,                "Cypriot" },
        { QChar::Script_Braille,                "Braille" },
        // 4.1
        { QChar::Script_Buginese,               "Buginese" },
        { QChar::Script_NewTaiLue,              "NewTaiLue" },
        { QChar::Script_Glagolitic,             "Glagolitic" },
        { QChar::Script_Tifinagh,               "Tifinagh" },
        { QChar::Script_SylotiNagri,            "SylotiNagri" },
        { QChar::Script_OldPersian,             "OldPersian" },
        { QChar::Script_Kharoshthi,             "Kharoshthi" },
        // 5.0
        { QChar::Script_Balinese,               "Balinese" },
        { QChar::Script_Cuneiform,              "Cuneiform" },
        { QChar::Script_Phoenician,             "Phoenician" },
        { QChar::Script_PhagsPa,                "PhagsPa" },
        { QChar::Script_Nko,                    "Nko" },
        // 5.1
        { QChar::Script_Sundanese,              "Sundanese" },
        { QChar::Script_Lepcha,                 "Lepcha" },
        { QChar::Script_OlChiki,                "OlChiki" },
        { QChar::Script_Vai,                    "Vai" },
        { QChar::Script_Saurashtra,             "Saurashtra" },
        { QChar::Script_KayahLi,                "KayahLi" },
        { QChar::Script_Rejang,                 "Rejang" },
        { QChar::Script_Lycian,                 "Lycian" },
        { QChar::Script_Carian,                 "Carian" },
        { QChar::Script_Lydian,                 "Lydian" },
        { QChar::Script_Cham,                   "Cham" },
        // 5.2
        { QChar::Script_TaiTham,                "TaiTham" },
        { QChar::Script_TaiViet,                "TaiViet" },
        { QChar::Script_Avestan,                "Avestan" },
        { QChar::Script_EgyptianHieroglyphs,    "EgyptianHieroglyphs" },
        { QChar::Script_Samaritan,              "Samaritan" },
        { QChar::Script_Lisu,                   "Lisu" },
        { QChar::Script_Bamum,                  "Bamum" },
        { QChar::Script_Javanese,               "Javanese" },
        { QChar::Script_MeeteiMayek,            "MeeteiMayek" },
        { QChar::Script_ImperialAramaic,        "ImperialAramaic" },
        { QChar::Script_OldSouthArabian,        "OldSouthArabian" },
        { QChar::Script_InscriptionalParthian,  "InscriptionalParthian" },
        { QChar::Script_InscriptionalPahlavi,   "InscriptionalPahlavi" },
        { QChar::Script_OldTurkic,              "OldTurkic" },
        { QChar::Script_Kaithi,                 "Kaithi" },
        // 6.0
        { QChar::Script_Batak,                  "Batak" },
        { QChar::Script_Brahmi,                 "Brahmi" },
        { QChar::Script_Mandaic,                "Mandaic" },
        // 6.1
        { QChar::Script_Chakma,                 "Chakma" },
        { QChar::Script_MeroiticCursive,        "MeroiticCursive" },
        { QChar::Script_MeroiticHieroglyphs,    "MeroiticHieroglyphs" },
        { QChar::Script_Miao,                   "Miao" },
        { QChar::Script_Sharada,                "Sharada" },
        { QChar::Script_SoraSompeng,            "SoraSompeng" },
        { QChar::Script_Takri,                  "Takri" },
        // 7.0
        { QChar::Script_CaucasianAlbanian,      "CaucasianAlbanian" },
        { QChar::Script_BassaVah,               "BassaVah" },
        { QChar::Script_Duployan,               "Duployan" },
        { QChar::Script_Elbasan,                "Elbasan" },
        { QChar::Script_Grantha,                "Grantha" },
        { QChar::Script_PahawhHmong,            "PahawhHmong" },
        { QChar::Script_Khojki,                 "Khojki" },
        { QChar::Script_LinearA,                "LinearA" },
        { QChar::Script_Mahajani,               "Mahajani" },
        { QChar::Script_Manichaean,             "Manichaean" },
        { QChar::Script_MendeKikakui,           "MendeKikakui" },
        { QChar::Script_Modi,                   "Modi" },
        { QChar::Script_Mro,                    "Mro" },
        { QChar::Script_OldNorthArabian,        "OldNorthArabian" },
        { QChar::Script_Nabataean,              "Nabataean" },
        { QChar::Script_Palmyrene,              "Palmyrene" },
        { QChar::Script_PauCinHau,              "PauCinHau" },
        { QChar::Script_OldPermic,              "OldPermic" },
        { QChar::Script_PsalterPahlavi,         "PsalterPahlavi" },
        { QChar::Script_Siddham,                "Siddham" },
        { QChar::Script_Khudawadi,              "Khudawadi" },
        { QChar::Script_Tirhuta,                "Tirhuta" },
        { QChar::Script_WarangCiti,             "WarangCiti" },
        // 8.0
        { QChar::Script_Ahom,                   "Ahom" },
        { QChar::Script_AnatolianHieroglyphs,   "AnatolianHieroglyphs" },
        { QChar::Script_Hatran,                 "Hatran" },
        { QChar::Script_Multani,                "Multani" },
        { QChar::Script_OldHungarian,           "OldHungarian" },
        { QChar::Script_SignWriting,            "SignWriting" },
        // unhandled
        { QChar::Script_Unknown,                0 }
    };
    Scrpt *p = scripts;
    while (p->name) {
        scriptMap.insert(p->name, p->script);
        ++p;
    }
}




QSet<QString> qlocaleList() {
	   
	   	   QList<QLocale> allLocales = QLocale::matchingLocales(
            QLocale::AnyLanguage,
            QLocale::AnyScript,
            QLocale::AnyCountry);
            
							QSet<QString> isoLanguages;

							for(const QLocale &locale : allLocales) {
								isoLanguages.insert(locale.bcp47Name());
							}

               /// qDebug() << isoLanguages;
	   
	  return isoLanguages;
   }


class RangeClass
{
public:
  RangeClass();
  void getPercentageScript( const QString text , QStringList & rec );
  QString getnameScriptQChar( const ushort unicode );
};




RangeClass::RangeClass()
{
   initScriptMap();
}


QString RangeClass::getnameScriptQChar( const ushort unicode )  { //// uniode in
	
	                            QChar vox(unicode);
								 //// ushort Unn = vox.unicode();
								QString letterqq = QString().append(vox);
								QChar::Script typecha = vox.script();
								//// int Sesript = vox.script();
								QByteArray scriptname = scriptMap.key(typecha);
								const QString scriptid = QString::fromUtf8(scriptname.constData());
								if (scriptid.size() !=0) {
									return scriptid;
								} else {
									qFatal("Unhandled unicode property value: %d",unicode);
								}
	return QString();
}


void RangeClass::getPercentageScript( const QString text , QStringList & rec )  { 
	
	   std::map<std::string, int, std::greater<std::string> > countscripting;
	   int xcsize =0;
	           for (int o = 0; o < text.size(); o++) {
					const QChar vox(text.at(o));
					const ushort unico = vox.unicode();
					QString scripter = this->getnameScriptQChar(unico);
					if ("Inherited" !=scripter && "Common" !=scripter ) {
					    std::string scristr = scripter.toUtf8().constData();
						++countscripting[scristr];
						xcsize++; /// new size space out e inherit
					   //// qDebug() <<"L " << unico <<   " - " << scripter  << " - "  << vox.script();
					   }
							              
					}
					//// qDebug() <<"L xsize" << xsize <<   " - " << xcsize;
					std::map<std::string,int>::const_iterator iter;  
					for( iter = countscripting.begin(); iter != countscripting.end(); iter++ ) {
						int perhe =  iter->second / (xcsize / 100);
						if (perhe > 49) {
						HitScript *current = new HitScript(iter->first,xcsize,perhe);
						rec << current->print();
						//// std::cout <<  "tot" << xcsize << " ->%" << perhe << " - " << iter->second << " string: " << iter->first << std::endl;
					 }
				    }
}













#endif
