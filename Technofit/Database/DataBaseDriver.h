#pragma once
#include "IDataBaseDriver.h"
#include "IRepository.h"

class DataBaseDriver : public IDataBaseDriver
{
public:
    DataBaseDriver()
    {
       
    }
    void connect() override;
    void close() override;
    void get() override;
    void save() override;
    void setRepository(IRepository* repository)
    {
        repository_ = repository;
    }
private:
    IRepository* repository_;
};