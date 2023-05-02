#pragma once
#include "../UseCase/IMetricsUseCase.h"
#include "../UseCase/IMetricsNetworkHandler.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

struct MockMetricsUseCase : public IMetricsUseCase, public IMetricsNetworkHandler
{
    MOCK_METHOD(void, OnFetchStatistics, (Device& device), (override));
    MOCK_METHOD(void, RefreshData, (int user_id), (override));
    ~MockMetricsUseCase() override
    {

    }
};
