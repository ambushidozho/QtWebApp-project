#include "DataHandlers.h"
#include "../Mocks/MockUsecase.h"
#include "../Mocks/MockRequest.h"
#include "../Mocks/MockResponse.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

class DataHandlerTest : public ::testing::Test
{
protected:
    void SetUp() override
    {

    }
    void TearDown() override
    {

    }
};

TEST_F(DataHandlerTest, first){
    MockUsecase* mockusecase = new MockUsecase();
    ClientDataHandler cdh;
    cdh.setUsecase(mockusecase);
    MockRequest request;
    MockResponse response;
    EXPECT_CALL(*mockusecase, ProcessRequest(_));
    cdh.service(request, response);
    delete mockusecase;
}