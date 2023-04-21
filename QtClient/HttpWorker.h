#pragma once
#include <QObject>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QAuthenticator>
#include <QNetworkProxy>
#include <QBuffer>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <functional>
#include <QString>



class HttpWorker : public QObject
{
    Q_OBJECT
public:
    explicit HttpWorker(QObject *parent = nullptr);

public slots:
    QNetworkReply* get(QString location);
    QNetworkReply* post(QString location, QByteArray data);
private slots:
    // void readyRead();
    // void authenticationRequired(QNetworkReply *reply, QAuthenticator *authenticator);
    // void encrypted(QNetworkReply *reply);
    // void finished(QNetworkReply *reply);
    // void preSharedKeyAuthenticationRequired(QNetworkReply *reply, QSslPreSharedKeyAuthenticator *authenticator);
    // void proxyAuthenticationRequired(const QNetworkProxy &proxy, QAuthenticator *authenticator);
    // void sslErrors(QNetworkReply *reply, const QList<QSslError> &errors);
private:
    QNetworkAccessManager manager;
};