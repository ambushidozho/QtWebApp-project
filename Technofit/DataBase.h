#include "IDataBase.h"
#include <QSqlDatabase>

class DataBase : IDataBase
{
public:
    DataBase()
    {
       
    }
    void Connect() override
    {
        db = QsqlDatabase::addDatabase("type of driver", "name");
        db.setHostName("name");
        db.setDatabaseName("name");
        db.setUserName("name");
        db.setPassword("pass");
        if(db.open())
        {
            //opened
        }
        else
        {
            //error
        }
    }
    void Close() override
    {

    }
    void Get() override
    {
        
    }
    void Save() override
    {

    }
private:
    QSqlDatabase db;
};