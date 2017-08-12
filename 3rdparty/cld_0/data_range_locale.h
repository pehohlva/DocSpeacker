#ifndef RANGELISTFROMQHAR
#define RANGELISTFROMQHAR

#include <iostream>
#include <string>
#include <algorithm>


/* capture range from unicode language */          
typedef struct
{
    int mine; int maxe; int la_nr;
} LARANGE;

int InRange(int num, LARANGE * range)
{
    if (num >= range->mine && num <= range->maxe)
        return range->la_nr;
    return -1;
}


const LARANGE Range_list[] = {
{ 65 , 385 , 3}, /// Range provider latin
{ 880 , 8038,4}, /// Range provider Greek
{ 1024 , 1344,5}, /// Range provider script
{ 1329 , 1423,6}, /// Range provider Armenian
{ 1489 , 64335,7}, /// Range provider Hebrew subset*
{ 1568 , 1888,8}, /// Range provider arabic
{ 1808 , 67407,9}, /// Range provider script
{ 1920 , 2240,10}, /// Range provider script
{ 2308 , 67897,11}, /// Range provider script
{ 2432 , 68031,12}, /// Range provider script
{ 2565 , 68213,13}, /// Range provider script
{ 2693 , 68323,14}, /// Range provider script
{ 2821 , 68466,15}, /// Range provider script
{ 2947 , 68496,16}, /// Range provider Tamil
{ 3077 , 68680,17}, /// Range provider script
{ 3205 , 68850,18}, /// Range provider script
{ 3333 , 3653,19}, /// Range provider script
{ 3461 , 3781,20}, /// Range provider script
{ 3585 , 3905,21}, /// Range provider script
{ 3713 , 4033,22}, /// Range provider script
{ 3840 , 4160,23}, /// Range provider script
{ 4096 , 69791,24}, /// Range provider script
{ 4256 , 69864,25}, /// Range provider script
{ 4352 , 4672,26}, /// Range provider script
{ 4608 , 4928,27}, /// Range provider Ethiopic
{ 5024 , 43967,28}, /// Range provider script
{ 5121 , 5441,29}, /// Range provider script
{ 5761 , 71324,30}, /// Range provider script
{ 5792 , 71338,31}, /// Range provider script
{ 6016 , 6336,32}, /// Range provider script
{ 6176 , 71850,33}, /// Range provider script
{ 12353 , 77983,34}, /// Range provider script
{ 12449 , 78041,35}, /// Range provider script
{ 12549 , 78266,36}, /// Range provider script
{ 12293 , 13530,37}, /// Range provider script
{ 40960 , 41280,38}, /// Range provider script
{ 5888 , 71444,42}, /// Range provider script
{ 5920 , 6240,43}, /// Range provider script
{ 5952 , 6272,44}, /// Range provider script
{ 5984 , 6304,45}, /// Range provider script
{ 994 , 11507,46}, /// Range provider script
{ 6400 , 6720,47}, /// Range provider script
{ 6480 , 6800,48}, /// Range provider script
{ 0 , 1, 54 }, /// Range provider script qt braille not print give null
{ 6656 , 6976,55}, /// Range provider script
{ 6528 , 6848,56}, /// Range provider script
{ 11264 , 11584,57}, /// Range provider script
{ 11568 , 11888,58}, /// Range provider script
{ 43008 , 43328,59}, /// Range provider script
{ 6917 , 7237,62}, /// Range provider script
{ 43072 , 43392,65}, /// Range provider script
{ 1994 , 2314,66}, /// Range provider script
{ 7043 , 7363,67}, /// Range provider script
{ 7168 , 7488,68}, /// Range provider script
{ 7258 , 7578,69}, /// Range provider script
{ 42240 , 42560,70}, /// Range provider script
{ 43138 , 43458,71}, /// Range provider script
{ 43274 , 43594,72}, /// Range provider script
{ 43312 , 43632,73}, /// Range provider script
{ 43520 , 43840,77}, /// Range provider script
{ 6688 , 7008,78}, /// Range provider script
{ 43648 , 43968,79}, /// Range provider script
{ 2048 , 67644,82}, /// Range provider script
{ 42192 , 42512,83}, /// Range provider script
{ 42656 , 42976,84}, /// Range provider script
{ 43396 , 43716,85}, /// Range provider script
{ 43744 , 44064,86}, /// Range provider script
{ 7104 , 7424,93}, /// Range provider script
{ 2112 , 67669,95}, /// Range provider script
};


static const int Rangeavaiabletot = sizeof(Range_list)/sizeof(Range_list[0]);









/*  QChar::Script_Latin	3	 
QChar::Script_Greek	4	 
QChar::Script_Cyrillic	5	 
QChar::Script_Armenian	6	 
QChar::Script_Hebrew	7	 
QChar::Script_Arabic	8	 
QChar::Script_Syriac	9	 
QChar::Script_Thaana	10	 
QChar::Script_Devanagari	11	 
QChar::Script_Bengali	12	 
QChar::Script_Gurmukhi	13	 
QChar::Script_Gujarati	14	 
QChar::Script_Oriya	15	 
QChar::Script_Tamil	16	 
QChar::Script_Telugu	17	 
QChar::Script_Kannada	18	 
QChar::Script_Malayalam	19	 
QChar::Script_Sinhala	20	 
QChar::Script_Thai	21	 
QChar::Script_Lao	22	 
QChar::Script_Tibetan	23	 
QChar::Script_Myanmar	24	 
QChar::Script_Georgian	25	 
QChar::Script_Hangul	26	 
QChar::Script_Ethiopic	27	 
QChar::Script_Cherokee	28	 
QChar::Script_CanadianAboriginal	29	 
QChar::Script_Ogham	30	 
QChar::Script_Runic	31	 
QChar::Script_Khmer	32	 
QChar::Script_Mongolian	33	 
QChar::Script_Hiragana	34	 
QChar::Script_Katakana	35	 
QChar::Script_Bopomofo	36	 
QChar::Script_Han	37	 
QChar::Script_Yi	38	 
QChar::Script_OldItalic	39	 
QChar::Script_Gothic	40	 
QChar::Script_Deseret	41	 
QChar::Script_Tagalog	42	 
QChar::Script_Hanunoo	43	 
QChar::Script_Buhid	44	 
QChar::Script_Tagbanwa	45	 
QChar::Script_Coptic	46	 
QChar::Script_Limbu	47	 
QChar::Script_TaiLe	48	 
QChar::Script_LinearB	49	 
QChar::Script_Ugaritic	50	 
QChar::Script_Shavian	51	 
QChar::Script_Osmanya	52	 
QChar::Script_Cypriot	53	 
QChar::Script_Braille	54	 
QChar::Script_Buginese	55	 
QChar::Script_NewTaiLue	56	 
QChar::Script_Glagolitic	57	 
QChar::Script_Tifinagh	58	 
QChar::Script_SylotiNagri	59	 
QChar::Script_OldPersian	60	 
QChar::Script_Kharoshthi	61	 
QChar::Script_Balinese	62	 
QChar::Script_Cuneiform	63	 
QChar::Script_Phoenician	64	 
QChar::Script_PhagsPa	65	 
QChar::Script_Nko	66	 
QChar::Script_Sundanese	67	 
QChar::Script_Lepcha	68	 
QChar::Script_OlChiki	69	 
QChar::Script_Vai	70	 
QChar::Script_Saurashtra	71	 
QChar::Script_KayahLi	72	 
QChar::Script_Rejang	73	 
QChar::Script_Lycian	74	 
QChar::Script_Carian	75	 
QChar::Script_Lydian	76	 
QChar::Script_Cham	77	 
QChar::Script_TaiTham	78	 
QChar::Script_TaiViet	79	 
QChar::Script_Avestan	80	 
QChar::Script_EgyptianHieroglyphs	81	 
QChar::Script_Samaritan	82	 
QChar::Script_Lisu	83	 
QChar::Script_Bamum	84	 
QChar::Script_Javanese	85	 
QChar::Script_MeeteiMayek	86	 
QChar::Script_ImperialAramaic	87	 
QChar::Script_OldSouthArabian	88	 
QChar::Script_InscriptionalParthian	89	 
QChar::Script_InscriptionalPahlavi	90	 
QChar::Script_OldTurkic	91	 
QChar::Script_Kaithi	92	 
QChar::Script_Batak	93	 
QChar::Script_Brahmi	94	 
QChar::Script_Mandaic	95	
* 
* 
* cut here ...  
QChar::Script_Chakma	96	 
QChar::Script_MeroiticCursive	97	 
QChar::Script_MeroiticHieroglyphs	98	 
QChar::Script_Miao	99	 
QChar::Script_Sharada	100	 
QChar::Script_SoraSompeng	101	 
QChar::Script_Takri	102	 
QChar::Script_CaucasianAlbanian	103	 
QChar::Script_BassaVah	104	 
QChar::Script_Duployan	105	 
QChar::Script_Elbasan	106	 
QChar::Script_Grantha	107	 
QChar::Script_PahawhHmong	108	 
QChar::Script_Khojki	109	 
QChar::Script_LinearA	110	 
QChar::Script_Mahajani	111	 
QChar::Script_Manichaean	112	 
QChar::Script_MendeKikakui	113	 
QChar::Script_Modi	114	 
QChar::Script_Mro	115	 
QChar::Script_OldNorthArabian	116	 
QChar::Script_Nabataean	117	 
QChar::Script_Palmyrene	118	 
QChar::Script_PauCinHau	119	 
QChar::Script_OldPermic	120	 
QChar::Script_PsalterPahlavi	121	 
QChar::Script_Siddham	122	 
QChar::Script_Khudawadi	123	 
QChar::Script_Tirhuta	124	 
QChar::Script_WarangCiti	125	 
QChar::Script_Ahom	126	 
QChar::Script_AnatolianHieroglyphs	127	 
QChar::Script_Hatran	128	 
QChar::Script_Multani	129	 
QChar::Script_OldHungarian	130	 
QChar::Script_SignWriting	131	  */


int findinUnicodeRange( int idx , int & lang , int & maxi ) {
	//// int mine; int maxe; int la_nr;
	             const int rangesize = Rangeavaiabletot;
	             
							    for (int i = 0; i < rangesize; ++i) {	 
									LARANGE *cursor = new  Range_list[i];  /// [i];
									int rescue = InRange(idx,cursor);
									if (rescue !=-1) {
										lang =cursor->la_nr;
										 maxi =range->maxe;
									 //// qDebug() <<"L " 
									 return =cursor->la_nr; ////  << cursor.language_nr <<   " - " << cursor.language_nr <<  "\r";
								     }
									
								}
	return -1;
}



 #endif
