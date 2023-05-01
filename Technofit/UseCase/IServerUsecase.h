#pragma once
#include "../../IRequest.h"


class IServerUsecase
{
public:
    virtual std::string ProcessRequest(std::vector<unsigned char>& request) = 0;
};