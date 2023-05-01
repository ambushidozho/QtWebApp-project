cmake_minimum_required(VERSION 3.0.0)
project("QtWebApp Technofit")

set(CMAKE_AUTOMOC ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED HINTS $ENV{Qt6_DIR} $ENV{Qt5_DIR})
find_package(Qt6 COMPONENTS Core5Compat REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Network REQUIRED)
if (${QT_VERSION_MAJOR} EQUAL 6)
    find_package(Qt6 COMPONENTS Core5Compat REQUIRED)
endif()

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
	ClientAppRoot.h
	main.cpp
	Handlers/RequestHandler.cpp
	Handlers/RequestHandler.h
	Handlers/IHandler.h
	Handlers/DataHandlers.h
	Handlers/DataHandlers.cpp
	UseCase/IServerUsecase.h
	UseCase/ServerUsecase.h
	UseCase/ServerUsecase.cpp
	Database/DataBaseDriver.cpp
	Database/IDataBaseDriver.h
	Database/DataBaseDriver.h
	Database/Repository.h
	Database/Repository.cpp
	Database/IRepository.h
	Adapters/RequestAdapter.h
	Adapters/RequestAdapter.cpp
	Adapters/ResponseAdapter.h
	Adapters/ResponseAdapter.cpp
	../IRequest.h
	../IResponse.h
)

add_executable(TechnofitTest
	main_test.cpp
	Handlers/DataHandlers.h
	Handlers/DataHandlers.cpp
	Handlers/DataHandlerTests.cpp
	Database/IRepository.h
	Database/Repository.h
	Database/Repository.cpp
	Database/RepositoryTests.cpp
	Database/IDataBaseDriver.h
	Database/DataBaseDriver.h
	Database/DataBaseDriver.cpp
	Database/DataBaseDriverTests.cpp
	UseCase/IServerUsecase.h
	UseCase/ServerUsecase.h
	UseCase/ServerUsecase.cpp
	UseCase/ServerUsecaseTests.cpp
	../IRequest.h
	../IResponse.h
)

target_link_libraries(TechnofitTest -lgtest -lgmock)
target_link_libraries(Technofit QtWebAppGlobal QtWebAppLogging QtWebAppHttpServer QtWebAppTemplateEngine)
target_include_directories(Technofit PUBLIC ../QtWebApp/httpserver ../QtWebApp/logging ../QtWebApp/templateengine ../QtWebApp)
target_link_libraries(Technofit Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(Technofit Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Network)
if (${QT_VERSION_MAJOR} EQUAL 6)
    target_link_libraries(Technofit Qt6::Core5Compat)
endif()




