#include "Repository.h"
#include "../Mocks/MockDataBaseDriver.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

class RepositoryTest : public ::testing::Test
{
protected:
    void SetUp() override
    {

    }
    void TearDown() override
    {

    }
};

TEST_F(RepositoryTest, formQueryTest){
    MockDataBaseDriver* mockdatabasedriver = new MockDataBaseDriver();
    Repository repository;
    repository.setDatabaseDriver(mockdatabasedriver);
    std::vector<unsigned char> mockrequest;
    EXPECT_CALL(*mockdatabasedriver, get(_));
    repository.formQuery(mockrequest);
    delete mockdatabasedriver;
}
