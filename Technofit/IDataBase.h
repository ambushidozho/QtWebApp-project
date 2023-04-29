

class IDataBase
{
    virtual void Connect() = 0;
    virtual void Close() = 0;
    virtual void Save() = 0;
    virtual void Get() = 0;
};