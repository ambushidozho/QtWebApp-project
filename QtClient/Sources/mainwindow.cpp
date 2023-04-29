#include <QPixmap>
#include "../Headers/mainwindow.h"
#include "ui_mainwindow.h"


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

    // график данных
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUseCase(IMetricsUseCase* usecase)
{
    usecase_ = usecase;
}

void MainWindow::UpdateResults(Device &result)
{
    ui->pulse_label->setText(QString::number(result.get_pulse()));
    ui->O2_label->setText(QString::number(result.get_O2()));
    ui->Temprature_label->setText(QString::number(result.get_temprature()));
    //ui->name_label->setText(result.get_name());
    // записывает результат в gui
    show();
}

void MainWindow::RefreshGUIdata()
{
    
    usecase_->RefreshData(22);
}

void MainWindow::startrefresh()
{
    QTimer* timer = new QTimer(this);
    timer->setInterval(1000);
    connect (timer, SIGNAL(timeout()), this, SLOT(RefreshGUIdata));
    timer->start(1000);
}


// будет кнопка которая делает запрос на создание новго девайса если он есть в бд
// то он будет создан в клиенте


// будет кнопка которая делает запрос на прогноз данных
// данные будут возвращены и отображены