#include "NetworkManager.h"
#include "../Mocks/MockMetricsNetwork.h"
#include "../Mocks/MockRequest.h"
#include "../Mocks/MockResponse.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

class NetworkManagerTest : public ::testing::Test
{
protected:
    void SetUp() override
    {

    }
    void TearDown() override
    {

    }
};

TEST_F(NetworkManagerTest, getTest){
    MockMetricsNetwork* network = new MockMetricsNetwork();
    NetworkManager manager;
    MockRequest request;
    MockResponse response;
    manager.setMetricsNetwork(network);
    EXPECT_CALL(*network, OnGetReply(_));
    std::function<void(IResponse&)> lambda = [network](IResponse& response){
        network->OnGetReply(response);
    };
    //std::function<void(IResponse&)> q = [network, &response]() {network->OnGetReply(response);};
    manager.get(request, lambda);
    delete network;
}
