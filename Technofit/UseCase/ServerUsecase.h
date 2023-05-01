#pragma once
#include "IServerUsecase.h"
#include "../Database/IRepository.h"


class ServerUsecase : public IServerUsecase
{
public:
    std::string ProcessRequest(std::vector<unsigned char>& request) override;
	void setRepository(IRepository* repository)
    {
        repository_ = repository;
    }
private:
    IRepository* repository_;
};
