#pragma once
#include "../UseCase/IMetricsNetworkHandler.h"
#include "IMetricsNetwork.h"
#include "../../IResponse.h"
#include "NetworkManager.h"
#include <memory>

class MetricsNetwork : public IMetricsNetwork
{
public:
    MetricsNetwork()
    {
        networkManager = new NetworkManager();
    }
    ~MetricsNetwork() override
    {
        delete networkManager;
    }
    void FetchStatistics(int user_id) override;
    void OnGetReply(IResponse& reply);
    void setReplyHandler(IMetricsNetworkHandler* replyHandler)
    {
        this->replyHandler = replyHandler;
    }
private:
    INetworkManager* networkManager;
    IMetricsNetworkHandler* replyHandler;
};