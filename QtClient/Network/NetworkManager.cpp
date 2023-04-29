#include "NetworkManager.h"
#include "ResponseAdapter.h"
#include <QNetworkReply>
#include <QUrl>
#include <QString>
#include <QByteArray>
#include <QNetworkRequest>


void NetworkManager::post(IRequest& request, std::vector<unsigned char>& body, std::function<void(IResponse)> OnGetReply)
{
    QNetworkRequest Qrequest;
    Qrequest.setUrl(QUrl(QString::fromStdString(request.GetUrl())));
    Qrequest.setRawHeader(QString::fromStdString(request.GetHeader()));
    QByteArray data;
    std::copy(body.begin(), body.end(), std::back_inserter(data));
    QNetworkReply *reply = networkmanager->post(Qrequest, data);
    ResponseAdapter response;
    response->SetReply(reply);
    OnGetReply(response);
}    

void NetworkManager::get(IRequest& request, std::function<void(IResponse)> OnGetReply)
{
    QNetworkRequest Qrequest;
    Qrequest.setUrl(QUrl(QString::fromStdString(request.GetUrl())));
    Qrequest.setRawHeader(QString::fromStdString(request.GetHeader()));
    QNetworkReply *reply = networkmanager->get(Qrequest);
    ResponseAdapter response;
    response->SetReply(reply);
    OnGetReply(response);
}