#pragma once
#include <vector>

class IRequest
{
public:
    virtual void SetHeader(std::string header) = 0;
    virtual void SetUrl(std::string url) = 0;
    virtual void SetBody(std::vector<unsigned char>& body) = 0;
    virtual std::vector<unsigned char>& GetBody() = 0;
    virtual std::string GetUrl() = 0;
    virtual std::string GetHeader() = 0;
};

