#pragma once
#ifndef REQUESTMAPPER_H
#define REQUESTMAPPER_H
#include "httprequesthandler.h"

class RequestHandler : public qtwebapp::HttpRequestHandler
{
	Q_OBJECT
	Q_DISABLE_COPY(RequestHandler)
  public:
	RequestHandler(QObject *parent = 0);

	~RequestHandler();
	
	void service(qtwebapp::HttpRequest &request, qtwebapp::HttpResponse &response) override;
};

#endif // REQUESTMAPPER_H
