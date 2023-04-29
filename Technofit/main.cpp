#include "global.h"
#include "httplistener.h"
#include "RequestHandler.h"
#include <QCoreApplication>
#include <QDir>


using namespace qtwebapp;

/** Search the configuration file */
QString searchConfigFile() {
	QString binDir = QCoreApplication::applicationDirPath();
	QString fileName("Technofit.ini");
	QStringList searchList;
	searchList.append(binDir);
	searchList.append(binDir + "/etc");
	searchList.append(binDir + "/../etc");
	searchList.append(binDir + "/../Technofit/etc");    // for development with shadow build (Linux)
	searchList.append(binDir + "/../../Technofit/etc"); // for development with shadow build (Windows)
	searchList.append(QDir::rootPath() + "etc/opt");
	searchList.append(QDir::rootPath() + "etc");

	foreach (QString dir, searchList) {
		QFile file(dir + "/" + fileName);
		if (file.exists()) {
			fileName = QDir(file.fileName()).canonicalPath();
			qDebug("Using config file %s", qPrintable(fileName));
			return fileName;
		}
	}

	// not found
	foreach (QString dir, searchList) {
		qWarning("%s/%s not found", qPrintable(dir), qPrintable(fileName));
	}
	qFatal("Cannot find config file %s", qPrintable(fileName));
	return nullptr;
}

/**
  Entry point of the program.
*/
int main(int argc, char *argv[]) {
	QCoreApplication app(argc, argv);
	app.setApplicationName("Demo1");

	QString configFileName = searchConfigFile();

	QSettings *logSettings = new QSettings(configFileName, QSettings::IniFormat, &app);
	logSettings->beginGroup("logging");
	FileLogger *logger = new FileLogger(logSettings, 10000, &app);
	logger->installMsgHandler();

	//Configure template loader and cache
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
