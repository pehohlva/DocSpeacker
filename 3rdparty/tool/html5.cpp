#include "html5.h"

#include "tidy.h"

typedef QMap<QString, QString> Appsetting;
typedef QMap<int, QStringList> resultMap;
/// typedef QMap<QString, QString> Vario;
/// typedef QMap<QString, QString> sqlr;

#define CACHEBUFFERDIR \
               QString( "%1/.tidy/" ).arg(QDir::homePath())

/* date format to stirng */
QString datetr(QString form, uint unixtime )
{
     QDateTime fromunix;
     fromunix.setTime_t(unixtime);
     return fromunix.toString((const QString)form);
}


/* return int value from a unixtime date MMM YYY ... */
int dateswap(QString form, uint unixtime )
{
     QDateTime fromunix;
     fromunix.setTime_t(unixtime);
     QString numeric = fromunix.toString((const QString)form);
     bool ok;
     return (int)numeric.toFloat(&ok);
}

QString  Firstupper( QString nametomake )
{
    QString firtupper,lower,fullname,na,nb;
    int xse = nametomake.size();
    na = nametomake.toLower();
    nb = nametomake.toUpper();
    firtupper = nb.left(1);
    fullname = QString("%1%2").arg(firtupper).arg(na.mid(1,xse - 1));

return fullname;
}

const char*  Rotate( int casir )
{
    const char *bane;

    switch(casir)
                {
                case 1:
                bane ="-";
                break;
                case 2:
                bane ="\\";
                break;
                case 3:
                bane ="|";
                break;
                case 4:
                bane ="/";
                break;

    }

return bane;
}

QString DesktopFile( QString fullFileName )
{
    if (fullFileName.startsWith("http://", Qt::CaseInsensitive) or
        fullFileName.startsWith("https://", Qt::CaseInsensitive) or
        fullFileName.startsWith("ftp://", Qt::CaseInsensitive) or
        fullFileName.startsWith("news://", Qt::CaseInsensitive) or
        fullFileName.startsWith("mailto:", Qt::CaseInsensitive) or
        fullFileName.startsWith("webdav://", Qt::CaseInsensitive)  )
       {
         return fullFileName;
       } else {
         return fullFileName.prepend("file:///");
       }
}

QString LocalDir(const uint unixtime , QString base )
{
     if (unixtime < 10000) {
         return QString();
       }
    QString base_3 ="";
    QString base_0 = QString("%1%2/").arg( base , datetr("yyyy",(uint)unixtime) );
    QString base_1 = QString("%1%2/").arg( base_0 , datetr("MM",(uint)unixtime) );
    QString base_2 = QString("%1%2/").arg( base_1 , datetr("dd",(uint)unixtime) );
    base_3 = QString("%1%2/").arg( base_2 , QString::number(unixtime) );
     return base_3;
}

/* encode to url strings */
QString EncodeUrlPart( QString xml  )
{
    QUrl urlmod(QString("http://localhost/%1").arg(xml));
    QByteArray capsed(urlmod.toEncoded());
    QString res = QString("%1").arg(capsed.data());
    res = res.replace("%20","_");
    res = res.replace("%","");
    QUrl urlmod2(res);
    res = urlmod2.path ();
    res = res.replace("/","");
    return res;
}
/* time null unix time long nummer */
uint QTime_Null()
{
    QDateTime timer1( QDateTime::currentDateTime() );
    return timer1.toTime_t();
}

/* display a mail date format  UmanTimeFromUnix(QTime_Null())   */
QString UmanTimeFromUnix( uint unixtime )
{
     /* mail rtf Date format! http://www.faqs.org/rfcs/rfc788.html */
     QDateTime fromunix;
     fromunix.setTime_t(unixtime);
     QStringList RTFdays = QStringList() << "day_NULL" << "Mon" << "Tue" << "Wed" << "Thu" << "Fri" << "Sat" << "Sun";
     QStringList RTFmonth = QStringList() << "month_NULL" << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun" << "Jul" << "Aug" << "Sep" << "Oct" << "Nov" << "Dec";
     QDate timeroad(dateswap("yyyy",unixtime),dateswap("M",unixtime),dateswap("d",unixtime));
     /*qDebug() << "### RTFdays " << RTFdays.at(timeroad.dayOfWeek());
     qDebug() << "### RTFmonth " << RTFmonth.at(dateswap("M",unixtime));
     qDebug() << "### yyyy " << dateswap("yyyy",unixtime);
     qDebug() << "### M " << dateswap("M",unixtime);
     qDebug() << "### d " << dateswap("d",unixtime);*/
     QStringList rtfd_line;
     rtfd_line.clear();
     rtfd_line.append("Date: ");
     rtfd_line.append(RTFdays.at(timeroad.dayOfWeek()));
     rtfd_line.append(", ");
     rtfd_line.append(QString::number(dateswap("d",unixtime)));
     rtfd_line.append(" ");
     rtfd_line.append(RTFmonth.at(dateswap("M",unixtime)));
     rtfd_line.append(" ");
     rtfd_line.append(QString::number(dateswap("yyyy",unixtime)));
     rtfd_line.append(" ");
     rtfd_line.append(fromunix.toString("hh:mm:ss"));
     rtfd_line.append("");
     /*qDebug() << "### mail rtf Date format " << rtfd_line.join("");*/
return QString(rtfd_line.join(""));
}

/* check if a int or float nummer */
bool is_numeric(QString incomming)
{
    incomming.replace(QString(" "), QString("")); /* trimm */
    QString str2 = incomming;
    bool ok;
    str2.toFloat(&ok);
return ok;
}

/* encode to name */
QString encodeBase64( QString xml )
{
    QByteArray text;
    text.append(xml);
    return text.toBase64();
}

/* decode to name */
QString decodeBase64( QString xml )
{
    QByteArray xcode("");;
    xcode.append(xml);
    QByteArray precode(QByteArray::fromBase64(xcode));
    QString notetxt = precode.data();
    return notetxt;
}

/* remove dir recursive */
void DownDir_RM(const QString d) {
   QDir dir(d);
    QDir enddir(d);
   if (dir.exists())
   {
      const QFileInfoList list = dir.entryInfoList();
      QFileInfo fi;
      for (int l = 0; l < list.size(); l++)
      {
         fi = list.at(l);
         if (fi.isDir() && fi.fileName() != "." && fi.fileName() != "..")
            DownDir_RM(fi.absoluteFilePath());
         else if (fi.isFile())
         {
            unlink(fi.absoluteFilePath());
         }

      }
         dir.rmdir(d);
   }

   //// return enddir.exists();
}

qint64 filesize( const QString fullFileName ) {

    QFileInfo fi(fullFileName);
    return fi.size();
}

/* remove a file */
bool unlink(const QString fullFileName)
{
    if (fullFileName.size() > 0) {
    QFile f( fullFileName );
        if ( f.exists(fullFileName) ) {
       if (f.remove()) {
        return true;
       }
        }
    }
return false;
}

/*  Readutf8File file_put_utf8contents */
/* read the contenet of a local file as qstring */
QString readfile(const QString fullFileName )
{
    QString inside = "";
    QFile file(fullFileName);
    if (file.exists()) {
                if (file.open(QFile::ReadOnly | QFile::Text)) {
                    inside = QString::fromUtf8(file.readAll());
                    file.close();
                }
     }
return inside;
}

QString bytesToSize(const qint64 size) {
    if (size < 0)
        return QString();
    if (size < 1024)
        return QObject::tr("%1 B").arg(QString::number(((double) size), 'f', 0));
    if ((size >= 1024) && (size < 1048576))
        return QObject::tr("%1 KB").arg(QString::number(((double) size) / 1024, 'f', 0));
    if ((size >= 1048576) && (size < 1073741824))
        return QObject::tr("%1 MB").arg(QString::number(((double) size) / 1048576, 'f', 2));
    if (size >= 1073741824)
        return QObject::tr("%1 GB").arg(QString::number(((double) size) / 1073741824, 'f', 2));
    return QString();
}

/* copy file from a to b ... if dir not exist make it ...*/
bool copy(const QString inputfile, const  QString outfile)
{
    bool actioncpy = false;
    QString ultimacartellaaperta = outfile.left(outfile.lastIndexOf("/"))+"/";
    QDir dira(ultimacartellaaperta);
    if ( dira.mkpath(ultimacartellaaperta) ) { } else {
    return actioncpy;
    }
    if (is_file(inputfile)) {
           unlink(outfile);
           QFile Imaged(inputfile);
               if (Imaged.copy(outfile)) {
                   actioncpy = true;
                }
    }
return actioncpy;
}

const  QString UserLanguage()
{
     /////////////QSettings setter;
     QString languser,languagesistem,langqt;
        QLocale loci = QLocale::system();
             languser = getenv("LANG");
             languser = languser.toLower();
             languagesistem = loci.name();
             languagesistem = languagesistem.toLower();
             languagesistem = languagesistem.left(2);
     /* Window XP Prof MUI Multiuser == stay only "c" language && user setting setenv !!! */
     if (languagesistem == "c") {
         if (languser.size() > 2 && languser.contains("_")) {
             languagesistem = languser.left(2);
         }
     }
     ////////////setter.setValue("userlanguage",languagesistem);
     ///////////qDebug() << "### save to qsetting " << languagesistem;
    ///////// qDebug() << "### QT grep language " << QLocale::languageToString( QLocale::system().language());
     /////////qDebug() << "### User setenv " << getenv("LANG");
     return languagesistem;
}


 bool is_file(const QString fullFileName)
{
    if (!fullFileName.size() > 3) {
      return false;
    }
    QFile f( fullFileName );
        if ( f.exists(fullFileName) ) {
    return true;
        } else {
        return false;
    }
}


bool file_put_contents(const QString fullFileName, QString xml , int modus) {
    if (fullFileName.contains("/", Qt::CaseInsensitive)) {
    QString ultimacartellaaperta = fullFileName.left(fullFileName.lastIndexOf("/"))+"/";
    QDir dira(ultimacartellaaperta);
    if ( dira.mkpath(ultimacartellaaperta) ) { } else {
    return false;
    }
    }
        QTextCodec *codecx;
        codecx = QTextCodec::codecForMib(106);
        QFile f( fullFileName );
            if (modus == 1) {
                if ( f.open(  QIODevice::WriteOnly | QIODevice::Append ) ) {
                    QTextStream sw( &f );
                    sw.setCodec(codecx);
                    sw << xml;
                    f.close();
                     if (f.bytesAvailable() > 0) {
                        return true;
                      } else {
                        return false;
                      }
                }
             } else {
                if ( f.open( QFile::Append | QFile::Text ) ) {
                        QTextStream sw( &f );
                        sw.setCodec(codecx);
                        sw << xml;
                        f.close();
                        if (f.bytesAvailable() > 0) {
                           return true;
                         } else {
                           return false;
                         }
                 }
              }
}



/* extract domaine from a url grep image from file..  */
QString Domain( QString url )
{
   QString hdomain = "";
   QUrl wurl( url );
   hdomain = QString( "http://%1/" ).arg( wurl.host() );
   return hdomain;
}


/* read the contenet of a local file as qstring */
QString fopenutf8(QString fullFileName)
{
    QString inside = "";
    QFile file(fullFileName);
    if (file.exists()) {
                if (file.open(QFile::ReadOnly | QFile::Text)) {
                    inside = QString::fromUtf8(file.readAll());
                  file.close();
                }
    }

return inside;
}


Html5::Html5() : loaded(false)
{


}




/*  --------*/

/*

class QTidy : public QObject
{
    Q_OBJECT

    QTidy();
    QString TidyCleanfullxhtml( QString body );
    QString TidyCleanfullxml( QString body );
    QString OpenFile( const QString file ) {
        return readfile(file);
    }
    bool SaveFile(const QString file , QString xml) {
      return file_put_contents(file,xml);
    }

    QString error() { return ErrorMSG; }
    ~QTidy();
public:

private:
    void Init( const QString dircache );
    bool tidy_file_set_config(QString xml);
    bool SetUp_xhtml_full_page();
    bool CleanTidy(QString inputfile, QString outfile);
    bool SetUp_xml();
    QString ErrorMSG;
    QString TMP_Dir;
    QString TMP_Config;
    QTextCodec *setcurrentcodec;
    QStringList  tidiconfigfile;
    int status;
};




QTidy::QTidy()
{
  this->Init(CACHEBUFFERDIR);
}

QTidy::~QTidy() {
   DownDir_RM(CACHEBUFFERDIR);
   /// TidyDoc doc;
}

void QTidy::Init(const QString dircache )
{
    if (!dircache.endsWith("/")) {
      TMP_Dir = dircache + "/";
    } else {
      TMP_Dir = dircache;
    }

    TMP_Config = QString( "%1tidy.conf" ).arg( TMP_Dir );
    setcurrentcodec = QTextCodec::codecForMib(106);
    QDir dira(TMP_Dir);
    if ( dira.mkpath(TMP_Dir) ) { } else {
    ErrorMSG = QString("ERROR! on %1 not Possibel to make dir \"%2\"\n").arg( TMP_Dir );
    }
}


///  write the config file
bool QTidy::tidy_file_set_config(QString xml)
{
unlink(TMP_Config);
return file_put_contents(TMP_Config,xml);
    /* file_put_utf8contents   Readutf8File
}

// prepare config tidy config file xhtml clean
bool QTidy::SetUp_xhtml_full_page()
{
    status = 0;
    ErrorMSG ="";
    TidyDoc doc = tidyCreate();
    ////--output-xhtml y --indent "auto" --wrap "90"
    bool ok;
    tidiconfigfile.clear();
    tidiconfigfile.append("output-xhtml: yes");
    tidiconfigfile.append("indent: auto");
    tidiconfigfile.append("wrap: 90");
    /// tidiconfigfile.append("show-body-only: yes");
    QString configtotsl = tidiconfigfile.join("\n");
    ok = tidy_file_set_config(configtotsl);
    if (ok) {
         QByteArray configfileti = TMP_Config.toUtf8();
         status = tidyLoadConfig( doc, configfileti.data() );
        if ( status != 0 ) {
         ErrorMSG ="Not possibel to load Config File!";
         return false;
        } else {
        return true;
        }
    } else {
      ErrorMSG ="Not possibel to load Config File!";
     return false;
    }
}


QString QTidy::TidyCleanfullxhtml( QString body )
{
    QString newbody;
    bool ok = false;;
    const QString sucleanfile = QString( "%1tidy_tmp.xml" ).arg( TMP_Dir );
    const QString sucleanfileout = QString( "%1tidy_tmp_out.xml" ).arg( TMP_Dir );
    ok = file_put_contents(sucleanfile,body);
    if (!ok) {
    return body;
    } else {
    SetUp_xhtml_full_page();
    CleanTidy(sucleanfile,sucleanfileout);
    newbody =  readfile(sucleanfileout);
            if (newbody.size() > 2) {

            } else {
            newbody = body;
            }
    }
    //// todo tidy work in ram buffer...
    unlink(sucleanfile);
    unlink(sucleanfile);
    return newbody;
}

QString QTidy::TidyCleanfullxml( QString body )
{
    QString newbody;
    bool ok = false;;
    const QString sucleanfile = QString( "%1tidy_tmp.xml" ).arg( TMP_Dir );
    const QString sucleanfileout = QString( "%1tidy_tmp_out.xml" ).arg( TMP_Dir );
    ok = file_put_contents(sucleanfile,body);
    if (!ok) {
    return body;
    } else {
    SetUp_xml();
    CleanTidy(sucleanfile,sucleanfileout);
    newbody =  readfile(sucleanfileout);
            if (newbody.size() > 2) {

            } else {
            newbody = body;
            }
    }
    //// todo tidy work in ram buffer...
    unlink(sucleanfile);
    unlink(sucleanfile);
    return newbody;
}


// QString clean file inputfile and put to outfile
bool QTidy::CleanTidy(QString inputfile, QString outfile)
{

    Bool ok;
    TidyDoc doc = tidyCreate();
    ctmbstr cfgfil = NULL, outputfil = NULL, htmlfil = NULL;
    int rc = 0 - 10;
    int base = 0 - 10;
    int status = 0;
    QByteArray infile = inputfile.toUtf8();
    QByteArray outfi = outfile.toUtf8();
    htmlfil = infile.data();
    outputfil = outfi.data();
    rc = tidyParseFile( doc, htmlfil );

                if ( outputfil ) {
                    status = tidySaveFile( htmlfil , outputfil );
                } else {
                    status = tidySaveStdout( doc );
                }

    QFile f( outfile );
   if (!f.exists()) {
    //////////qDebug() <<
       QFile Imaged(inputfile);
      if (!Imaged.copy(outfile)) {
       ErrorMSG ="Not possibel to copy!";
       }
   } else {
    return true;
    }
    /// check if file exist if not copy in to out

return false;
}


/// prepare config tidy config file xml clean
bool QTidy::SetUp_xml()
{
    status = 0;
    ErrorMSG ="";
    TidyDoc doc = tidyCreate();
    bool ok;
    tidiconfigfile.clear();
    tidiconfigfile.append("input-xml: yes");
    tidiconfigfile.append("char-encoding: utf8");
    tidiconfigfile.append("output-encoding: ascii");
    tidiconfigfile.append("output-xml: yes");
    tidiconfigfile.append("hide-comments: no");
    tidiconfigfile.append("numeric-entities: yes");
    tidiconfigfile.append("add-xml-space: no");
    QString configtotsl = tidiconfigfile.join("\n");
    ok = tidy_file_set_config(configtotsl);
    if (ok) {
         QByteArray configfileti = TMP_Config.toUtf8();
         status = tidyLoadConfig( doc, configfileti.data() );
        if ( status != 0 ) {
         ErrorMSG ="Not possibel to load Config File!";
         return false;
        } else {
        return true;
        }
    } else {
      ErrorMSG ="Not possibel to load Config File!";
     return false;
    }
}

 */


