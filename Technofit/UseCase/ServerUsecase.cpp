#include "ServerUsecase.h"



std::string ServerUsecase::ProcessRequest(std::vector<unsigned char>& request) 
{
    return repository_->formQuery(request);
}

