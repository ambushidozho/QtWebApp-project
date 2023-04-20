#pragma once
#include "IRequestResponse.h"
class IHandler
{
public:

	virtual void service(IRequest &request, IResponse &response) = 0;

private:

};