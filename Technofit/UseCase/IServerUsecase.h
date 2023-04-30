#pragma once
#include "../../IRequest.h"


class IServerUsecase
{
public:
    virtual void ProcessRequest(IRequest& request) = 0;
};