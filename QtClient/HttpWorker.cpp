#include "HttpWorker.h"

HttpWorker::HttpWorker(QObject *parent) : QObject(parent)
{
    // тут по идее должен инициализироваться манагер
    // connect(&manager, &QNetworkAccessManager::authenticationRequired, this, &HttpWorker::authenticationRequired);
    // connect(&manager, &QNetworkAccessManager::encrypted, this, &HttpWorker::encrypted);
    // connect(&manager, &QNetworkAccessManager::finished, this, &HttpWorker::finished);
    // connect(&manager, &QNetworkAccessManager::preSharedKeyAuthenticationRequired, this, &HttpWorker::preSharedKeyAuthenticationRequired);
    // connect(&manager, &QNetworkAccessManager::proxyAuthenticationRequired, this, &HttpWorker::proxyAuthenticationRequired);
    // connect(&manager, &QNetworkAccessManager::sslErrors, this, &HttpWorker::sslErrors);
}

QNetworkReply* HttpWorker::get(QString location)
{
    QNetworkReply* reply =  manager.get(QNetworkRequest(QUrl(location)));
    //connect(reply, &QNetworkReply::readyRead, this, &HttpWorker::readyRead);
    return reply;
}
QNetworkReply* HttpWorker::post(QString location, QByteArray data)
{
    QNetworkRequest request = QNetworkRequest(QUrl(location));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "text/plain"); // ???????
    QNetworkReply* reply = manager.post(request, data);
    return reply;
}

// void HttpWorker::readyRead()
// {
//     qInfo() << "ReadyRead";

//     QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());
//     if(reply)
//     {
//         qInfo() << reply->readAll();
//     }

// }
// void HttpWorker::authenticationRequired(QNetworkReply *reply, QAuthenticator *authenticator)
// {
//     Q_UNUSED(reply);
//     Q_UNUSED(authenticator);
//     qInfo() << "authenticationRequired";
// }
// void HttpWorker::encrypted(QNetworkReply *reply)
// {
//     Q_UNUSED(reply);
//     qInfo() << "encrypted";
// }
// void HttpWorker::finished(QNetworkReply *reply)
// {
//     Q_UNUSED(reply);
//     qInfo() << "finished";
// }
// void HttpWorker::preSharedKeyAuthenticationRequired(QNetworkReply *reply, QSslPreSharedKeyAuthenticator *authenticator)
// {
//     Q_UNUSED(reply);
//     Q_UNUSED(authenticator);
//     qInfo() << "preSharedKeyAuthenticationRequired";
// }
// void HttpWorker::proxyAuthenticationRequired(const QNetworkProxy &proxy, QAuthenticator *authenticator)
// {
//     Q_UNUSED(proxy);
//     Q_UNUSED(authenticator);
//     qInfo() << "proxyAuthenticationRequired";
// }
// void HttpWorker::sslErrors(QNetworkReply *reply, const QList<QSslError> &errors)
// {
//     Q_UNUSED(proxy);
//     Q_UNUSED(errors);
//     qInfo() << "sslErrors";
// }