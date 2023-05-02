#pragma once
#include "../Network/IMetricsNetwork.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>



struct MockMetricsNetwork : public IMetricsNetwork
{
    MOCK_METHOD(void, FetchStatistics, (int user_id), (override));
    MOCK_METHOD(void, OnGetReply, (IResponse& reply), (override));
    ~MockMetricsNetwork() override
    {

    }
};