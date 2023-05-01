#pragma once
#include "../UseCase/IServerUsecase.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>




struct MockUsecase : public IServerUsecase
{
    MOCK_METHOD(std::string, ProcessRequest, (std::vector<unsigned char>& request), (override));
};