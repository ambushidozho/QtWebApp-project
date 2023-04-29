#pragma once
#include "../IRequest.h"
#include "../IResponse.h"



class RequestAdapter : public IRequest
{
public:
    RequestAdapter()
    {
    }
    QNetworkRequest GetQtRequest();
    void SetHeader(std::string header) override;
    void SetUrl(std::string url) override;
    void SetBody(std::vector<unsigned char> body) override;
private:
    qtwebapp::HttpRequest request;
};

class ResponseAdapter : public IResponse
{
public:
    std::string GetStatus() override;
    std::vector<unsigned char> GetBody() override;
    void SetReply(QNetworkReply* reply)
    {
        this->reply = reply;
    }
private:
    qtwebapp::HttpResponse response;
};