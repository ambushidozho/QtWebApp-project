#include "ResponseAdapter.h"
#include <QByteArray>

std::string ResponseAdapter::GetStatus() 
{
    return "OK";
}

std::vector<unsigned char> ResponseAdapter::GetBody() 
{
    QByteArray data = reply->readAll();
    const unsigned char* begin = reinterpret_cast<unsigned char*>(data.data());
    const unsigned char* end = begin + data.length();
    std::vector<unsigned char> body(begin, end);
    return body;
}