#pragma once
#include <QtCore>
#include <QtGlobal>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QByteArray>
#include <QObject>
#include <QBuffer>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <functional>
#include <QString>
#include "Device.h"


class RefreshDataWorker : public QObject
{
    Q_OBJECT
public slots:
    void DoWork(const QString &parameter);
signals:
    void ResultReady(Device &result);
};