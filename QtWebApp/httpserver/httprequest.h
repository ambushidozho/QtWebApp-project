#pragma once
#include "httpserverconfig.h"
#include "qtwebappglobal.h"
#include "../../Technofit/IRequestResponse.h"
#include <QByteArray>
#include <QHostAddress>
#include <QMap>
#include <QMultiMap>
#include <QTcpSocket>
#include <QTemporaryFile>
#include <QUuid>

namespace qtwebapp {

	class QTWEBAPP_EXPORT HttpRequest
	{
		Q_DISABLE_COPY(HttpRequest)
		friend class HttpSessionStore;

	  public:
		enum RequestStatus 
		{ 
			waitForRequest,
			waitForHeader,
			waitForBody,
			complete,
			abort 
		};
		HttpRequest(const HttpServerConfig &cfg);

		virtual ~HttpRequest();

		void readFromSocket(QTcpSocket *socket);

		RequestStatus getStatus() const;

		QByteArray getMethod() const;

		QByteArray getPath() const;

		const QByteArray &getRawPath() const; 

		QByteArray getVersion() const;

		QByteArray getHeader(const QByteArray &name) const;

		QList<QByteArray> getHeaders(const QByteArray &name) const;

		QMultiMap<QByteArray, QByteArray> getHeaderMap() const;

		QByteArray getParameter(const QByteArray &name) const;

		QList<QByteArray> getParameters(const QByteArray &name) const;

		QMultiMap<QByteArray, QByteArray> getParameterMap() const;

		QByteArray getBody() const;

		static QByteArray urlDecode(const QByteArray source);

		QFile *getUploadedFile(const QByteArray fieldName) const;

		QByteArray getCookie(const QByteArray &name) const;

		QMap<QByteArray, QByteArray> &getCookieMap();

		QHostAddress getPeerAddress() const;

	  private:

		QMultiMap<QByteArray, QByteArray> headers;

		QMultiMap<QByteArray, QByteArray> parameters;

		QMap<QByteArray, QTemporaryFile *> uploadedFiles;

		QMap<QByteArray, QByteArray> cookies;

		QByteArray bodyData;

		QByteArray method;

		QByteArray path;

		QByteArray version;

		RequestStatus status;

		QHostAddress peerAddress;

		int maxSize;

		int maxMultiPartSize;

		int currentSize;

		int expectedBodySize;

		QByteArray currentHeader;

		QByteArray boundary;

		QTemporaryFile *tempFile;

		void parseMultiPartFile();

		void readRequest(QTcpSocket *socket);

		void readHeader(QTcpSocket *socket);

		void readBody(QTcpSocket *socket);

		void decodeRequestParams();

		void extractCookies();

		QByteArray lineBuffer;

		QString tmpDir;
	};

} // namespace qtwebapp
