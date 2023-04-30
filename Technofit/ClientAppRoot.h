#pragma once
#include "Database/DataBaseDriver.h"
#include "Database/Repository.h"
#include "UseCase/ServerUsecase.h"
#include "Handlers/DataHandlers.h"



class ClientAppRoot
{
public:
    ClientAppRoot()
    {
        databasedriver_ = new DataBaseDriver();
        repository_ = new Repository();
        usecase_ = new ServerUsecase();
        cdh_ = new ClientDataHandler();
    }
    ~ClientAppRoot()
    {
        delete usecase_;
        delete repository_;
        delete databasedriver_;
        delete cdh_;
    }
    DataBaseDriver* databasedriver_;
    Repository* repository_;
    ServerUsecase* usecase_;
    ClientDataHandler* cdh_;
};
