#ifndef TEXTRECHANDER_H
#define TEXTRECHANDER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QDataStream>
#include <QNetworkInterface>
#include <QNetworkAddressEntry>

#include  "textrec.h"  //// option && define dir!




class QSslError;


class GetTessyFile: public QObject
{
    Q_OBJECT
    QNetworkAccessManager manager;
    QList<QNetworkReply *> currentDownloads;

public:
    GetTessyFile();
    void doDownList(const QStringList urilist );
    void doDownload(const QUrl &url);
    QString saveFileName(const QUrl &url);
    bool saveToDisk(const QString &filename, QIODevice *data);
signals:

    void jobtessReady();

public slots:
    void downloadRecProgress(qint64 r, qint64 tot);
    void downloadFinished(QNetworkReply *reply);
    void sslErrors(const QList<QSslError> &errors);
};








#endif // TEXTRECHANDER_H
