#pragma once
#include <QMainWindow>
#include <QThread>
#include <QString>
#include "Device.h"


QT_BEGIN_NAMESPACE
namespace Ui 
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    void RefreshGUIdata(const QString &parameter);
    void UpdateResults(Device &result); // тут я не уверен насчёт общности кода но вроде бы я должен получать именно device как результат а не qstring
    void DeviceConnected();
private:
    Ui::MainWindow* ui;
    QThread refresherThread;
    // class Controller : public QObject
    // {
    //     Q_OBJECT
    // private:

    // public:
    //     Controller();
    //     ~Controller();
    // public slots:
    //     void handleResults(const Device &result);
    // signals:
    //     void triggerRefresherToWork(const QString &parameter);
    // };
};