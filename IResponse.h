#pragma once
#include <vector>


class IResponse
{
    virtual std::string GetStatus() = 0;
    virtual std::vector<unsigned char> GetBody() = 0;
};