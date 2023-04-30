#pragma once

class IDataBaseDriver
{
public:
    virtual void connect() = 0;
    virtual void close() = 0;
    virtual void save() = 0;
    virtual void get() = 0;
};