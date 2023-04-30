#pragma once
#include "../../IResponse.h"
#include "httpresponse.h"


class ResponseAdapter : public IResponse
{
public:
    ResponseAdapter(qtwebapp::HttpResponse* response)
    {
        response_ = response;
    }
    std::string GetStatus() override;
    std::vector<unsigned char> GetBody() override;
    void write(std::vector<unsigned char>& data) override;
private:
    qtwebapp::HttpResponse* response_;
};
