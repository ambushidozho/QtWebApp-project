#ifndef REQUESTMAPPER_H
#define REQUESTMAPPER_H
#include "httprequesthandler.h"
#include "DataHandlers.h"

class RequestHandler : public qtwebapp::HttpRequestHandler, public IHandler
{
	Q_OBJECT
	Q_DISABLE_COPY(RequestHandler)
  public:
	RequestHandler(QObject *parent = 0);

	~RequestHandler();
	
	void service(qtwebapp::HttpRequest &request, qtwebapp::HttpResponse &response) override;
	//void service(IRequest &request, IResponse &response) override;
};

#endif // REQUESTMAPPER_H
