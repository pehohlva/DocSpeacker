/*
 * data_extractor_file_language.h
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
 * Description: here function to get multisubstring sorting
 * find top hit word list from all Latin Language
 * fork to qt from https://shuyo.wordpress.com/2012/05/17/short-text-language-detection-with-infinity-gram/
 *  #pragma once
 */
 
#ifndef DATAEXTRACTORTOBUILD
#define DATAEXTRACTORTOBUILD


#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
#include <string>
#include <map>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <QDir>
#include <QByteArray>
#include <QString>
#include <QElapsedTimer>
#include <QDebug>
#include <QFile>
#include <QChar>

	
struct QT {
			
QString read_file( const  std::string  f ) {
	 
	 std::string line, text, temp;
	 std::ifstream ifs(f); 
	 
	        if ( ! ifs.is_open() ) {                 
			  std::cout <<" Failed to open:" << f << std::endl;
			  return QString();
		   }
		     while ( !ifs.eof() )  {
				  getline(ifs, line);
				  temp.append(line);
				}
	   return QString::fromStdString(temp);
}

};

#define _USERHOME_ \
               QString(QDir::homePath()+"/")
#define __DIRBASICTESSY__ \
              _USERHOME_ + QString("Applications/Language/Tess/")  /// only Mac



     
     
     
     /*     int scursur=1;
		            QSet<int> set;
		           	do{
                        scursur++;
                               QChar fox(scursur);
                               if ( !fox.isNull() ) {
								   set << (int)fox.script();
							   }
							   
                        } while(scursur < 90000);
                        QList<int> list = set.toList();
                        qSort(list);
                        QList<int>::iterator i;
                        //// QList<QString>::iterator i;
							for (i = list.begin(); i != list.end(); ++i) {
								/// qDebug() << *i;
								summs += range_provider_lang(*i,"script");
							}
							*   */      
              
              
QString range_provider_lang( const int onumero , QString fofo ) {
	  QString latin = QString();  //// ("<br/>/* Range from language name.%1  nr.%2 */ <br/>").arg(fofo,numero);
	  const int x = 98262;
	  const int i = 20;
	  int cursor = i;
	  bool take = true;
	  QSet<int> set;
	  //// qMax(min, qMin(value, max)).
	  int MinimumCursor = 100000;
	  int MaximumCursor = 0;
	  bool tessgo = false;
	  int inside =0;
	  int steeps = 1;
	do{
           cursor++;
           steeps++;
           
           if (inside > 220) {
			/// stop it
			cursor= 100000;
           } 
           if (steeps == 50) {
			  steeps = 1; 
			  std::cout <<"-----Cursor: " << MaximumCursor << "\r";
		   }
           
           
           QChar fox(cursor);
           int scriper = (int)fox.script();
           /// set << scriper;
               if ( scriper == onumero && scriper !=2 && QChar::isLetter(cursor) ) {
				     inside++;
					  MaximumCursor = qMax(MaximumCursor,cursor);
					  MinimumCursor = qMin(MinimumCursor,cursor);
		       }
    
     } while(cursor < x);
     
     if (MinimumCursor == 100000) {
		 /// not found 
		 MaximumCursor = 1;
		 MinimumCursor = 0;
	 } else {
		  
		  int overload = MinimumCursor + 1000;
		  if (MaximumCursor < overload) {
			 MaximumCursor = MinimumCursor + 320; 
		  }
		  
		  
	 }
     
     std::cout <<" \n";
     std::cout <<"End ->" << onumero << "<- set:" << set.size() << "\n";
     QString m = "{ " + QString::number(MinimumCursor)  + " , " + QString::number(MaximumCursor) + "," + QString::number(onumero) + "},  /// Range provider " + fofo; 
     latin.append(m);
	latin.append("<br/>");
	return latin;
}
     
              
/*  separate unicode non english only EU or indi latin
 * write index table to associate                   */   
QString latin_provider( const int numero , QString fofo ) {
	  QString latin = QString("<br/>/* Range from language name.%1  nr.%2 */ <br/>").arg(fofo,numero);
	  const int x = 88262;
	  const int i = 191;
	  int cursor = i;
	  bool take = true;
	do{
           cursor++;
           /* jump  unicode dirty or bugs realy not to print .. */
           if (cursor > 7929 && cursor < 43876) {
			  cursor = 43877;
		   }
		    if (cursor > 7531 && cursor < 7679) {
			  cursor = 7680;
		   }
		   if (cursor > 567 && cursor < 592) {
			  cursor = 593;
		   }
		   if (cursor > 7835 && cursor < 7839) {
			  cursor = 7840;
		   }
		    /* jump */
           std::cout <<"Cursor: " << cursor << "\r";
           QChar fox(cursor);
               if ((int)fox.script() == numero) {
				   
				   if ( !fox.isNull() ) {
					   QChar mi = fox.toTitleCase();
					   ////   {      1,     0 },
					   QString s = "&#" + QString::number(cursor) + ";";
					   QString m = "&#" + QString::number(mi.unicode()) + ";";
					   QString initlin = QString("&nbsp;&nbsp;&nbsp;{");
					   initlin.append(QString::number(cursor));
					   initlin.append(" , &nbsp;");
					   initlin.append(QString::number(numero));
					   initlin.append("&nbsp;},&nbsp;&nbsp;&nbsp;\t/* ");
					   initlin.append(s); /// html on qtextedit ... 
					   initlin.append(" - uni:");
					   initlin.append(QString::number((int)fox.unicodeVersion()));
					   initlin.append(" - ti:");
					   initlin.append(m);
					   initlin.append("&nbsp;&nbsp;*/<br/>\n");
					   
					   latin.append(initlin);
				   }
		     }
    
     } while(cursor < x);
	latin.append("};<br/><br/>");
	return latin;
}
     
      

namespace Fast {	

	
	

	
	
bool file_put( const QString file , QByteArray dat ) {

    QFileInfo fi(file);
    QDir dir;
         if(!dir.exists(fi.absolutePath())) {
             dir.mkpath(fi.absolutePath());
          }
          
      QFile f(file);
      if (f.open(QFile::WriteOnly)) {
        uint bi = f.write(dat);
        f.close();
        return bi > 0 ? true : false;
      }
   return false;
 }

std::string read_file( const  std::string  f ) {
	 
	 std::string line, text, temp;
	 std::ifstream ifs(f); 
	 
	        if ( ! ifs.is_open() ) {                 
			  std::cout <<" Failed to open:" << f << std::endl;
			  return temp;
		   }
		   int i=-1;
		     while ( !ifs.eof() )  {
				  getline(ifs, line);
				  i++;
				  std::cout << "Read line: " << i << "\r";
				  temp.append(line);
				}
	   return temp;
}


/* this is faster  as qt qfile open 2ms */
std::map<int, std::string, std::greater<int> > 
                      parse_substring_file(const  std::string  f ) {
	
	    std::string line, text, temp;
        std::map<std::string,int> strCount;
        std::map<int, std::string, std::greater<int> > mapsorted;
		std::map<std::string,int>::const_iterator iter;  
		/// file open 			
        std::ifstream ifs(f); 
        
            if ( ! ifs.is_open() ) {                 
			  std::cout <<" Failed to open:" << f << std::endl;
			  return mapsorted;
		   }
	         std::cout <<"Opened file OK:" << f << std::endl;
	         
	           while ( !ifs.eof() )  {
				  getline(ifs, line);
				  text.append(line);
				}
	          ifs.close();
	          
	               for ( int i(0); i < text.size(); ++i ){
						temp += text[i];
						if ( text[i] == ' ' && temp.size() >= 2 ){
							temp.pop_back();
							++strCount[temp]; /// insert in noqt map.. if new
							temp.clear();
					   }
					}
					
					     
						for( iter = strCount.begin(); iter != strCount.end(); iter++ ) {
							 if ( iter->second > 2 && iter->first.size() > 0) {
								 if (iter->first.size() >= 3) {
									mapsorted[(int)iter->second] =iter->first; 
								 }
								 
							}
						}
	         
	   return mapsorted; 
	
}








/*  int main(int argc, char* argv[]){
	
	QCoreApplication a(argc, argv);

    


	return a.exec();
}

QTextStream cout(stdout,QIODevice::WriteOnly);
    
    std::string line, text, temp;
    
 * typedef QPair<qint64,QString> HitWordParade;
typedef QVector<HitWordParade > TopWordLanguage;
* 
* 
* 
* std::map<int, std::string, std::greater<int> > mapsorteda;
    std::map<int, std::string, std::greater<int> > mapsortedb;
    
    
         CHECKTIME(
                
                  mapsortedb = parse_substring_file_m4("/Users/dev/Applications/Language/Tess/ita/ita.training_text");
                  std::cout << "b method qt5 core lib\n";
                
		  )
    
		  CHECKTIME(
		  
		          mapsorteda = parse_substring_file_m2("/Users/dev/Applications/Language/Tess/ita/ita.training_text");
		          std::cout << "a method old c lib\n";
		   )
		  
		  
         
  
       std::cout << "a method old c lib\n";
       for(auto const & item : mapsorteda) 
       std::cout << "{" << item.first  <<"," << item.second << "}\n";
 
	    std::cout << "b method qt5 core lib\n";
	    for(auto const & item : mapsortedb) 
       std::cout << "{" << item.first  <<"," << item.second << "}\n";
   */




std::map<int, std::string, std::greater<int> > 
                                sumfile_get(	const QString dir) {
	 
	    std::string line, text, temp;
        std::map<std::string,int> strCount;
        std::map<int, std::string, std::greater<int> > mapsorted;
		std::map<std::string,int>::const_iterator iter;  
		
	 ///QString fwX = __DIRBASICTESSY__ + QString("@key@/desired_characters").replace("@key@",dir);
     ///QString fwO = __DIRBASICTESSY__ + QString("@key@/@key@.training_text").replace("@key@",dir); ////  training text
     QString fwA = __DIRBASICTESSY__ + QString("@key@/@key@.word.bigrams").replace("@key@",dir); ////  training word
     //// QString fwB = __DIRBASICTESSY__ + QString("@key@/@key@.wordlist").replace("@key@",dir); ////  training word
     ///std::string  tmpx = read_file(fwX.toUtf8().constData());
     ///std::string  tmpo = read_file(fwO.toUtf8().constData());
     std::string  tmpa = read_file(fwA.toUtf8().constData());
     ///std::string  tmpb = read_file(fwB.toUtf8().constData());
           ///text.append(tmpx);
           ///text.append(tmpo);
           text.append(tmpa);
           ///text.append(tmpb);
           
                 for ( int i(0); i < text.size(); ++i ){
						temp += text[i];
						if ( text[i] == ' '){
							temp.pop_back();
							++strCount[temp]; /// insert in noqt map.. if new
							temp.clear();
					   }
					}
					
					     
						for( iter = strCount.begin(); iter != strCount.end(); iter++ ) {
							 if ( iter->second > 2 && iter->first.size() > 0) {
								 if (iter->first.size() >= 3) {
									mapsorted[(int)iter->second] =iter->first; 
								 }
								 
							}
						}
	return mapsorted;
	
}


};

#endif 



 
 




