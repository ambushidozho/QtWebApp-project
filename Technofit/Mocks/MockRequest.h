#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../../IRequest.h"

struct MockRequest : public IRequest
{
    MOCK_METHOD(void, SetHeader, (std::string header), (override));
    MOCK_METHOD(void, SetUrl, (std::string url), (override));
    MOCK_METHOD(void, SetBody, (std::vector<unsigned char>& body), (override));
    MOCK_METHOD(std::string, GetUrl, (), (override));
    MOCK_METHOD(std::string, GetHeader, (), (override));
    std::vector<unsigned char>& GetBody() override
    {
        std::vector<unsigned char> vc(1, '1');
        return vc;
    } 
};