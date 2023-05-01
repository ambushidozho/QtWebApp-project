#pragma once
#include "../Database/IDataBaseDriver.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>



struct MockDataBaseDriver : public IDataBaseDriver
{
    MOCK_METHOD(std::string, get, (std::string query), (override));
    MOCK_METHOD(void, connect, (), (override));
    MOCK_METHOD(void, close, (), (override));
    MOCK_METHOD(void, save, (), (override));
};