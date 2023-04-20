cmake_minimum_required(VERSION 2.8.11)
project("QtWebApp Technofit")

set(CMAKE_AUTOMOC ON)

#find_package(QtWebApp REQUIRED COMPONENTS HttpServer Logging TemplateEngine)
find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED HINTS $ENV{Qt6_DIR} $ENV{Qt5_DIR})
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Network REQUIRED)
find_package(Qt6 COMPONENTS Core5Compat REQUIRED)

add_executable(Technofit
	controller/dumpcontroller.cpp
	controller/dumpcontroller.h
	controller/fileuploadcontroller.cpp
	controller/fileuploadcontroller.h
	controller/formcontroller.cpp
	controller/formcontroller.h
	controller/logincontroller.cpp
	controller/logincontroller.h
	controller/sessioncontroller.cpp
	controller/sessioncontroller.h
	controller/templatecontroller.cpp
	controller/templatecontroller.h
	documentcache.h
	global.cpp
	global.h
	main.cpp
	requestmapper.cpp
	requestmapper.h
)
#target_link_libraries(test gtest gmock pthread)
#target_link_libraries(demo1 ${QtWebApp_LIBRARIES})
target_link_libraries(Technofit QtWebAppGlobal QtWebAppLogging QtWebAppHttpServer QtWebAppTemplateEngine)
target_include_directories(Technofit PUBLIC ../QtWebApp/httpserver ../QtWebApp/logging ../QtWebApp/templateengine ../QtWebApp)
target_link_libraries(Technofit Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(Technofit QtWebAppGlobal Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Network)
target_link_libraries(Technofit Qt6::Core5Compat)
