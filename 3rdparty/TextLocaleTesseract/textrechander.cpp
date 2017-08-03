#include <QVector>
#include <QLocale>
#include <QVector>
#include <QVectorIterator>
#include <QMap>

#include "textrechander.h"
#include "textrec.h"
#include "textrecdown.h"
#include "textrec.h"


GetTessyFile::GetTessyFile()
{
    connect(&manager, SIGNAL(finished(QNetworkReply*)),
            SLOT(downloadFinished(QNetworkReply*)));
}

void GetTessyFile::downloadRecProgress(qint64 r, qint64 tot) {
    QTextStream xc(stdout);
    xc << "\t\tIn:" << bytesToSize(r) << "|" << bytesToSize(tot) << "\r";
    xc.flush();
    /// emit downstatus(r,tot);
}


void GetTessyFile::doDownList(const QStringList urilist ) {

   for (int i = 0; i < urilist.size(); ++i) {
         QUrl orecurl(urilist.at(i));
         this->doDownload(orecurl);
     }
}

void GetTessyFile::doDownload(const QUrl &url)
{
    QNetworkRequest request(url);
    QNetworkReply *reply = manager.get(request);
#ifndef QT_NO_SSL
    connect(reply, SIGNAL(sslErrors(QList<QSslError>)), SLOT(sslErrors(QList<QSslError>)));
#endif
    connect(reply, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(downloadRecProgress(qint64, qint64)));
    currentDownloads.append(reply);
}

QString GetTessyFile::saveFileName(const QUrl &url)
{

  /////QUrl potest( test , QUrl::StrictMode );
  const QString diruri("/tesseract-ocr/langdata/master/");
    if ( url.path().indexOf(diruri) ==-1 ) {
      return QString();
    }
    QString full_local_path_file_base = url.path().replace(diruri,__DIRBASICTESSY__);
    return full_local_path_file_base;
}

bool GetTessyFile::saveToDisk(const QString &filename, QIODevice *data)
{
  QFileInfo fi(filename);
  QDir dir;
       if(!dir.exists(fi.absolutePath())) {
           dir.mkpath(fi.absolutePath());
        }
          QFile file(filename);
         if (fi.exists()) {
            file.remove();
          }

        if (!file.open(QIODevice::WriteOnly)) {
            fprintf(stderr, "Could not open %s for writing: %s\n",
                    qPrintable(filename),
                    qPrintable(file.errorString()));
            return false;
        }

      file.write(data->readAll());
      file.close();
      return true;
}


void GetTessyFile::sslErrors(const QList<QSslError> &sslErrors)
{
   /////  return;
#ifdef QT_NO_SSL_ERROR
    foreach (const QSslError &error, sslErrors)
        fprintf(stderr, "SSL error: %s\n", qPrintable(error.errorString()));
#else
    Q_UNUSED(sslErrors);
#endif
}

void GetTessyFile::downloadFinished(QNetworkReply *reply)
{
    QUrl url = reply->url();
    if (reply->error()) {
        fprintf(stderr, "Download of %s failed: %s\n",
                url.toEncoded().constData(),
                qPrintable(reply->errorString()));
    } else {
        QString filename = saveFileName(url);
        if (saveToDisk(filename, reply)) {
            printf("ok.");
      }
            //// printf("Download of %s succeeded (saved to %s)\n", url.toEncoded().constData(), qPrintable(filename));
    }

    currentDownloads.removeAll(reply);
    reply->deleteLater();

      if (currentDownloads.isEmpty()) {
        emit jobtessReady();
      }
}



