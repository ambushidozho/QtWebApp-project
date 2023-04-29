#pragma once
#include <QNetworkRequest>
#include <vector>
#include "../IRequest.h"



class RequestAdapter : public IRequest
{
public:
    RequestAdapter()
    {

    }
    QNetworkRequest GetQtRequest();
    void SetHeader(std::string header) override;
    void SetUrl(std::string url) override;
    void SetBody(std::vector<unsigned char>& body) override;
    std::vector<unsigned char>& GetBody() override;
    std::string GetUrl() override;
    std::string GetHeader() override;
private:
    QNetworkRequest request;
    std::vector<unsigned char> data;
};

