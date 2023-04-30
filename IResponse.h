#pragma once
#include <vector>
#include <string>


class IResponse
{
public:
    virtual std::string GetStatus() = 0;
    virtual std::vector<unsigned char> GetBody() = 0;
    virtual void write(std::vector<unsigned char>& data) = 0;
};