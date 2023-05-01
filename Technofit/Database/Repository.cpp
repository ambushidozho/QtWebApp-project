#include "Repository.h"


std::string Repository::formQuery(std::vector<unsigned char>& request)
{
    // формирует селект запрос передает его драйверу пока не знаю в каком виде ну допустим std::string
    std::string query = "here should be query";
    return databasedriver_->get(query);
}
