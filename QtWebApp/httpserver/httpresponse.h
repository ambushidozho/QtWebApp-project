
#pragma once

#include "httpcookie.h"
#include "qtwebappglobal.h"
#include <QMap>
#include <QString>
#include <QTcpSocket>

namespace qtwebapp {
	class QTWEBAPP_EXPORT HttpResponse
	{
		Q_DISABLE_COPY(HttpResponse)
	  public:
		
		HttpResponse(QTcpSocket *socket);
	
		void setHeader(const QByteArray name, const QByteArray value);
	
		void setHeader(const QByteArray name, const int value);
	
		QMap<QByteArray, QByteArray> &getHeaders();
	
		QMap<QByteArray, HttpCookie> &getCookies();

		void setStatus(const int statusCode, const QByteArray description = QByteArray());

		int getStatusCode() const;

		void write(const QByteArray data, const bool lastPart = false);

		bool hasSentLastPart() const;

		void setCookie(const HttpCookie &cookie);

		void redirect(const QByteArray &url);

		void flush();

		bool isConnected() const;

	  private:

		QMap<QByteArray, QByteArray> headers;

		QTcpSocket *socket;

		int statusCode;

		QByteArray statusText;

		bool sentHeaders;

		bool sentLastPart;

		bool chunkedMode;

		QMap<QByteArray, HttpCookie> cookies;

		bool writeToSocket(QByteArray data);

		void writeHeaders();
	};

} // namespace qtwebapp
