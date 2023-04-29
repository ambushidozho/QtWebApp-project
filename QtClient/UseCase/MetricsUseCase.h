#pragma once
#include "IMetricsUseCase.h"
#include "../Headers/IMetricsUI.h"
#include "../Network/IMetricsNetwork.h"
#include "IMetricsNetworkHandler.h"
#include "../Headers/Device.h"
#include "../Headers/mainwindow.h"
#include <memory>

class MetricsUseCase : public IMetricsUseCase, public IMetricsNetworkHandler
{
public:
    void SetUIandNetwork(IMetricsUI* ui,  IMetricsNetwork* network)
    {
        this->ui = ui;
        this->network_ = network;
    }
    ~MetricsUseCase() override
    {

    }
    void OnFetchStatistics(Device& device) override;
    void RefreshData(int user_id) override; 
private:
    IMetricsUI* ui;
    IMetricsNetwork* network_;
};