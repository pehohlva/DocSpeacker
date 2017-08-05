#ifndef TESSDATABASELANGUAGE_H
#define TESSDATABASELANGUAGE_H

#include <QObject>
#include <QLocale>
#include <QDate>
#include <QtCore>
#include "textrec_config.h"
#include <qdebug.h>
#include "textrec.h"

namespace TracTesserActText {
   // conflict on QLocale #include <QtCore/qglobal.h> /qglobal.h





/* qt locale id  */
struct TessLocale
{
    int lang;  // language
    int coun;  // country
};
/* qt locale associate  */
struct TessSpeack
{
    int lang;  // language
    int dbline; // which db line to find data to associate x 30 -1; line white
};

static const int fullrangedb = 29; /// 100 line from zero

const TessSpeack tra_tess_list[] = {
      {     0,      0 }, // null
      {     0,     1 }, // lat latin
      {     8,     2 }, // ara arabic
      {     28,     3 }, // ces
      {     25,     4 }, // chi_sim
      {     29,     5 }, // dan
      {     42,     6 }, // deu
      {     31,     7 }, // en
      {     36,     8 }, // fin
      {     37,     9 }, // fra
      {     0,      0 }, // null
      {     48,     11 }, // heb
      {     49,     12 }, // hin
      {     0,      0 }, // null
      {     50,     14 }, // hun
      {     52,     15 }, // ind
      {     58,     16 }, // ita
      {     0,      0 }, // null
      {     0,      0 }, // null
      {     0,      0 }, // null
      {     0,      0 }, // null
      {     0,      0 }, // null
      {     59,     22 }, // jpn
      {     66,     23 }, // kor
      {     30,     24 }, // nld
      {     85,     25 }, // nor
      {     90,     26 }, // pol
      {     91,     27 }, // por
      {     95,     28 }, // ron
      {     96,     29 }, // rus
      {     108,    30 }, // slk
      {     0,      0 }, // null
      {     0,      0 }, // null
      {     0,      0 }, // null
      {     0,      0 }, // null
      {     0,      0 }, // null
      {     0,      0 }, // null
      {     0,      0 }, // null
      {     0,      0 }, // null
      {     0,      0 }, // null
      {     0,      0 }, // null
      {     111,     41 }, // spa
      {     114,     42 }, // swe
      {     120,     43 }, // tha
      {     125,     44 }, // tur
      {     0,      0 }, // null
      {     0,      0 }, // null
      {     0,      0 }, // null
      {     0,      0 }, // null
      {     0,      0 }, // null
      {     0,      0 }, // null
      {     0,      0 }, // null
      {     0,      0 }, // null
      {     0,      0 }, // null
      {     0,      0 }, // null
      {     43,    55 }, // gre //// the simply by discovery
};

static const int summsupport_tess_language = sizeof(tra_tess_list)/sizeof(tra_tess_list[0]);

const TessLocale t_locale_list[] = {
    {      1,     0 }, // C/AnyCountry
    {      3,    69 }, // Afan/Ethiopia
    {      3,   111 }, // Afan/Kenya
    {      4,    59 }, // Afar/Djibouti
    {      4,    67 }, // Afar/Eritrea
    {      4,    69 }, // Afar/Ethiopia
    {      5,   195 }, // Afrikaans/SouthAfrica
    {      5,   148 }, // Afrikaans/Namibia
    {      6,     2 }, // Albanian/Albania
    {      7,    69 }, // Amharic/Ethiopia
    {      8,   186 }, // Arabic/SaudiArabia
    {      8,     3 }, // Arabic/Algeria
    {      8,    17 }, // Arabic/Bahrain
    {      8,    64 }, // Arabic/Egypt
    {      8,   103 }, // Arabic/Iraq
    {      8,   109 }, // Arabic/Jordan
    {      8,   115 }, // Arabic/Kuwait
    {      8,   119 }, // Arabic/Lebanon
    {      8,   122 }, // Arabic/LibyanArabJamahiriya
    {      8,   145 }, // Arabic/Morocco
    {      8,   162 }, // Arabic/Oman
    {      8,   175 }, // Arabic/Qatar
    {      8,   201 }, // Arabic/Sudan
    {      8,   207 }, // Arabic/SyrianArabRepublic
    {      8,   216 }, // Arabic/Tunisia
    {      8,   223 }, // Arabic/UnitedArabEmirates
    {      8,   237 }, // Arabic/Yemen
    {      9,    11 }, // Armenian/Armenia
    {     10,   100 }, // Assamese/India
    {     12,    15 }, // Azerbaijani/Azerbaijan
    {     14,   197 }, // Basque/Spain
    {     15,    18 }, // Bengali/Bangladesh
    {     15,   100 }, // Bengali/India
    {     16,    25 }, // Bhutani/Bhutan
    {     20,    33 }, // Bulgarian/Bulgaria
    {     22,    20 }, // Byelorussian/Belarus
    {     23,    36 }, // Cambodian/Cambodia
    {     24,   197 }, // Catalan/Spain
    {     25,    44 }, // Chinese/China
    {     25,    97 }, // Chinese/HongKong
    {     25,   126 }, // Chinese/Macau
    {     25,   190 }, // Chinese/Singapore
    {     25,   208 }, // Chinese/Taiwan
    {     27,    54 }, // Croatian/Croatia
    {     28,    57 }, // Czech/CzechRepublic
    {     29,    58 }, // Danish/Denmark
    {     30,   151 }, // Dutch/Netherlands
    {     30,    21 }, // Dutch/Belgium
    {     31,   225 }, // English/UnitedStates
    {     31,     4 }, // English/AmericanSamoa
    {     31,    13 }, // English/Australia
    {     31,    21 }, // English/Belgium
    {     31,    22 }, // English/Belize
    {     31,    28 }, // English/Botswana
    {     31,    38 }, // English/Canada
    {     31,    89 }, // English/Guam
    {     31,    97 }, // English/HongKong
    {     31,   100 }, // English/India
    {     31,   104 }, // English/Ireland
    {     31,   107 }, // English/Jamaica
    {     31,   133 }, // English/Malta
    {     31,   134 }, // English/MarshallIslands
    {     31,   148 }, // English/Namibia
    {     31,   154 }, // English/NewZealand
    {     31,   160 }, // English/NorthernMarianaIslands
    {     31,   163 }, // English/Pakistan
    {     31,   170 }, // English/Philippines
    {     31,   190 }, // English/Singapore
    {     31,   195 }, // English/SouthAfrica
    {     31,   215 }, // English/TrinidadAndTobago
    {     31,   224 }, // English/UnitedKingdom
    {     31,   226 }, // English/UnitedStatesMinorOutlyingIslands
    {     31,   234 }, // English/USVirginIslands
    {     31,   240 }, // English/Zimbabwe
    {     33,    68 }, // Estonian/Estonia
    {     34,    71 }, // Faroese/FaroeIslands
    {     36,    73 }, // Finnish/Finland
    {     37,    74 }, // French/France
    {     37,    21 }, // French/Belgium
    {     37,    38 }, // French/Canada
    {     37,   125 }, // French/Luxembourg
    {     37,   142 }, // French/Monaco
    {     37,   206 }, // French/Switzerland
    {     40,   197 }, // Galician/Spain
    {     41,    81 }, // Georgian/Georgia
    {     42,    82 }, // German/Germany
    {     42,    14 }, // German/Austria
    {     42,    21 }, // German/Belgium
    {     42,   123 }, // German/Liechtenstein
    {     42,   125 }, // German/Luxembourg
    {     42,   206 }, // German/Switzerland
    {     43,    85 }, // Greek/Greece
    {     43,    56 }, // Greek/Cyprus
    {     44,    86 }, // Greenlandic/Greenland
    {     46,   100 }, // Gujarati/India
    {     47,    83 }, // Hausa/Ghana
    {     47,   156 }, // Hausa/Niger
    {     47,   157 }, // Hausa/Nigeria
    {     48,   105 }, // Hebrew/Israel
    {     49,   100 }, // Hindi/India
    {     50,    98 }, // Hungarian/Hungary
    {     51,    99 }, // Icelandic/Iceland
    {     52,   101 }, // Indonesian/Indonesia
    {     57,   104 }, // Irish/Ireland
    {     58,   106 }, // Italian/Italy
    {     58,   206 }, // Italian/Switzerland
    {     59,   108 }, // Japanese/Japan
    {     61,   100 }, // Kannada/India
    {     63,   110 }, // Kazakh/Kazakhstan
    {     64,   179 }, // Kinyarwanda/Rwanda
    {     65,   116 }, // Kirghiz/Kyrgyzstan
    {     66,   114 }, // Korean/RepublicOfKorea
    {     67,   102 }, // Kurdish/Iran
    {     67,   103 }, // Kurdish/Iraq
    {     67,   207 }, // Kurdish/SyrianArabRepublic
    {     67,   217 }, // Kurdish/Turkey
    {     69,   117 }, // Laothian/Lao
    {     71,   118 }, // Latvian/Latvia
    {     72,    49 }, // Lingala/DemocraticRepublicOfCongo
    {     72,    50 }, // Lingala/PeoplesRepublicOfCongo
    {     73,   124 }, // Lithuanian/Lithuania
    {     74,   127 }, // Macedonian/Macedonia
    {     76,   130 }, // Malay/Malaysia
    {     76,    32 }, // Malay/BruneiDarussalam
    {     77,   100 }, // Malayalam/India
    {     78,   133 }, // Maltese/Malta
    {     80,   100 }, // Marathi/India
    {     82,   143 }, // Mongolian/Mongolia
    {     84,   150 }, // Nepali/Nepal
    {     85,   161 }, // Norwegian/Norway
    {     87,   100 }, // Oriya/India
    {     88,     1 }, // Pashto/Afghanistan
    {     89,   102 }, // Persian/Iran
    {     89,     1 }, // Persian/Afghanistan
    {     90,   172 }, // Polish/Poland
    {     91,   173 }, // Portuguese/Portugal
    {     91,    30 }, // Portuguese/Brazil
    {     92,   100 }, // Punjabi/India
    {     92,   163 }, // Punjabi/Pakistan
    {     95,   177 }, // Romanian/Romania
    {     96,   178 }, // Russian/RussianFederation
    {     96,   222 }, // Russian/Ukraine
    {     99,   100 }, // Sanskrit/India
    {    100,   241 }, // Serbian/SerbiaAndMontenegro
    {    100,    27 }, // Serbian/BosniaAndHerzegowina
    {    100,   238 }, // Serbian/Yugoslavia
    {    101,   241 }, // SerboCroatian/SerbiaAndMontenegro
    {    101,    27 }, // SerboCroatian/BosniaAndHerzegowina
    {    101,   238 }, // SerboCroatian/Yugoslavia
    {    102,   195 }, // Sesotho/SouthAfrica
    {    103,   195 }, // Setswana/SouthAfrica
    {    107,   195 }, // Siswati/SouthAfrica
    {    108,   191 }, // Slovak/Slovakia
    {    109,   192 }, // Slovenian/Slovenia
    {    110,   194 }, // Somali/Somalia
    {    110,    59 }, // Somali/Djibouti
    {    110,    69 }, // Somali/Ethiopia
    {    110,   111 }, // Somali/Kenya
    {    111,   197 }, // Spanish/Spain
    {    111,    10 }, // Spanish/Argentina
    {    111,    26 }, // Spanish/Bolivia
    {    111,    43 }, // Spanish/Chile
    {    111,    47 }, // Spanish/Colombia
    {    111,    52 }, // Spanish/CostaRica
    {    111,    61 }, // Spanish/DominicanRepublic
    {    111,    63 }, // Spanish/Ecuador
    {    111,    65 }, // Spanish/ElSalvador
    {    111,    90 }, // Spanish/Guatemala
    {    111,    96 }, // Spanish/Honduras
    {    111,   139 }, // Spanish/Mexico
    {    111,   155 }, // Spanish/Nicaragua
    {    111,   166 }, // Spanish/Panama
    {    111,   168 }, // Spanish/Paraguay
    {    111,   169 }, // Spanish/Peru
    {    111,   174 }, // Spanish/PuertoRico
    {    111,   225 }, // Spanish/UnitedStates
    {    111,   227 }, // Spanish/Uruguay
    {    111,   231 }, // Spanish/Venezuela
    {    113,   111 }, // Swahili/Kenya
    {    113,   210 }, // Swahili/Tanzania
    {    114,   205 }, // Swedish/Sweden
    {    114,    73 }, // Swedish/Finland
    {    116,   209 }, // Tajik/Tajikistan
    {    117,   100 }, // Tamil/India
    {    118,   178 }, // Tatar/RussianFederation
    {    119,   100 }, // Telugu/India
    {    120,   211 }, // Thai/Thailand
    {    122,    67 }, // Tigrinya/Eritrea
    {    122,    69 }, // Tigrinya/Ethiopia
    {    124,   195 }, // Tsonga/SouthAfrica
    {    125,   217 }, // Turkish/Turkey
    {    129,   222 }, // Ukrainian/Ukraine
    {    130,   100 }, // Urdu/India
    {    130,   163 }, // Urdu/Pakistan
    {    131,   228 }, // Uzbek/Uzbekistan
    {    131,     1 }, // Uzbek/Afghanistan
    {    132,   232 }, // Vietnamese/VietNam
    {    134,   224 }, // Welsh/UnitedKingdom
    {    136,   195 }, // Xhosa/SouthAfrica
    {    138,   157 }, // Yoruba/Nigeria
    {    140,   195 }, // Zulu/SouthAfrica
    {    141,   161 }, // Nynorsk/Norway
    {    142,    27 }, // Bosnian/BosniaAndHerzegowina
    {    143,   131 }, // Divehi/Maldives
    {    144,   224 }, // Manx/UnitedKingdom
    {    145,   224 }, // Cornish/UnitedKingdom
    {    146,    83 }, // Akan/Ghana
    {    147,   100 }, // Konkani/India
    {    148,    83 }, // Ga/Ghana
    {    149,   157 }, // Igbo/Nigeria
    {    150,   111 }, // Kamba/Kenya
    {    151,   207 }, // Syriac/SyrianArabRepublic
    {    152,    67 }, // Blin/Eritrea
    {    153,    67 }, // Geez/Eritrea
    {    153,    69 }, // Geez/Ethiopia
    {    154,   157 }, // Koro/Nigeria
    {    155,    69 }, // Sidamo/Ethiopia
    {    156,   157 }, // Atsam/Nigeria
    {    157,    67 }, // Tigre/Eritrea
    {    158,   157 }, // Jju/Nigeria
    {    159,   106 }, // Friulian/Italy
    {    160,   195 }, // Venda/SouthAfrica
    {    161,    83 }, // Ewe/Ghana
    {    161,   212 }, // Ewe/Togo
    {    163,   225 }, // Hawaiian/UnitedStates
    {    164,   157 }, // Tyap/Nigeria
    {    165,   129 }, // Chewa/Malawi
};

static const int tottesslocale = sizeof(t_locale_list)/sizeof(t_locale_list[0]);


class Class_TessDataLang
{
public:
  enum Supported {
      lat = 0, // latin is on Greek dir .. see last!
      ara = 8,
      ces = 28,
      chi_sim = 25,
      dan = 29,
      deu = 42,
      eng = 31,
      fin = 36,
      fra = 37,
      heb = 48,
      hin = 49,
      hun = 50,
      ind = 52,
      ita = 58,
      jpn = 59,
      kor = 66,
      nld = 30,
      nor = 85,
      pol = 90,
      por = 91,
      ron = 95,
      rus = 96,
      slk = 108,
      spa = 111,
      swe = 114,
      tha = 120,
      tur = 125,
      /// gre = 43, /// no file from ocr tessdata Greek
      nul = lat,
  };

  Class_TessDataLang();
  QString number_go_Name( const int i );
  void writedbline();
  QString getLocaleData(const ushort *data, int size);
  void tessTranslate( const int qtlocale_nr );
  //// void Class_TessDataLang::tessTranslate( const int qtlocale_nr )
  void set_language_native( int id , QString & nt , QString & ctess );

};






}


#endif // Class_TessDataLang_H
