#pragma once
#include <QNetworkReply>
#include "../IResponse.h"

class ResponseAdapter : public IResponse
{
public:
    std::string GetStatus() override;
    std::vector<unsigned char> GetBody() override;
    void write(std::vector<unsigned char>& data) override
    {
        
    }
    void SetReply(QNetworkReply* reply)
    {
        this->reply = reply;
    }
private:
    QNetworkReply* reply;
};