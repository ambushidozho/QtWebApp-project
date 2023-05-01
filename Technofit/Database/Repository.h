#pragma once
#include "IRepository.h"
#include "IDataBaseDriver.h"


class Repository : public IRepository
{
public:
    std::string formQuery(std::vector<unsigned char>& request) override;
    void setDatabaseDriver(IDataBaseDriver* databasedriver)
    {
        databasedriver_ = databasedriver;
    }
private:
    IDataBaseDriver* databasedriver_;
};