#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSplitter>
#include <QDebug>
#include <QPushButton>
#include <QHBoxLayout>
#include <QSpinBox>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QFileInfo>
#include <QTimer>
#include <QDateTime>
#include "./dialog/rename.h"
#include "./dialog/changedevice.h"
#include "./dialog/adduser.h"
#include <QSharedMemory>
#include <QBuffer>
#include <QDataStream>
#include <QTabWidget>
#include <QPalette>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    d_info  = NULL;

    pix_on.load(":/image/green.png");
    pix_off.load(":/image/gray.png");

    Init_TreeWidget();

    CreateItemMenu();

    Init_tableWidget();

#ifdef Enable_Curve
    Init_curve_widget();
#endif

    QSplitter *splitter = new QSplitter(ui->centralWidget);
    splitter->setHandleWidth(0);
    splitter->addWidget(ui->treeWidget);

    tabWidget   = new QTabWidget();
    tabWidget->setTabsClosable(true);
    tabWidget->setStyleSheet("QTabWidget::pane{border: 1px solid green}"
                             "QTabWidget::tab-bar{alignment:left;}"
                             "QTabBar::tab{background:transparent; color:black; min-width:40ex; min-height:10ex;}"
                             "QTabBar::tab:hover{background:rgb(255, 255, 255, 100);}"
                             "QTabBar::tab:selected{border-color: white;background:white;color:green;}"
                             "");
    connect(tabWidget,SIGNAL(tabCloseRequested(int)),this,SLOT(close_tabWidget(int)));

    tabWidget->addTab(ui->minor_widget,tr("Control"));

    splitter->addWidget(tabWidget);

    splitter->setCollapsible(0,false);
    splitter->setCollapsible(1,false);

    ui->horizontalLayout->addWidget(splitter);

    QSplitter *splitter_minor   = new QSplitter(Qt::Vertical,ui->minor_widget);
    splitter_minor->addWidget(ui->tableWidget);
    splitter_minor->addWidget((QWidget *)ui->textBrowser);
    splitter_minor->setHandleWidth(0);
    splitter_minor->setCollapsible(0,false);
    splitter_minor->setCollapsible(1,false);
    ui->verticalLayout_minor->addWidget(splitter_minor);

    ui->treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->textBrowser->setContextMenuPolicy(Qt::NoContextMenu);

    logicAction = new LogicAction(this);
    connect(this,SIGNAL(connected_status(Device_Name&,QString&,int,int,Connected)),logicAction,SLOT(connect_ready(Device_Name&,QString&,int,int,Connected)));
    connect(logicAction,SIGNAL(connect_error(Device_Name&,QString&)),this,SLOT(connected_fail(Device_Name&,QString&)));

    connect(logicAction,SIGNAL(return_one_on_off(Device_Name,int,ON_OFF)),this,SLOT(get_button_status(Device_Name,int,ON_OFF)));
    connect(logicAction,SIGNAL(return_one_actual_eletric(Device_Name,int,int)),this,SLOT(get_actual_eletric(Device_Name,int,int)));
    connect(logicAction,SIGNAL(return_one_Max_eletric(Device_Name,int,int)),this,SLOT(get_Max_eletric(Device_Name,int,int)));

#ifdef Enable_Curve
    connect(logicAction,SIGNAL(return_one_actual_eletric(Device_Name,int,int)),curve_widget,SLOT(get_actual(Device_Name,int,int)));
    connect(logicAction,SIGNAL(return_one_Max_eletric(Device_Name,int,int)),curve_widget,SLOT(get_max(Device_Name,int,int)));
#endif

    connect(this,SIGNAL(search_Max_eletric(Device_Name)),logicAction,SIGNAL(search_Max_eletric(Device_Name)));
    connect(this,SIGNAL(search_on_off(Device_Name)),logicAction,SIGNAL(search_on_off(Device_Name)));
    connect(this,SIGNAL(set_on_off(Device_Name,int,ON_OFF)),logicAction,SIGNAL(set_on_off(Device_Name,int,ON_OFF)));

    GetPrevious_device();

    get_user();

    Get_UserInfo();

    add_statusBar();

    timer   = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerout()));
    timer->start(1000);

    Init_interface();

    Init_control_confirmation();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Init_curve_widget()
{
    QList<int> ele_max;
    for(int i=0;i<8;i++){
        ele_max.append(99);
    }
    curve_widget    = new Curve_Widget(" ",8,ele_max);
    curve_widget->hide();
}

void MainWindow::Init_interface()
{
    alarm_status    = NULL;
    home            = NULL;
    loadManagement  = NULL;
    control         = NULL;
    scheduling      = NULL;
    outlet_configuration    = NULL;
    log_event       = NULL;
    outlet_configure_child = NULL;
}

//在使能全部打开或关闭时，给予提示信息；
void MainWindow::Init_control_confirmation()
{
    control_confirmation    = new Control_Confirmation(this);
    connect(control_confirmation,SIGNAL(send_ok(Device_Name,ON_OFF)),this,SLOT(start_all_on_off(Device_Name,ON_OFF)));
}

void MainWindow::GetPrevious_device()
{
    QFile file("device.ini");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<file.errorString();
    }

    QString str;
    QTextStream out(&file);
    QStringList list;
    while(!out.atEnd()){
        str = out.readLine();
        list    = str.split(";");
        if(list.size() < 4){
            return ;
        }
        d_info  = new Device_Info(list.at(1),list.at(0),list.at(2).toInt(),list.at(3).toInt(),this);

        connect(this,SIGNAL(all_btn_on_off(Device_Name,int,ON_OFF)),d_info,SLOT(set_all_btn(Device_Name,int,ON_OFF)));
        connect(d_info,SIGNAL(set_one_off(Device_Name,int,ON_OFF)),logicAction,SIGNAL(set_on_off(Device_Name,int,ON_OFF)));

        for(int i=0;i<d_info->row();i++){
            d_info->set_Current_status(i,list.at(i*5+4).toInt(),list.at(i*5+5).toInt(),0,list.at(i*5+6).toInt(),list.at(i*5+7).toInt(),list.at(i*5+8));
            d_info->set_connect(disconnected);
        }
        device_info.insert(d_info->name(),d_info);

        action_change_net->setEnabled(true);
        action_del_device->setEnabled(true);
        ui->actionChang_Net->setEnabled(true);
        ui->action_del_device->setEnabled(true);
        ui->actionSet_Electric->setEnabled(true);
        action_rename->setEnabled(true);
        ui->actionRename_Device->setEnabled(true);
        add_Treewidget();
    }
    if(d_info != NULL){
        Change_tableWidget();
    }
    file.close();
}

void MainWindow::Get_UserInfo()
{
    QFile file("userinfo.ini");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<file.errorString();
    }
    QTextStream out(&file);
    QStringList list;
    while(!out.atEnd()){
        QString str;
        str = out.readLine();
        list    = str.split(";");
        userinfo.insert(list.at(0),list.at(1));
        list.clear();
    }
    file.close();
}

//保存设备信息；
void MainWindow::Save_Record_device()
{
    QFile file(tr("device.ini"));
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        qDebug()<<file.errorString();
    }
    QTextStream in(&file);
    foreach(QString str,device_info.keys()){
        QString name    = device_info.value(str)->name();
        QString ip      = device_info.value(str)->ip();
        QString port    = tr("%1").arg(device_info.value(str)->port());
        QString row     = tr("%1").arg(device_info.value(str)->row());
        QString current_status;
        for(int i=0;i<device_info.value(str)->row();i++){
            current_status += tr("%1;").arg(device_info.value(str)->current_status(i).max_current);
            current_status += tr("%1;").arg(device_info.value(str)->current_status(i).min_current);
            current_status += tr("%1;").arg(device_info.value(str)->current_status(i).on_delay);
            current_status += tr("%1;").arg(device_info.value(str)->current_status(i).off_delay);
            current_status += device_info.value(str)->current_status(i).describe+";";
        }
        QString save;
        save    = name+";"+ip+";"+port+";"+row+";"+current_status+"\n";
        in << save;
    }
    file.close();
}

//保存用户信息；
void MainWindow::Save_UserInfo()
{
    QFile file("userinfo.ini");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        qDebug()<<file.errorString();
    }
    QTextStream in(&file);
    foreach(QString str,userinfo.keys()){
        QString name    = str;
        QString psd     = userinfo.value(str);
        QString save;
        save    = name + ";" + psd + '\n';
        if(!name.isEmpty())
        in << save;
    }
    file.close();
}
//初始化树设备；
void MainWindow::Init_TreeWidget()
{
    QStringList str;
    str << tr("Device List") << tr("IP Address");
    ui->treeWidget->setHeaderLabels(str);
    ui->treeWidget->setHeaderHidden(true);
    item   = new QTreeWidgetItem(ui->treeWidget);
    top_item    = item;
    top_item->setText(0,tr("Device List"));
    top_item->setText(1,"IP Address");
}
//添加一个树设备；
void MainWindow::add_Treewidget()
{    
    top_item->addChild(d_info->item());
}

void MainWindow::add_statusBar()
{
    label_bar_url   = new QLabel(this);
    label_bar_url->setOpenExternalLinks(true);
    label_bar_url->setText(tr("<a href=\"http://shanghai0904636.11467.com/\">http://www.fachen.com"));
    ui->statusBar->addWidget(label_bar_url,1);

    label_device_name_bar   = new QLabel(this);
    label_device_name_bar->setText((d_info == NULL) ? " " : d_info->name()+":");
    ui->statusBar->addWidget(label_device_name_bar,1);

    label_ip_bar    = new QLabel(this);
    label_ip_bar->setText(tr("disconnect"));
    ui->statusBar->addWidget(label_ip_bar,1);

    label_time_bar  = new QLabel(this);
    ui->statusBar->addWidget(label_time_bar,1);
}
//初始化表头
void MainWindow::Init_tableWidget(int row, int column)
{
    QStringList str;
    str <<tr("端口号(PORT)")<<tr("状态(ON/OFF)")<<tr("电流最大值")<<tr("电源大小")<<tr("备注");

    ui->tableWidget->setRowCount(row);
    ui->tableWidget->setColumnCount(column);

    ui->tableWidget->setHorizontalHeaderLabels(str);
    ui->tableWidget->verticalHeader()->setVisible(false);

    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableWidget->setColumnWidth(1,150);

    ui->tableWidget->setRowCount(row);
    ui->tableWidget->setColumnCount(column);

    for(int i=0;i<8;i++){
        QTableWidgetItem *item  = new QTableWidgetItem;
        item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        item->setText(tr("%1").arg(i+1));
        item->setFlags(Qt::NoItemFlags);
        ui->tableWidget->setItem(i,0,item);

        QWidget *widget     = new QWidget;
        PushButtonPrivat *btn    = new PushButtonPrivat(i,this);
        QLabel  *label      = new QLabel;
        QHBoxLayout *h_layout   = new QHBoxLayout;
        QFont font;
        font.setPixelSize(15);
        btn->setFont(font);
        btn->setText(tr("on/off"));
        btn->setEnabled(true);
        btn->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
        btn->setMaximumSize(55,40);
        btn->setMinimumSize(55,40);
        connect(btn,SIGNAL(button_status(int)),this,SLOT(button_status(int)));

        label->setPixmap(QPixmap(":/image/gray.png"));
        label->setObjectName(tr("%1").arg(i));
        h_layout->setMargin(0);
        h_layout->addWidget(label);
        h_layout->addWidget(btn);
        widget->setLayout(h_layout);
        ui->tableWidget->setCellWidget(i,1,widget);

        QTableWidgetItem *temp  = new QTableWidgetItem;
        temp->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        temp->setFlags(Qt::NoItemFlags);
        ui->tableWidget->setItem(i,2,temp);

        QTableWidgetItem *temp1  = new QTableWidgetItem;
        temp1->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        temp1->setFlags(Qt::NoItemFlags);
        ui->tableWidget->setItem(i,3,temp1);

        QTableWidgetItem *temp2 = new QTableWidgetItem;
        temp2->setFlags(Qt::NoItemFlags);
        temp2->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidget->setItem(i,4,temp2);
    }
}
/*
//创建一个表格；
void MainWindow::Create_tableWidget(int row, int column)
{
    ui->tableWidget->setRowCount(row);
    ui->tableWidget->setColumnCount(column);

    for(int i=0;i<row;i++){
        QTableWidgetItem *item  = new QTableWidgetItem;
        item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        item->setText(tr("%1").arg(i+1));
        item->setFlags(Qt::NoItemFlags);
        ui->tableWidget->setItem(i,0,item);

        QWidget *widget     = new QWidget;
        PushButtonPrivat *btn    = new PushButtonPrivat(d_info->name(),i,this);
        QLabel  *label      = new QLabel;
        QHBoxLayout *h_layout   = new QHBoxLayout;
        QFont font;
        font.setPixelSize(15);
        btn->setFont(font);
        btn->setText(tr("off"));
        btn->setEnabled(true);
        btn->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
        btn->setMaximumSize(55,40);
        btn->setMinimumSize(55,40);
        connect(btn,SIGNAL(button_status(Device_Name,int,ON_OFF)),logicAction,SIGNAL(set_on_off(Device_Name,int,ON_OFF)));

        label->setPixmap(QPixmap(":/image/gray.png"));
        label->setObjectName(d_info->name() + tr("%1").arg(i));
        h_layout->setMargin(0);
        h_layout->addWidget(label);
        h_layout->addWidget(btn);
        widget->setLayout(h_layout);
        ui->tableWidget->setCellWidget(i,1,widget);

        QTableWidgetItem *temp  = new QTableWidgetItem;
        temp->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        temp->setText(tr("%1 A").arg((d_info->size() == 0) ? 99 : d_info->current_status(i).max_current));
        temp->setFlags(Qt::NoItemFlags);
        ui->tableWidget->setItem(i,2,temp);

        QTableWidgetItem *temp1  = new QTableWidgetItem;
        temp1->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        temp1->setText(tr("%1 A").arg((d_info->size() == 0) ? 0 : d_info->current_status(i).actual_current));
        temp1->setFlags(Qt::NoItemFlags);
        ui->tableWidget->setItem(i,3,temp1);

        QTableWidgetItem *temp2 = new QTableWidgetItem;
        temp2->setFlags(Qt::NoItemFlags);
        temp2->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        temp2->setText(d_info->current_status(i).describe);
        ui->tableWidget->setItem(i,4,temp2);
    }
}
*/

//更新tabwidget信息；
void MainWindow::Change_tableWidget()
{
    if(d_info->name().isEmpty()){
        return ;
    }
    if(d_info->row() < 8)
    {
        ui->tableWidget->setRowHidden(6,true);
        ui->tableWidget->setRowHidden(7,true);
    }
    else {
        ui->tableWidget->setRowHidden(6,false);
        ui->tableWidget->setRowHidden(7,false);
    }

    emit send_row(d_info->row());

    QList<int> ele_max;

    for(int i=0;i<d_info->row();i++){
        if(d_info->current_status(i).power_port == ON){
            ui->tableWidget->cellWidget(i,1)->findChild<QLabel*>(tr("%1").arg(i))->setPixmap(pix_on);
        }
        else{
            ui->tableWidget->cellWidget(i,1)->findChild<QLabel*>(tr("%1").arg(i))->setPixmap(pix_off);
        }
        ui->tableWidget->model()->setData(ui->tableWidget->model()->index(i,2),d_info->current_status(i).max_current);
        ui->tableWidget->model()->setData(ui->tableWidget->model()->index(i,3),d_info->current_status(i).actual_current);
        ui->tableWidget->model()->setData(ui->tableWidget->model()->index(i,4),d_info->current_status(i).describe);
        ele_max.append(d_info->current_status(i).max_current);

        emit send_Describe(i,d_info->current_status(i).describe);
        emit send_Max_eletric(i,d_info->current_status(i).max_current);
        emit send_Min_eletric(i,d_info->current_status(i).min_current);
        emit send_real_eletric(i,d_info->current_status(i).actual_current);
        emit send_on_off_status(i,d_info->current_status(i).power_port);
    }
    emit change_name(d_info->name(),d_info->row(),ele_max);
}

//更新表格大小，并向tabwidget发送信息；
void MainWindow::Change_tableWidget(int row)
{
    row = row;
    if(d_info->name().isEmpty()){
        return ;
    }
    for(int i=d_info->row();i<8;i++){
        ui->tableWidget->setRowHidden(i,true);
    }
    emit send_row(row);
}

//更新电流最大值，并向tabwidget发送信息；
void MainWindow::Change_tableWidget(int device_port, int max)
{
    if(d_info->name().isEmpty()){
        return ;
    }
    ui->tableWidget->model()->setData(ui->tableWidget->model()->index(device_port,2),max);
    emit send_Max_eletric(device_port,max);
}

//更新电流最小值，并向tabwidget发送消息；
void MainWindow::Change_tableWidget(int device_port, int min, QString dump)
{
    if(d_info->name().isEmpty()){
        return ;
    }
    dump    = dump;
    emit send_Min_eletric(device_port,min);
}

//更新实际电流值，并向tabwidget发送信息；
void MainWindow::Change_tableWidget(int device_port, int actual, int dump)
{
    dump    = dump;
    if(d_info->name().isEmpty()){
        return ;
    }
    ui->tableWidget->model()->setData(ui->tableWidget->model()->index(device_port,3),actual);
    emit send_real_eletric(device_port,actual);
}

//更新端口描述信息，并向tabwidget发送信息；
void MainWindow::Change_tableWidget(int device_port, QString describe)
{
    if(d_info->name().isEmpty()){
        return ;
    }
    ui->tableWidget->model()->setData(ui->tableWidget->model()->index(device_port,4),describe);
    emit send_Describe(device_port,describe);
}

//创建右键菜单；
void MainWindow::CreateItemMenu()
{
    device_child_menu   = new QMenu(this);
    action_add_device   = device_child_menu->addAction(tr("Add Device"),this,SLOT(on_action_add_device_triggered()));
    action_del_device   = device_child_menu->addAction(tr("Delete Device"),this,SLOT(on_action_del_device_triggered()));
    action_rename   = device_child_menu->addAction(tr("Rename"),this,SLOT(on_actionRename_Device_triggered()));

    device_child_menu->addSeparator();

    action_change_net  = device_child_menu->addAction(tr("Change Network"),this,SLOT(on_actionChang_Net_triggered()));
    action_change_net->setEnabled(false);
    ui->actionChang_Net->setEnabled(false);
    action_connect  = device_child_menu->addAction(tr("Connect"),this,SLOT(on_action_connect_triggered()));

    action_disconnect   = device_child_menu->addAction(tr("Disconnect"),this,SLOT(on_action_disconnect_triggered()));
    action_disconnect->setEnabled(false);
    ui->action_disconnect->setEnabled(false);
    device_child_menu->addSeparator();

    action_del_device->setEnabled(false);
    ui->action_del_device->setEnabled(false);

    action_rename->setEnabled(false);
    ui->actionRename_Device->setEnabled(false);
    device_child_menu->addSeparator();
    action_fold = device_child_menu->addAction(tr("Fold all"),this,SLOT(onaction_fold_triggered()));

    ui->actionSet_Electric->setEnabled(false);
}

//点击右键时，使能或禁止某些功能；
void MainWindow::change_contex_menu_status(Device_Info *d_info)
{
    label_device_name_bar->setText(d_info->name()+":");
    if(d_info->connect() == connected){
        ui->action_connect->setEnabled(false);
        ui->action_disconnect->setEnabled(true);
        action_connect->setEnabled(false);
        action_disconnect->setEnabled(true);
        label_ip_bar->setText(tr("connected"));
    }
    else {
        ui->action_connect->setEnabled(true);
        ui->action_disconnect->setEnabled(false);
        action_connect->setEnabled(true);
        action_disconnect->setEnabled(false);
        label_ip_bar->setText(tr("disconnected"));
    }
}

//退出应用程序时，保存相关数据；
void MainWindow::closeEvent(QCloseEvent *event)
{
    int r = QMessageBox::question(this,tr("关闭应用程序"),tr("确定要退出此应用程序吗？"),QMessageBox::Ok | QMessageBox::Default,QMessageBox::No | QMessageBox::Escape);

    if (r==QMessageBox::Ok){
        Save_Record_device();
        Save_UserInfo();
        event->accept();
    }
    else{
        event->ignore();
    }
}

//关闭某个界面；
void MainWindow::close_tabWidget(int index)
{
    tabWidget->removeTab(index);
}

//打开OverView界面；
void MainWindow::on_action_OverView_triggered()
{
    if(home == NULL){
        home    = new Home;
    }
    tabWidget->addTab(home,"OverView");
    tabWidget->setCurrentWidget(home);
}

//打开Alarm界面；
void MainWindow::on_action_Alarm_Status_triggered()
{
    if(alarm_status == NULL){
        alarm_status    = new Alarm_Status;
    }
    tabWidget->addTab(alarm_status,"Alarm Status");
    tabWidget->setCurrentWidget(alarm_status);
}

//打开Load_Management界面；
void MainWindow::on_action_Load_Management_triggered()
{
    if(loadManagement == NULL){
        loadManagement    = new LoadManagement;
    }
    tabWidget->addTab(loadManagement,"Load Management");
    tabWidget->setCurrentWidget(loadManagement);
}

//添加Control界面；
void MainWindow::on_action_control_triggered()
{
    if(control == NULL){
        control    = new Control;
        connect(control,SIGNAL(set_btn_status(int)),this,SLOT(button_status(int)));
        connect(control,SIGNAL(search_btn_status(int)),this,SLOT(search_btn_status(int)));
        connect(control,SIGNAL(set_Max(int,int)),this,SLOT(set_Max_eletric(int,int)));
        connect(control,SIGNAL(set_Min(int,int)),this,SLOT(set_Min_eletric(int,int)));
        connect(control,SIGNAL(set_Describe(int,QString)),this,SLOT(set_Describe(int,QString)));
        connect(control,SIGNAL(modification(int)),this,SLOT(open_configure_child(int)));
        connect(control,SIGNAL(set_all_on_off(int)),this,SLOT(set_all_on_off(int)));
        connect(this,SIGNAL(send_on_off_status(int,ON_OFF)),control,SLOT(get_btn_status(int,ON_OFF)));
        connect(this,SIGNAL(send_real_eletric(int,int)),control,SLOT(get_real_eletric(int,int)));
        connect(this,SIGNAL(send_Max_eletric(int,int)),control,SLOT(get_Max(int,int)));
        connect(this,SIGNAL(send_Min_eletric(int,int)),control,SLOT(get_Min(int,int)));
        connect(this,SIGNAL(send_Describe(int,QString)),control,SLOT(get_Describe(int,QString)));
        connect(this,SIGNAL(send_row(int)),control,SLOT(get_row(int)));

        Change_tableWidget();
    }
    tabWidget->addTab(control,"Control");
    tabWidget->setCurrentWidget(control);
}

//打开设置延时界面；
void MainWindow::open_configure_child(int device_port)
{
    if(outlet_configure_child == NULL){
        outlet_configure_child  = new Outlet_configure_child;
        connect(outlet_configure_child,SIGNAL(send_Interval(Device_Name,int,int,int)),this,SLOT(get_on_off_delay(Device_Name,int,int,int)));
        connect(outlet_configure_child,SIGNAL(send_Interval()),this,SLOT(get_on_off_delay()));
    }
    if(d_info->current_status(device_port).describe.isEmpty()){
        outlet_configure_child->setPortName(tr("port%1:").arg(device_port));
    }
    else {
        outlet_configure_child->setPortName(d_info->current_status(device_port).describe);
    }
    outlet_configure_child->setName(d_info->name());
    outlet_configure_child->setInterval(d_info->current_status(device_port).on_delay,d_info->current_status(device_port).off_delay);
    outlet_configure_child->setdevice_port(device_port);

    tabWidget->addTab(outlet_configure_child,"configure outlet");
    tabWidget->setCurrentWidget(outlet_configure_child);
}

//更新延时时间；
void MainWindow::get_on_off_delay(Device_Name name, int device_port, int on_delay, int off_delay)
{
    device_info.value(name)->change_Current_status(name,device_port,on_delay,off_delay);
    tabWidget->removeTab(tabWidget->indexOf(outlet_configure_child));
    if(d_info->name() == name){
        outlet_configuration->set_on_delay(device_port,on_delay);
        outlet_configuration->set_off_delay(device_port,off_delay);
    }
}

//获取延时时间后，关闭延时界面；
void MainWindow::get_on_off_delay()
{
    tabWidget->removeTab(tabWidget->indexOf(outlet_configure_child));
}

//判断全部是打开或者关闭。
void MainWindow::set_all_on_off(int index)
{
    switch(index){
    case 0:
        control_confirmation->set_nothing(d_info->name());control_confirmation->exec();break;
    case 1:
        control_confirmation->set_hint(d_info->name(),d_info->name(),d_info->row());
        for(int i=0;i<d_info->row();i++){
            control_confirmation->set_on_delay(i+1,0);
        }
        control_confirmation->exec();break;
    case 2:
        control_confirmation->set_hint(d_info->name(),d_info->name(),d_info->row());
        for(int i=0;i<d_info->row();i++){
            control_confirmation->set_on_delay(i+1,d_info->current_status(i).on_delay);
        }
        control_confirmation->exec();break;
    case 3:
        control_confirmation->set_hint(d_info->name(),d_info->row());
        for(int i=0;i<d_info->row();i++){
            control_confirmation->set_off_delay(i+1,0);
        }
        control_confirmation->exec();break;
    case 4:
        control_confirmation->set_hint(d_info->name(),d_info->row());
        for(int i=0;i<d_info->row();i++){
            control_confirmation->set_off_delay(i+1,d_info->current_status(i).off_delay);
        }
        control_confirmation->exec();break;
    }
}

//开始向底层发送数据；
void MainWindow::start_all_on_off(Device_Name name, ON_OFF flag)
{

}

void MainWindow::on_actionConfiguration_triggered()
{
    if(outlet_configuration == NULL){
        outlet_configuration    = new Outlet_Configuration;
    }
    tabWidget->addTab(outlet_configuration,"Outlet Configuration");
    tabWidget->setCurrentWidget(outlet_configuration);
}

void MainWindow::on_actionScheduling_triggered()
{
    if(scheduling == NULL){
        scheduling    = new Scheduling;
    }
    tabWidget->addTab(scheduling,"Scheduling");
    tabWidget->setCurrentWidget(scheduling);
}

void MainWindow::on_actionLog_event_triggered()
{
    if(log_event == NULL){
        log_event   = new Log_Event;
    }
    tabWidget->addTab(log_event,"Log Event");
    tabWidget->setCurrentWidget(log_event);
}

//设置电流最大值；
void MainWindow::set_Max_eletric(int device_port, int val)
{
    emit set_Max_eletric(d_info->name(),device_port,val);
}

//设置电流最小值；
void MainWindow::set_Min_eletric(int device_port, int val)
{
    emit set_Min_eletric(d_info->name(),device_port,val);
}

//设置端口描述信息；
void MainWindow::set_Describe(int device_port, QString str)
{
    d_info->change_Current_status(device_port,str);
}

void MainWindow::on_action_Device_triggered()
{
    qDebug()<<tr("on action device triggered!!!");
}

void MainWindow::on_actionChang_Net_triggered()
{
    if(d_info->connect() == connected){
        QMessageBox::warning(this,tr("%1警告").arg(d_info->name()),tr("请先断开网络连接，在更改%1设备网络").arg(d_info->name()),tr("确定"));
        return ;
    }

    Changedevice *changedevice   = new Changedevice(device_info,this);
    connect(changedevice,SIGNAL(change_data(QString&,QString&,QString&,int&)),this,SLOT(change_device(QString&,QString&,QString&,int&)));

    changedevice->exec();

    qDebug()<<tr("on action change net triggered!!!");
}

//添加用户；
void MainWindow::on_actionAdd_User_triggered()
{
    AddUser *adduser    = new AddUser(this);
    connect(adduser,SIGNAL(userInfo(QString&,QString&)),this,SLOT(Add_user(QString&,QString&)));

    adduser->exec();
}

void MainWindow::on_actionDelete_User_triggered()
{
    qDebug()<<tr("on action delete user triggered!!!");
}

void MainWindow::on_actionChang_Passwd_triggered()
{
    qDebug()<<tr("on action change passwd triggered!!!");
}

void MainWindow::on_actionRename_Device_triggered()
{
    Rename *rename  = new Rename(device_info,this);
    connect(rename,SIGNAL(rename(QString&,QString&,QStringList &)),this,SLOT(rename_device(QString&,QString&,QStringList &)));
    rename->exec();

    delete rename;
}

void MainWindow::on_actionCheck_Power_triggered()
{
    if(d_info->connect() == disconnected){
        QMessageBox::warning(this,tr("警告"),tr("%1设备没有连接网络，请先连接网络！").arg(d_info->name()),tr("确定"));
        return ;
    }
    emit search_Max_eletric(d_info->name());
}

void MainWindow::on_action_btn_triggered()
{
    if(d_info->connect() == disconnected){
        QMessageBox::warning(this,tr("警告"),tr("%1设备没有连接网络，请先连接网络！").arg(d_info->name()),tr("确定"));
        return ;
    }
    emit search_on_off(d_info->name());
}

void MainWindow::on_action_all_btn_triggered()
{
    All_btn *all_btn    = new All_btn(device_info.keys(),this);
    connect(all_btn,SIGNAL(all_btn_send(Device_Name,int,ON_OFF)),this,SIGNAL(all_btn_on_off(Device_Name,int,ON_OFF)));

    all_btn->exec();

    delete all_btn;
}

void MainWindow::on_actionAbout_triggered()
{
    qDebug()<<tr("on action about triggered!!!");
}

void MainWindow::on_actionHelp_F1_triggered()
{
    qDebug()<<tr("on action help F1 triggered!!!");
}

void MainWindow::on_action_connect_triggered()
{
    d_info->set_connect(connected);
    label_ip_bar->setText(tr("connected"));
    QString name    = d_info->name();
    QString ip  = d_info->ip();
    emit connected_status(name,ip,d_info->port(),d_info->row(),connected);
}

void MainWindow::on_action_disconnect_triggered()
{
    d_info->set_connect(disconnected);
    label_ip_bar->setText(tr("disconnect"));
    QString name    = d_info->name();
    QString ip  = d_info->ip();
    emit connected_status(name,ip,d_info->port(),d_info->row(),disconnected);
}

void MainWindow::onaction_fold_triggered()
{
    ui->treeWidget->collapseAll();
}
//实现treewidget的右键菜单；
void MainWindow::on_treeWidget_customContextMenuRequested(const QPoint &pos)
{
    item   = ui->treeWidget->itemAt(pos);
    if(d_info == NULL){
        device_child_menu->exec(QCursor::pos());
        return ;
    }
    if(item == NULL){
        item    = d_info->item();
    }
    if(item->parent() != 0){
        d_info  = device_info.value(item->text(0));
        change_contex_menu_status(d_info);
    }
    device_child_menu->exec(QCursor::pos());
    on_treeWidget_itemClicked(item,0);
}
//添加设备；
void MainWindow::on_action_add_device_triggered()
{
    d_info      = new Device_Info("","",0,0,this);

//    connect(this,SIGNAL(all_btn_on_off(Device_Name,int,ON_OFF)),d_info,SLOT(set_all_btn(Device_Name,int,ON_OFF)));
//    connect(d_info,SIGNAL(set_one_off(Device_Name,int,ON_OFF)),logicAction,SIGNAL(set_on_off(Device_Name,int,ON_OFF)));

    add_device  = new Add_device(this);

    connect(add_device,SIGNAL(data(Device_data&)),this,SLOT(display_tableWidget(Device_data&)));
    if(!add_device->exec()){
        delete add_device;
        return ;
    }

    add_Treewidget();
    device_info.insert(d_info->name(),d_info);

    action_change_net->setEnabled(true);
    action_del_device->setEnabled(true);
    ui->actionChang_Net->setEnabled(true);
    ui->action_del_device->setEnabled(true);
    ui->actionSet_Electric->setEnabled(true);
    action_rename->setEnabled(true);
    ui->actionRename_Device->setEnabled(true);

    delete add_device;
}

void MainWindow::on_action_del_device_triggered()
{
    if(item->parent() == 0){
        return ;
    }

    item->parent()->removeChild(item);

    device_info.remove(d_info->name());
    delete d_info;

    item    = ui->treeWidget->currentItem();
    d_info  = device_info.value(item->text(0));
    if(d_info == NULL){
        action_change_net->setEnabled(false);
        action_del_device->setEnabled(false);
        ui->actionChang_Net->setEnabled(false);
        ui->action_del_device->setEnabled(false);
        ui->actionSet_Electric->setEnabled(false);
        action_rename->setEnabled(false);
        ui->actionRename_Device->setEnabled(false);
        return ;
    }
    Change_tableWidget();
}
//显示表格；
void MainWindow::display_tableWidget(Device_data &data)
{
    if((device_info.find(data.name) != device_info.end()) && (device_info.find(data.name).key() == data.name)){
        QMessageBox::warning(add_device,tr("输入错误"),tr("设备名%1已存在，请重新输\n入新的设备名!").arg(data.name));
        add_device->reject();
        return ;
    }
    d_info->set_ip(data.IP);
    switch(data.index){
    case EIGHTIN_EIGHTOUT:
        d_info->set_row(8);
        break;
    case SIXIN_SIXOUT:
        d_info->set_row(8);
        break;
    case ONEIN_SIXOUT:
        d_info->set_row(6);
        break;
    }
    d_info->set_name(data.name);
    d_info->set_port(data.Port.toInt());

    add_device->accept();
}
//接受电流的最大值；
void MainWindow::receive_max_eletric(QStringList &str)
{
    for(int i=0;i<str.size();i++){
        d_info->change_Current_status(i,str.at(i).toInt());
        Change_tableWidget(i,str.at(i).toInt());
    }
}

void MainWindow::rename_device(QString &newName, QString &oldName, QStringList &str)
{
    d_info    = device_info.value(oldName);
    d_info->set_name(newName);
    for(int i=0;i<str.size();i++){
        d_info->change_Current_status(i,str.at(i));
    }
    device_info.remove(oldName);
    device_info.insert(d_info->name(),d_info);

    on_treeWidget_itemClicked(d_info->item(),0);
}


void MainWindow::change_device(QString &name, QString &IP, QString &port, int &index)
{
    d_info  = device_info.value(name);
    d_info->set_ip(IP);
    d_info->set_port(port.toInt());
    d_info->set_row(index);
    device_info.insert(name,d_info);

    Change_tableWidget(index);
}

//添加用户；
void MainWindow::Add_user(QString &name, QString &password)
{
    userinfo.insert(name,password);
}

//获取用户信息，采用共享内存；
void MainWindow::get_user()
{
    QSharedMemory *share_userinfo   = new QSharedMemory("SHAREFILE",this);
    if(!share_userinfo->attach()){
        qDebug()<<tr("No Share Data");
        return ;
    }
    QBuffer buffer;
    QDataStream out(&buffer);

    share_userinfo->lock();
    buffer.setData((char*)share_userinfo->constData(),share_userinfo->size());
    buffer.open(QBuffer::ReadOnly);
    while(!out.atEnd()){
        QString name;
        QString psd;
        out >> name >> psd;
        d_userinfo.Name = name;
        d_userinfo.psd  = psd;
    }
    share_userinfo->unlock();
    share_userinfo->detach();
}

//更新右下角时间；
void MainWindow::timerout()
{
    QDateTime datetime;
    QString str = datetime.currentDateTime().time().toString("hh:mm:ss");
    label_time_bar->setText(str);
}

//向底层发送设置开关指令；
void MainWindow::button_status(int device_port)
{
    if(d_info->current_status(device_port).power_port == ON){
        emit set_on_off(d_info->name(),device_port,OFF);
    }
    else{
        emit set_on_off(d_info->name(),device_port,ON);
    }
}

//和设备连接失败；
void MainWindow::connected_fail(Device_Name &name, QString &error)
{
    device_info.value(name)->set_connect(disconnected);
    if(name == d_info->name()){
        label_ip_bar->setText(tr("disconnected"));
    }

    QMessageBox::warning(this,tr("%1连接失败").arg(name),tr("失败原因：%1").arg(error),tr("确定"));
}

//从底层接收开关状态；
void MainWindow::get_button_status(Device_Name name, int device_port, ON_OFF on_off)
{
    if(device_port >= device_info.value(name)->row()){
        return ;
    }
    device_info.value(name)->change_Current_status(device_port,on_off);    
    if(name != d_info->name()){
        return ;
    }

    emit send_on_off_status(device_port,on_off);

    if(on_off == ON){
        ui->tableWidget->cellWidget(device_port,1)->findChild<QLabel *>(tr("%1").arg(device_port))->setPixmap(pix_on);
    }
    else {
         ui->tableWidget->cellWidget(device_port,1)->findChild<QLabel *>(tr("%1").arg(device_port))->setPixmap(pix_off);
    }
}

//从底层接收电流最大值；
void MainWindow::get_Max_eletric(Device_Name name, int device_port, int Max)
{
    device_info.value(name)->change_Current_status(device_port,Max);
    if(name != d_info->name()){
        return ;
    }
    Change_tableWidget(device_port,Max);
}

//从底层接收电流最小值；
void MainWindow::get_Min_eletric(Device_Name name, int device_port, int Min)
{
    device_info.value(name)->change_Current_status(device_port,Min);
    if(name != d_info->name()){
        return ;
    }
    QString str;
    Change_tableWidget(device_port,Min,str);
}

//从底层接收电流实际值；
void MainWindow::get_actual_eletric(Device_Name name, int device_port, int actual)
{
    device_info.value(name)->change_Current_status(device_port,actual,actual);
    if(name != d_info->name()){
        return ;
    }
    Change_tableWidget(device_port,actual,actual);
}

//从底层发送查询指令，查询当前设备状态；
void MainWindow::search_btn_status(int device_port)
{
    emit search_on_off(d_info->name(),device_port);
}

//实现单机树设备时，切换表格数据；
void MainWindow::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    column  = column;
    if(item->parent() != 0){
        d_info  = device_info.value(item->text(0));

        Change_tableWidget();

        label_device_name_bar->setText(d_info->name()+":");
        if(d_info->connect() == connected){
            label_ip_bar->setText(tr("connected"));
        }
        else {
            label_ip_bar->setText(tr("disconnected"));
        }
    }
}
