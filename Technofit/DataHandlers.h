#pragma once
#include "IHandler.h"
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>

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


