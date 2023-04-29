#include "MetricsNetwork.h"
#include "../RequestAdapter.h"
#include "Device.h"

void MetricsNetwork::OnGetReply(IResponse& reply)
{
    // parse reply
    Device device;
    replyHandler.OnFetchStatistics(device);
}

void MetricsNetwork::FetchStatistics(int user_id) 
{
    RequestAdapter request;
    //формируется реквест, делается гет запрос
    networkManager.get(request, OnGetReply)
}


