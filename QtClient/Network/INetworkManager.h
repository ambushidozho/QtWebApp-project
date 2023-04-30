#pragma once
#include "../../IRequest.h"
#include "../../IResponse.h"


class INetworkManager
{
public:
    virtual ~INetworkManager()
    {

    }
    virtual void post(IRequest& request, std::vector<unsigned char>& body) = 0;    
    virtual void get(IRequest& request) = 0;


};

