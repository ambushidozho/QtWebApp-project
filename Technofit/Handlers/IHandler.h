#pragma once
#include "../IRequest.h"
#include "../IResponse.h"
#include <string>

class IHandler
{
public:

	virtual void service(IRequest &request, IResponse &response) = 0;
	virtual void setReply(std::string& reply) = 0;
private:

};