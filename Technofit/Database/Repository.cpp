#include "Repository.h"


void Repository::formQuery(IRequest& request)
{
    // формирует селект запрос передает его драйверу пока не знаю в каком виде ну допустим std::string
    databasedriver_->get();
}


void Repository::deserializeResponse(std::string& reply)
{
    // десериализует данные полученные данные из бд 
    // дергает usecase 
    replyhandler_->OnReplyFromDb(reply); // тоже непонятно какие но должны передаваться данные с дб
}