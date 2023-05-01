#include "../Mocks/MockRepository.h"
#include "ServerUsecase.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

class ServerUsecaseTest : public ::testing::Test
{
protected:
    void SetUp() override
    {

    }
    void TearDown() override
    {

    }
};

TEST_F(ServerUsecaseTest, ProcessRequestTest){
    MockRepository* mockrepository = new MockRepository();
    ServerUsecase usecase;
    std::vector<unsigned char> mockrequest;
    usecase.setRepository(mockrepository);
    EXPECT_CALL(*mockrepository, formQuery(_));
    usecase.ProcessRequest(mockrequest);
    delete mockrepository;
}
