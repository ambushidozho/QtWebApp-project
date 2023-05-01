#include "global.h"
#include "httplistener.h"
#include "Handlers/RequestHandler.h"
#include "logger.h"
#include <QCoreApplication>
#include <QDir>
#include <iostream>
#define DEBUG

using namespace qtwebapp;

QString searchConfigFile() {
	QString binDir = QCoreApplication::applicationDirPath();
	QString fileName("Technofit.ini");
	QStringList searchList;
	searchList.append(binDir);
	searchList.append(binDir + "/etc");
	searchList.append(binDir + "/../etc");
	searchList.append(binDir + "/../Technofit/etc");   
	searchList.append(binDir + "/../../Technofit/etc"); 
	searchList.append(QDir::rootPath() + "etc/opt");
	searchList.append(QDir::rootPath() + "etc");
	searchList.append("etc/");

	foreach (QString dir, searchList) {
		QFile file(dir + "/" + fileName);
		if (file.exists()) {
			fileName = QDir(file.fileName()).canonicalPath();
			qDebug("Using config file %s", qPrintable(fileName));
			return fileName;
		}
	}

	foreach (QString dir, searchList) {
		qWarning("%s/%s not found", qPrintable(dir), qPrintable(fileName));
	}
	qFatal("Cannot find config file %s", qPrintable(fileName));
	return nullptr;
}


int main(int argc, char *argv[]) {
	QCoreApplication app(argc, argv);
	app.setApplicationName("Technofit");

	QString configFileName = searchConfigFile();
	
	logger = new Logger(&app);
	logger->installMsgHandler();

	// Configure template loader and cache
	QSettings *templateSettings = new QSettings(configFileName, QSettings::IniFormat, &app);
	templateSettings->beginGroup("templates");
	templateCache = new TemplateCache(templateSettings, &app);

	QSettings *sessionSettings = new QSettings(configFileName, QSettings::IniFormat, &app);
	sessionSettings->beginGroup("sessions");
	sessionStore = new HttpSessionStore(sessionSettings, &app);

	//Configure static file controller
	QSettings *fileSettings = new QSettings(configFileName, QSettings::IniFormat, &app);
	fileSettings->beginGroup("docroot");
	staticFileController = new StaticFileController(fileSettings, &app);

	// Configure and start the TCP listener
	QSettings *listenerSettings = new QSettings(configFileName, QSettings::IniFormat, &app);
	listenerSettings->beginGroup("listener");
	new HttpListener(listenerSettings, new RequestHandler(&app), &app);
	app.exec();
	qInfo("Application has stopped");
}
