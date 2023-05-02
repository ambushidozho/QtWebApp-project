#pragma once
#include "../../IResponse.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>



struct MockResponse : public IResponse
{
    MOCK_METHOD(std::string, GetStatus, (), (override));
    MOCK_METHOD(std::vector<unsigned char>, GetBody, (), (override));
    MOCK_METHOD(void, write, (std::vector<unsigned char>& data), (override));
};