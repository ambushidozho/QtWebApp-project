#include <QPixmap>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QNetworkAccessManagerWrapper.h"
#include "RefreshDataWorker.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix1(":/img/img/icons8-сердце-с-пульсом-48.png");
    int w = ui->pic1_pulse->width() + 20;
    int h = ui->pic1_pulse->height() + 20;
    ui->pic1_pulse->setPixmap(pix1.scaled(w,h,Qt::KeepAspectRatio));
    QPixmap pix2(":/img/img/icons8-кислород-64.png");
    w = ui->pic2_O2->width() + 20;
    h = ui->pic2_O2->height() + 20;
    ui->pic2_O2->setPixmap(pix2.scaled(w,h,Qt::KeepAspectRatio));
    QPixmap pix3(":/img/img/icons8-температура-64.png");
    w = ui->pic3_Temprature->width() + 20;
    h = ui->pic3_Temprature->height() + 20;
    ui->pic3_Temprature->setPixmap(pix3.scaled(w,h,Qt::KeepAspectRatio));

    RefreshDataWorker *refresher = new RefreshDataWorker;
    refresher->moveToThread(&refresherThread); //MainWindow has a private member QThread refresherThread
    connect(&refresherThread, &QThread::finished, refresher, &QObject::deleteLater);
    connect(this, &MainWindow::RefreshGUIdata, refresher, &RefreshDataWorker::DoWork); //MainWindow has a signal which tells the worker class to start
    connect(refresher, &RefreshDataWorker::ResultReady, this, &MainWindow::UpdateResults); //Gets results back from the worker when it's finished
    refresherThread.start();    


    // график данных
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::RefreshGUIdata(const QString &parameter)
{
    
}

void MainWindow::UpdateResults(Device &result)
{
    ui->pulse_label->setText(QString::number(result.get_pulse()));
    ui->O2_label->setText(QString::number(result.get_O2()));
    ui->Temprature_label->setText(QString::number(result.get_temprature()));
    //ui->name_label->setText(result.get_name());
    // записывает результат в gui
}

void MainWindow::DeviceConnected()
{
    QTimer* timer = new QTimer(this);
    connect (timer, SIGNAL(timeout()), this, SLOT(RefreshGUIdata));
    timer->start(1000);
}

// void MainWindow::Controller::handleResults( Device &result)
// {
//     // не уверен нужна ли мне эта прослойка с контроллером
// }

// void MainWindow::Controller::triggerRefresherToWork( QString &parameter)
// {
//     // не уверен нужна ли мне эта прослойка с контроллером
// }





// будет кнопка которая делает запрос на создание новго девайса если он есть в бд
// то он будет создан в клиенте


// будет кнопка которая делает запрос на прогноз данных
// данные будут возвращены и отображены