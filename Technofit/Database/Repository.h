#pragma once
#include "IRepository.h"
#include "IDataBaseDriver.h"
#include "../UseCase/IServerDatabase.h"


class Repository : public IRepository
{
public:
    void formQuery(IRequest& request) override;
    void deserializeResponse(std::string& reply) override;
    void setUsecase(IServerDatabase* replyhandler)
    {
        replyhandler_ = replyhandler;
    }
    void setDatabaseDriver(IDataBaseDriver* databasedriver)
    {
        databasedriver_ = databasedriver;
    }
private:
    IDataBaseDriver* databasedriver_;
    IServerDatabase* replyhandler_;
};