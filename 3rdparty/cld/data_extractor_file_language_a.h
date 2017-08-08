#ifndef DATAEXTRACTORTOBUILDA
#define DATAEXTRACTORTOBUILDA

#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
#include <string>
#include <map>
#include <algorithm>
#include <fstream>
#include <iostream>

#include <QByteArray>
#include <QString>
#include <QElapsedTimer>
#include <QDebug>
#include <QFile>

/* #include <QtCore> #include <QTextStream> */

#define CONCAT_(x,y) x##y
#define CONCAT(x,y) CONCAT_(x,y)

#define CHECKTIME(x)  \
    QElapsedTimer  CONCAT(sb_, __LINE__); \
    CONCAT(sb_, __LINE__).start(); \
    x \
    qDebug() << __FUNCTION__ << ":" << __LINE__ << " Elapsed time: " <<  CONCAT(sb_, __LINE__).elapsed() << " ms.";


namespace FuntionSlow_U2 {
	


/* this is slow  as old libs std::ifstream  open 48ms */
static inline std::map<int, std::string, std::greater<int> > parse_substring_file_m4(const  QString  f ) {
						  
	    std::string line, text, temp;
        std::map<std::string,int> strCount;
        std::map<int, std::string, std::greater<int> > mapsorted;
		std::map<std::string,int>::const_iterator iter;  
		
		
	   QFile fi(f);
       QByteArray chunk;
       if (fi.exists()) {
          if (fi.open(QFile::ReadOnly)) {
              const QByteArray ch = fi.readAll();
              fi.close();
              text.append(ch.data());
              std::cout <<"Opened file OK:" << qUtf8Printable(f) << std::endl;
              
              
		  }                             
       }  
       
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


}

#endif 


