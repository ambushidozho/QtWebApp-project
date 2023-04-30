#include "ResponseAdapter.h"
#include <QByteArray>

std::string ResponseAdapter::GetStatus()
{
    return "OK";
}
std::vector<unsigned char> ResponseAdapter::GetBody()
{
    std::vector<unsigned char> vc;
    return vc;
}
void ResponseAdapter::write(std::vector<unsigned char>& data)
{
    QByteArray qdata;
    std::copy(data.begin(), data.end(), std::back_inserter(qdata));
    response_->write(qdata);
}