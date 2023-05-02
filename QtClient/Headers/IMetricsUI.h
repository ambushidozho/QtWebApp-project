#pragma once
#include "Device.h"

class IMetricsUI
{
public:
    virtual void UpdateResults(Device &result) = 0;
    virtual ~IMetricsUI()
    {

    }
};