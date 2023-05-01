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
    std::string get(std::string query) override;
    void save() override;
private:
};