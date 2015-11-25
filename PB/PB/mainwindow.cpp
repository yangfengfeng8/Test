#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "./home/home.h"
#include "./home/alarm_status.h"
#include "./home/outlet_status.h"
#include <QHBoxLayout>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QHBoxLayout *h_layout   = new QHBoxLayout;

    Home *home  = new Home;
    Alarm_Status *alarm_status   = new Alarm_Status;
    Outlet_Status *outlet_status    = new Outlet_Status;
    h_layout->addWidget(outlet_status);
    h_layout->setMargin(0);
//    ui->centralWidget->setLayout(h_layout);
    connect(ui->tabWidget,SIGNAL(tabCloseRequested(int)),this,SLOT(remove_tabwidget(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

MainWindow::remove_tabwidget(int index)
{
    qDebug()<<index;
    ui->tabWidget->removeTab(index);
}
