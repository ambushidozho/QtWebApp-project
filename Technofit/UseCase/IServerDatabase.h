#pragma once

class IServerDatabase
{
public:
    virtual void OnReplyFromDb(std::string& reply) = 0; // входной параметр пока не знаю в каком виде
};