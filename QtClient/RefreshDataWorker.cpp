#include "QNetworkAccessManagerWrapper.h"
#include "HttpWorker.h"
#include "RefreshDataWorker.h"



void RefreshDataWorker::DoWork(const QString &parameter)
{
    HttpWorker httpworker;
    QNetworkReply* reply;
    // свич кейс надо дописать!!!!!
    // switch()
    // {
    // case post:
    //     QByteArray data = variantMapToJson(data); 
    //     reply = httpworker.post("тут должен быть урл", data);
    //     break;
    // case get:
    //     reply = httpworker.get("тут должен быть урл");
    //     break;

    // }
    // QJsonObject obj = parseReply(reply);
    // reply->close();
    // reply->deleteLater();

    // // дальше у меня есть json 
    Device result;
    // // заполняю структурку и отдаю как результат
    emit ResultReady(result);
}
// void RefreshDataWorker::ResultReady(Device &result)
// {
//     qInfo("results passed into mainwindow");
// } // multiply definition не знаю почему то эта функция обьявлена 2 раза

