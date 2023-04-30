#include "DataBaseDriver.h"




void DataBaseDriver::connect() 
{

}
void DataBaseDriver::close() 
{

}
void DataBaseDriver::get()
{
    // получает запрос как входной параметр делает запрос отдаёт репозиторию результат
    std::string reply = "32 45 12";
    repository_->deserializeResponse(reply);
}
void DataBaseDriver::save()
{
    
}