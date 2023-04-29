#include "../Headers/mainwindow.h"
#include <QApplication>
#include "../Network/MetricsNetwork.h"
#include "../UseCase/MetricsUseCase.h"
#include <memory>
#include "../UseCase/IMetricsUseCase.h"
#include "../AppRoot.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    MainWindow mw_;
    AppRoot root(&mw_);
    root.usecase_->SetUIandNetwork(&mw_, root.network_);
    root.network_->setReplyHandler(root.usecase_);
    mw_.setUseCase(root.usecase_);
    mw_.show();
    mw_.startrefresh();
    return a.exec();
}