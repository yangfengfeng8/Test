#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "./PA/padevicelist.h"
#include "./PA/PAManagerTab/pamanagertab.h"

#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initMainWindow();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initMainWindow()
{
    initLayout();

    addStatusBar();

    initPA();
}

void MainWindow::initLayout()
{
    splitter    = new QSplitter(Qt::Horizontal,this);
    splitter->setHandleWidth(0);

    splitter->addWidget(ui->toolBox);
    splitter->addWidget(ui->widget);

    splitter->setStretchFactor(1,1);
    splitter->setCollapsible(0,false);
    splitter->setCollapsible(1,false);

    ui->horizontalLayout_2->addWidget(splitter);
}

void MainWindow::addStatusBar()
{
    label_bar_url   = new QLabel(this);
    label_bar_url->setText("<font color= blue>Welcome to HBTE!</font>");
    ui->statusBar->addWidget(label_bar_url,1);

    label_device_name_bar   = new QLabel(this);
    ui->statusBar->addWidget(label_device_name_bar,1);

    label_ip_bar    = new QLabel(this);
    ui->statusBar->addWidget(label_ip_bar,1);

    label_status    = new QLabel(this);
    ui->statusBar->addWidget(label_status,1);

    label_user      = new QLabel(this);
    label_user->setText(QString("User: %1").arg(QString("HBTE")));
    ui->statusBar->addWidget(label_user,1);
}

void MainWindow::initPA()
{
    initPADeviceList();

    initPAManagerTab();
}

void MainWindow::initPADeviceList()
{
    pADeviceList    = new PADeviceList(this);
    connect(pADeviceList,SIGNAL(errors(QString)),this,SLOT(errors(QString)));
    connect(this,SIGNAL(closed()),pADeviceList,SLOT(closed()));
    ui->verticalLayoutPA->addWidget(pADeviceList);
}

void MainWindow::initPAManagerTab()
{
    pAManagerTab    = new PAManagerTab(this);\
    ui->verticalLayout->addWidget(pAManagerTab);
}

void MainWindow::closeEvent(QCloseEvent *)
{
    emit closed();
}

void MainWindow::resizeEvent(QResizeEvent *)
{
}

void MainWindow::errors(const QString &Str)
{
    QMessageBox::warning(this,QString("Note:"),Str);
    return ;
}
