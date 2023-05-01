#include "MetricsNetwork.h"
#include "../RequestAdapter.h"
#include "../Headers/Device.h"

void MetricsNetwork::OnGetReply(IResponse& reply)
{
    // parse reply
    Device device;
    replyHandler_->OnFetchStatistics(device);
}

void MetricsNetwork::FetchStatistics(int user_id) 
{
    RequestAdapter request;
    std::function<void(IResponse&)> lambda = [this](IResponse& reply){
        OnGetReply(reply);
    };
    //формируется реквест, делается гет запрос
    networkManager_->get(request, lambda);
}