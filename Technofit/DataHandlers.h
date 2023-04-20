#pragma once
#include "IHandler.h"


class DeviceHandler : public IHandler
{
public:
	void service(IRequest &request, IResponse &response) override;
private:

};

class ClientDataHandler : public IHandler
{
public:
	void service(IRequest &request, IResponse &response) override;
private:

};


class ClientMLHandler : public IHandler
{
public:
	void service(IRequest &request, IResponse &response) override;
private:

};


