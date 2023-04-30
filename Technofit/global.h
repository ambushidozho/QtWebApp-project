#ifndef GLOBAL_H
#define GLOBAL_H

#include "filelogger.h"
#include "logger.h"
#include "httpsessionstore.h"
#include "staticfilecontroller.h"
#include "templatecache.h"

extern qtwebapp::TemplateCache *templateCache;

extern qtwebapp::HttpSessionStore *sessionStore;

extern qtwebapp::StaticFileController *staticFileController;

extern qtwebapp::Logger *logger;

#endif // GLOBAL_H
