#pragma once
#include "../Headers/Device.h"

class IMetricsNetworkHandler
{
public:
    virtual void OnFetchStatistics(Device& device) = 0;
};