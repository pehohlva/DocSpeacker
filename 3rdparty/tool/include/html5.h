#ifndef HTML5_H
#define HTML5_H

#include "html5_global.h"
/// typical php name function ... extra .
/* search doc by php7 :-)  */
const  QString UserLanguage();
/// read as kb mg gb ...
QString bytesToSize(const qint64 size);
QString Domain( QString url );
bool file_put_contents(const QString fullFileName, QString xml, int modus = 0);
QString readfile(const QString fullFileName );
bool is_file(const QString fullFileName);
qint64 filesize( const QString fullFileName );
bool unlink(const QString fullFileName);
/* copy file from a to b ... if dir not exist make it ...*/
bool copy(const QString inputfile, const  QString outfile);
/* remove dir recursive  hot work caution !! */
void DownDir_RM(const QString d);
/* encode to name pics file ... */
QString encodeBase64( QString xml );
/* decode to name pics file ...  */
QString decodeBase64( QString xml );
/* check if a int or float nummer */
bool is_numeric(QString incomming);
/* mail date format eng   */
QString UmanTimeFromUnix( uint unixtime );
/* time null unix time long nummer */
uint QTime_Null();
/* encode to url strings */
QString EncodeUrlPart( QString xml  );
QString LocalDir( const uint unixtime , QString base );
QString DesktopFile( QString fullFileName );
const char*  Rotate( int casir );  /// console
QString  Firstupper( QString nametomake );
/* date format to stirng */
QString datetr(QString form, uint unixtime );
/* return int value from a unixtime date MMM YYY ... */
int dateswap(QString form, uint unixtime );


class  Html5
{

public:
  Html5();

private:
  bool loaded;
};




#endif // HTML5_H
