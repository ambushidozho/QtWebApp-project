#pragma once
#include <QMainWindow>
#include <QThread>
#include <QString>
#include <QTimer>
#include "Device.h"
#include "../UseCase/IMetricsUseCase.h"
#include "IMetricsUI.h"
#include "../UseCase/MetricsUseCase.h"
#include <memory>


QT_BEGIN_NAMESPACE
namespace Ui 
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public IMetricsUI
{
    Q_OBJECT
public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    void RefreshGUIdata();
    void UpdateResults(Device &result) override;
    void setUseCase(IMetricsUseCase* usecase);
    void startrefresh();
private:
    Ui::MainWindow* ui;
    QThread refresherThread;
    IMetricsUseCase* usecase_;   
};