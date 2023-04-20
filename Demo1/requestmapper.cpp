#include "requestmapper.h"

#include "controller/dumpcontroller.h"
#include "controller/fileuploadcontroller.h"
#include "controller/formcontroller.h"
#include "controller/logincontroller.h"
#include "controller/sessioncontroller.h"
#include "controller/templatecontroller.h"
#include "filelogger.h"
#include "global.h"
#include "staticfilecontroller.h"

#include <QCoreApplication>

using namespace qtwebapp;

RequestHandler::RequestHandler(QObject *parent) : HttpRequestHandler(parent) 
{
	qDebug("RequestHandler: created");
}

RequestHandler::~RequestHandler() 
{
	qDebug("RequestHandler: deleted");
}

void RequestHandler::service(HttpRequest &request, HttpResponse &response) 
{
	QByteArray path = request.getPath();
	qDebug("RequestHandler: path=%s", path.data());


	// Тут должны быть условия при которых вызывается нужный хендлер исходя из параметров урла запроса 



	// ........



	//



	// For the following pathes, each request gets its own new instance of the related controller.

	if (path.startsWith("/dump")) {
		DumpController().service(request, response);
	}

	else if (path.startsWith("/template")) {
		TemplateController().service(request, response);
	}

	else if (path.startsWith("/form")) {
		FormController().service(request, response);
	}

	else if (path.startsWith("/file")) {
		FileUploadController().service(request, response);
	}

	else if (path.startsWith("/session")) {
		SessionController().service(request, response);
	}

	else if (path.startsWith("/login")) {
		LoginController().service(request, response);
	}

	// All other pathes are mapped to the static file controller.
	// In this case, a single instance is used for multiple requests.
	else {
		staticFileController->service(request, response);
	}

	qDebug("RequestHandler: finished request");

	// Clear the log buffer
	if (logger) {
		logger->clear();
	}
}

void RequestHandler::service(IRequest &request, IResponse &response) 
{
	// Тут должны быть условия при которых вызывается нужный хендлер исходя из параметров урла запроса 



	// ........



	//
}
