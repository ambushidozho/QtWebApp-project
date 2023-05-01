#pragma once
#include <string>

class IDataBaseDriver
{
public:
    virtual void connect() = 0;
    virtual void close() = 0;
    virtual void save() = 0;
    virtual std::string get(std::string query) = 0;
};