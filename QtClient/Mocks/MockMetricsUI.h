#pragma once
#include "../Headers/IMetricsUI.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

struct MockMetricsUI : public IMetricsUI
{
    MOCK_METHOD(void, UpdateResults, (Device &result), (override));
    ~MockMetricsUI() override
    {

    }
};