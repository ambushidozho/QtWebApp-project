#include "RequestAdapter.h"
#include <QString>
#include <QUrl>

void RequestAdapter::SetHeader(std::string header)
{

}

void RequestAdapter::SetUrl(std::string url)
{
    request.setUrl(QUrl(QString::fromStdString(url)));
}


void RequestAdapter::SetBody(std::vector<unsigned char>& body)
{
    data = body;
}

std::vector<unsigned char>& RequestAdapter::GetBody()
{
    return data;
}

std::string RequestAdapter::GetUrl()
{
    QString qs = request.url().toString();
    return qs.toStdString();
}

std::string RequestAdapter::GetHeader()
{
    return "Hello";
}

QNetworkRequest RequestAdapter::GetQtRequest()
{
    return request;
}