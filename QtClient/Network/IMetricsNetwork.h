#pragma once

class IMetricsNetwork
{
public:
    virtual void FetchStatistics(int user_id) = 0;
    virtual ~IMetricsNetwork() 
    {

    }
};