#pragma once
#include "../../IRequest.h"
#include "../../IResponse.h"


class INetworkManager
{
public:
    virtual ~INetworkManager()
    {

    }
    virtual void post(IRequest& request, std::vector<unsigned char>& body, std::function<void(IResponse&)> const& OnGetReply) = 0;    
    virtual void get(IRequest& request, std::function<void(IResponse&)> const& OnGetReply) = 0;


};

