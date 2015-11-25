#include "add_device.h"
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QComboBox>
#include <QPushButton>
#include <QMessageBox>
#include <QDebug>

Add_device::Add_device(QWidget *parent)
    : QDialog(parent)
{
    setWindowFlags(Qt::WindowCloseButtonHint | Qt::Dialog);
    setWindowTitle(tr("添加设备"));
    setMaximumSize(360,320);
    setMinimumSize(360,320);

    device_name     = new QLabel(tr("设备名称："),this);
    device_name->resize(40,20);
    IP_Address      = new QLabel(tr("IP 地址："),this);
    IP_Address->resize(40,20);
    IP_Port         = new QLabel(tr("IP 端口："),this);
    IP_Port->resize(40,20);
    Number          = new QLabel(tr("设备类型："),this);
    Number->resize(40,20);
    QVBoxLayout *v_layout_1 = new QVBoxLayout;
    v_layout_1->addWidget(device_name);
    v_layout_1->addSpacing(10);
    v_layout_1->addWidget(IP_Address);
    v_layout_1->addSpacing(10);
    v_layout_1->addWidget(IP_Port);
    v_layout_1->addSpacing(10);
    v_layout_1->addWidget(Number);
    Input_name   = new QLineEdit(this);
    Input_name->resize(60,20);
    Input_name->setMinimumSize(200,30);
    Input_IP     = new QLineEdit(this);
    Input_IP->setMinimumSize(200,30);

    Input_Port   = new QLineEdit(this);
    Input_Port->setMinimumSize(80,30);
    Input_Port->setValidator(new QIntValidator);
    Input_Num    = new QComboBox(this);
    Input_Num->setMinimumSize(80,30);
    Input_Num->addItem(tr("1 进 8 出"));
    Input_Num->addItem(tr("6 进 6 出"));
    Input_Num->addItem(tr("1 进 6 出"));
    QVBoxLayout *v_layout_2 = new QVBoxLayout;
    v_layout_2->addWidget(Input_name);
    v_layout_2->addSpacing(10);
    v_layout_2->addWidget(Input_IP);
    v_layout_2->addSpacing(10);
    v_layout_2->addWidget(Input_Port);
    v_layout_2->addSpacing(10);
    v_layout_2->addWidget(Input_Num);

    QHBoxLayout *h_layout   = new QHBoxLayout;
    h_layout->addLayout(v_layout_1);
    h_layout->addSpacing(40);
    h_layout->addLayout(v_layout_2);
    QVBoxLayout *v_layout   = new QVBoxLayout;

    QPushButton *Ok_btn      = new QPushButton(tr("确定"));
    Ok_btn->resize(60,40);
    Ok_btn->setMinimumSize(50,35);
    Ok_btn->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    Ok_btn->setFocus();
    connect(Ok_btn,SIGNAL(clicked()),this,SLOT(add_device_OK_slot()));
    QPushButton *Cancle_btn  = new QPushButton(tr("取消"));
    Cancle_btn->resize(50,35);
    Cancle_btn->setMinimumSize(50,35);
    Cancle_btn->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    connect(Cancle_btn,SIGNAL(clicked()),this,SLOT(add_device_Cancle_slot()));

    QHBoxLayout *h_layout_1   = new QHBoxLayout;
    h_layout_1->addWidget(Ok_btn);
    h_layout_1->addSpacing(20);
    h_layout_1->addWidget(Cancle_btn);
    v_layout->addLayout(h_layout);
    v_layout->addSpacing(20);
    v_layout->addLayout(h_layout_1);
    this->setLayout(v_layout);
}



bool Add_device::check_IP(const QString ip)
{
    QRegExp rx("((2[0-4]\\d|25[0-5]|[01]?\\d\\d?)\\.){3}(2[0-4]\\d|25[0-5]|[01]?\\d\\d?)");

    if(!rx.exactMatch(ip)){
        QMessageBox::warning(this,tr("错误"),tr("输入的IP地址有误，请重新输入！"));
        return false;
    }
    return true;
}

void Add_device::add_device_OK_slot()
{
    if(Input_name->text().isEmpty() || Input_IP->text().isEmpty() || Input_Port->text().isEmpty()){
        QMessageBox::warning(this,tr("输入错误"),tr("输入的设备名称、IP地址、端口号为空，\n请检查后按确认键！！！"));
        this->reject();
        return ;
    }
    if(!check_IP(Input_IP->text())){
        return ;
    }
    Device_data device_data;
    device_data.name    = Input_name->text();
    device_data.IP      = Input_IP->text();
    device_data.Port    = Input_Port->text();
    switch(Input_Num->currentIndex()){
    case 0:device_data.index    = EIGHTIN_EIGHTOUT;
        break;
    case 1:device_data.index    = SIXIN_SIXOUT;
        break;
    case 2:device_data.index    = ONEIN_SIXOUT;
        break;
    }

    emit data(device_data);
}

void Add_device::add_device_Cancle_slot()
{
    this->reject();
}
