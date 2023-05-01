#pragma once
#include "../Database/IRepository.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

struct MockRepository : public IRepository
{
    MOCK_METHOD(std::string, formQuery, (std::vector<unsigned char>& request), (override));
};