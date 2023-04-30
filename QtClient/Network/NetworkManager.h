#pragma once
#include "INetworkManager.h"
#include "../../IRequest.h"
#include "../../IResponse.h"
#include <QNetworkAccessManager>
#include "IMetricsNetwork.h"

class NetworkManager : public INetworkManager
{
public:
    NetworkManager()
    {
        networkmanager = new QNetworkAccessManager;
    }
    ~NetworkManager() override
    {
        
    }
    void setMetricsNetwork(IMetricsNetwork* network)
    {
        network_ = network;
    }
    void post(IRequest& request, std::vector<unsigned char>& body) override;    
    void get(IRequest& request) override;
private:
    QNetworkAccessManager* networkmanager;
    IMetricsNetwork* network_;
};