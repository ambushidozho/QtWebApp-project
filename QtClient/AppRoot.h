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
    }
    AppRoot()
    {

    }
    ~AppRoot()
    {
        delete usecase_;
        delete network_;
    }
    MetricsUseCase* usecase_;
    MetricsNetwork* network_;
    MainWindow* ui_;
};

