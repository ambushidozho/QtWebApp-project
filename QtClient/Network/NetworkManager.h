#pragma once
#include "INetworkManager.h"
#include "../../IRequest.h"
#include "../../IResponse.h"
#include <QNetworkAccessManager>

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
    void post(IRequest& request, std::vector<unsigned char>& body, std::function<void(IResponse)> OnGetReply) override;    
    void get(IRequest& request, std::function<void(IResponse)> OnGetReply) override;
private:
    QNetworkAccessManager* networkmanager;
};