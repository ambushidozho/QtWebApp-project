#include "DataBaseDriver.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

class DataBaseDriverTest : public ::testing::Test
{
protected:
    void SetUp() override
    {

    }
    void TearDown() override
    {

    }
};

TEST_F(DataBaseDriverTest, getTest){
    DataBaseDriver dbdriver;
    std::string expected_reply = "32 45 12";
    std::string reply = dbdriver.get(expected_reply);
    EXPECT_EQ(reply, expected_reply);
}
