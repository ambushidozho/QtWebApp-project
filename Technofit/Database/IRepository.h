#pragma once
#include "../../IRequest.h"
#include <string>

class IRepository
{
public:
    virtual void formQuery(IRequest& request) = 0;
    virtual void deserializeResponse(std::string& reply) = 0; // не понятно какой входной параметр пока что
};