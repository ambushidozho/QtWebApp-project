#pragma once
#include "../../IResponse.h"
class IMetricsNetwork
{
public:
    virtual void FetchStatistics(int user_id) = 0;
    virtual void OnGetReply(IResponse& reply) = 0;
    virtual ~IMetricsNetwork() 
    {

    }
};