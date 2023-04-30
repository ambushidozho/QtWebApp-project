#pragma once
#include "IHandler.h"
#include "../IRequest.h"
#include "../IResponse.h"
#include "../UseCase/IServerUsecase.h"
#include <string>


class DeviceDataHandler : public IHandler
{
public:
	void service(IRequest &request, IResponse &response) override;
private:
	IServerUsecase* usecase_;
};

class ClientDataHandler : public IHandler
{
public:
	ClientDataHandler()
	{
		
	}
	void service(IRequest &request, IResponse &response) override;
	void setReply(std::string& reply)
	{
		reply_ = reply;
	}
	void setUsecase(IServerUsecase* usecase)
	{
		usecase_ = usecase;
	}
private:
	IServerUsecase* usecase_;
	std::string reply_;
};


class ClientMLHandler : public IHandler
{
public:
	void service(IRequest &request, IResponse &response) override;
private:
	IServerUsecase* usecase_;
};


