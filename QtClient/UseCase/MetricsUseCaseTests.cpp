#include "MetricsUseCase.h"
#include "../Mocks/MockMetricsUI.h"
#include "../Mocks/MockMetricsNetwork.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

class MetricsUseCaseTest : public ::testing::Test
{
protected:
    void SetUp() override
    {

    }
    void TearDown() override
    {

    }
};

TEST_F(MetricsUseCaseTest, OnFetchStatistics){
    MockMetricsUI* mockui = new MockMetricsUI();
    MetricsUseCase usecase;
    usecase.SetUI(mockui);
    EXPECT_CALL(*mockui, UpdateResults(_));
    Device device;
    usecase.OnFetchStatistics(device);
    delete mockui;
}

TEST_F(MetricsUseCaseTest, RefreshDataTest){
    MockMetricsNetwork* mocknetwork = new MockMetricsNetwork();
    MetricsUseCase usecase;
    usecase.SetNetwork(mocknetwork);
    EXPECT_CALL(*mocknetwork, FetchStatistics(_));
    usecase.RefreshData(22);
    delete mocknetwork;
}