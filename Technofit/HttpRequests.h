#pragma once
#include "IRequestResponse.h"
#include "httprequest.h"
#include "httpresponse.h"


class Response : public IResponse
{
public:
    
private:
    

}


class Request : public IRequest
{
public:

private:

}


class RequestAdapter : public qtwebapp::HttpRequest
{
private:
    Request request_;
public:
    RequestAdapter(Request request);

}



