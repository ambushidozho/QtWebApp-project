/**
  @file
  @author Stefan Frings
*/

#pragma once

#include "httprequest.h"
#include "httpresponse.h"
#include "qtwebappglobal.h"
#include "../Technofit/IRequestResponse.h"
namespace qtwebapp 
{
	class QTWEBAPP_EXPORT HttpRequestHandler : public QObject {
		Q_OBJECT
		Q_DISABLE_COPY(HttpRequestHandler)
	  public:
	
		HttpRequestHandler(QObject *parent = nullptr) : QObject(parent) {}

	
		virtual void service(HttpRequest &request, HttpResponse &response) = 0;
	};

} // namespace qtwebapp
