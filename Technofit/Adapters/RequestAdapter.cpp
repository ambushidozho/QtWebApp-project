#include "RequestAdapter.h"



void RequestAdapter::SetHeader(std::string header)
{
    3;
}

void RequestAdapter::SetUrl(std::string url)
{
    3;
}

void RequestAdapter::SetBody(std::vector<unsigned char>& body)
{
    3;
}

std::vector<unsigned char>& RequestAdapter::GetBody()
{
    std::vector<unsigned char> vc;
    return vc;
}

std::string RequestAdapter::GetUrl()
{
    return "OK";
}

std::string RequestAdapter::GetHeader()
{
    return "OK";
}