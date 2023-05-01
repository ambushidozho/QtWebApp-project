#pragma once
#include "../Handlers/DataHandlers.h"
#include "../UseCase/IServerUsecase.h"
#include "../../IRequest.h"
#include "../../IResponse.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;
class Usecase : public IServerUsecase
{
public:
   
    void ProcessRequest(IRequest& request) override
    {
        
    }
};

class Request : public IRequest
{
public:
    void SetHeader(std::string header) override
    {
        3;
    }

    void SetUrl(std::string url) override
    {
        3;
    }

    void SetBody(std::vector<unsigned char>& body) override
    {
        3;
    }

    std::vector<unsigned char>& GetBody() override
    {
        std::vector<unsigned char> vc;
        return vc;
    }

    std::string GetUrl() override
    {
        return "OK";
    }

    std::string GetHeader() override
    {
        return "OK";
    }
};

class Response : public IResponse
{
public:
    
    std::string GetStatus() override
    {
        return "OK";
    }
    std::vector<unsigned char> GetBody() override
    {
        std::vector<unsigned char> vc;
        return vc;
    }
    void write(std::vector<unsigned char>& data) override
    {
        3;
    }
};

class MockUsecase : public Usecase
{
public:
    MOCK_METHOD(void, ProcessRequest, (IRequest& request), (override));
};

class MockRequest : public Request
{
public:
    // MOCK_METHOD(void, ProcessRequest, (IRequest& request), (override));
};

class MockResponse : public Response
{
public:
    MOCK_METHOD(std::vector<unsigned char>, GetBody, (), (override));
    MOCK_METHOD(std::string, GetStatus, (), (override));
    MOCK_METHOD(void, write, (std::vector<unsigned char>& data), (override));
};


TEST(DataHandlerTest, serviceTest)
{
    ClientDataHandler cdh;
    MockUsecase* usecase = new MockUsecase();
    MockRequest request;
    MockResponse response;
    cdh.setUsecase(usecase);

    EXPECT_CALL(*usecase, ProcessRequest(_))
    .Times(1);

    EXPECT_CALL(response, write(_));

    cdh.service(request, response);

}


