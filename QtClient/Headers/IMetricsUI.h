#pragma once


class IMetricsUI
{
public:
    virtual void UpdateResults(Device &result) = 0;
};