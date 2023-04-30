#pragma once
#include "IServerUsecase.h"
#include "IServerDatabase.h"
#include "../Handlers/IHandler.h"
#include "../Database/IRepository.h"


class ServerUsecase : public IServerDatabase, public IServerUsecase
{
public:
    void ProcessRequest(IRequest& request) override;
    void OnReplyFromDb(std::string& reply) override; // entry params!!!
    void setHandler(IHandler* handler)
    {
        handler_ = handler;
    }
	void setRepository(IRepository* repository)
    {
        repository_ = repository;
    }
private:
    IRepository* repository_;
    IHandler* handler_;
};
