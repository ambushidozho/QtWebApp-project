#include "MetricsNetwork.h"
#include "../Mocks/MockNetworkManager.h"
#include "../Mocks/MockMetricsUseCase.h"
#include "../Mocks/MockResponse.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

class MetricsNetworkTest : public ::testing::Test
{
protected:
    void SetUp() override
    {

    }
    void TearDown() override
    {

    }
};

TEST_F(MetricsNetworkTest, FetchStatisticsTest){
    MockNetworkManager* networkmanager = new MockNetworkManager();
    MetricsNetwork network;
    network.setNetworkManager(networkmanager);
    EXPECT_CALL(*networkmanager, get(_,_));
    network.FetchStatistics(22);
    delete networkmanager;
}

TEST_F(MetricsNetworkTest, OnGetReplyTest){
    MockMetricsUseCase* usecase = new MockMetricsUseCase();
    MetricsNetwork network;
    MockResponse response;
    network.setReplyHandler(usecase);
    EXPECT_CALL(*usecase, OnFetchStatistics(_));
    network.OnGetReply(response);
    delete usecase;
}