#include "ServerUsecase.h"



void ServerUsecase::ProcessRequest(IRequest& request) 
{
    repository_->formQuery(request);
}


void ServerUsecase::OnReplyFromDb(std::string& reply)
{
    // отдаю хендлеру данные которые он отправит
    handler_->setReply(reply);
}