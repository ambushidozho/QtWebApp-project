#pragma once
#include "../Network/INetworkManager.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

 
struct MockNetworkManager : public INetworkManager
{
    MOCK_METHOD(void, post, (IRequest& request, std::vector<unsigned char>& body, std::function<void(IResponse&)> const& OnGetReply), (override));
    MOCK_METHOD(void, get, (IRequest& request, std::function<void(IResponse&)> const& OnGetReply), (override));
    ~MockNetworkManager() override
    {

    }
};