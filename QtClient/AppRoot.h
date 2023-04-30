#include "Network/IMetricsNetwork.h"
#include "UseCase/IMetricsUseCase.h"
#include "Headers/IMetricsUI.h"
#include "UseCase/MetricsUseCase.h"
#include "Network/MetricsNetwork.h"

class AppRoot
{
public:
    AppRoot(MainWindow* ui) : ui_(ui)
    {
        usecase_ = new MetricsUseCase();
        network_ = new MetricsNetwork();
        networkManager_ = new NetworkManager();
    }
    ~AppRoot()
    {
        delete usecase_;
        delete network_;
        delete networkManager_;
    }
    MetricsUseCase* usecase_;
    MetricsNetwork* network_;
    NetworkManager* networkManager_;
    MainWindow* ui_;
};

