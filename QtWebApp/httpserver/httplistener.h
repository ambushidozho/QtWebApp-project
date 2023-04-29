#pragma once

#include "httpconnectionhandler.h"
#include "httpconnectionhandlerpool.h"
#include "httprequesthandler.h"
#include "httpserverconfig.h"
#include "qtwebappglobal.h"

#include <QBasicTimer>
#include <QTcpServer>

namespace qtwebapp {

	/**
	  Listens for incoming TCP connections and and passes all incoming HTTP requests to your implementation of
	  HttpRequestHandler, which processes the request and generates the response (usually a HTML document). <p> Example for
	  the required settings in the config file: <code><pre> ;host=192.168.0.100 port=8080 minThreads=1 maxThreads=10
	  cleanupInterval=1000
	  readTimeout=60000
	  ;sslKeyFile=ssl/my.key
	  ;sslCertFile=ssl/my.cert
	  maxRequestSize=16000
	  maxMultiPartSize=1000000
	  </pre></code>
	  The optional host parameter binds the listener to one network interface.
	  The listener handles all network interfaces if no host is configured.
	  The port number specifies the incoming TCP port that this listener listens to.
	  @see HttpConnectionHandlerPool for description of config settings minThreads, maxThreads, cleanupInterval and ssl
	  settings
	  @see HttpConnectionHandler for description of the readTimeout
	  @see HttpRequest for description of config settings maxRequestSize and maxMultiPartSize
	*/

	class QTWEBAPP_EXPORT HttpListener : public QTcpServer {
		Q_OBJECT
		Q_DISABLE_COPY(HttpListener)
	  public:

		HttpListener(const HttpServerConfig &cfg, HttpRequestHandler *requestHandler, QObject *parent = NULL);


		virtual ~HttpListener();

		void listen();

		void close();

	  protected:
		void incomingConnection(qintptr socketDescriptor);

	  private:
		HttpServerConfig cfg;

		HttpRequestHandler *requestHandler;

		HttpConnectionHandlerPool *pool;

	  signals:

		void handleConnection(qintptr socketDescriptor);
	};

} // namespace qtwebapp
