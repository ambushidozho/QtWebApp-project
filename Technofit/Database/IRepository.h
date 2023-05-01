#pragma once
#include "../../IRequest.h"
#include <string>

class IRepository
{
public:
    virtual std::string formQuery(std::vector<unsigned char>& request) = 0;
};