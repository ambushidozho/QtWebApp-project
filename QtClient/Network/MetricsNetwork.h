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
        
    }
    ~MetricsNetwork() override
    {
    }
    void FetchStatistics(int user_id) override;
    void OnGetReply(IResponse& reply) override;
    void setNetworkManager(INetworkManager* networkManager)
    {
        networkManager_ = networkManager;
    }
    void setReplyHandler(IMetricsNetworkHandler* replyHandler)
    {
        replyHandler_ = replyHandler;
    }
private:
    INetworkManager* networkManager_;
    IMetricsNetworkHandler* replyHandler_;
};