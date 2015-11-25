#include "changedevice.h"
#include <QSpacerItem>

Changedevice::Changedevice(QMap<QString, Device_Info *> device_info, QWidget *parent)
    : QDialog(parent)
    , device_info(device_info)
{
    foreach(QString str,device_info.keys()){
        name << str;
        IP_list  << device_info.value(str)->ip();
        port_list <<tr("%1").arg(device_info.value(str)->port());
    }

    row_index   = 0;
    name_index  = 0;

    QFont font;
    font.setPixelSize(20);
    this->setFont(font);

    QLabel *label_device        = new QLabel(this);
    label_device->setText(tr("当前设备："));

    QComboBox *combobox_device  = new QComboBox(this);
    combobox_device->addItems(name);
    connect(combobox_device,SIGNAL(currentIndexChanged(int)),this,SLOT(change_combobox_name(int)));

    QLabel *label_IP            = new QLabel(this);
    label_IP->setText(tr("IP:"));

    ip  = new QLineEdit(this);
    ip->setText(IP_list.at(0));

    QLabel *label_port          = new QLabel(this);
    label_port->setText(tr("Port:"));

    port    = new QLineEdit(port_list.at(0),this);

    QLabel *label_num           = new QLabel(tr("设备类型:"),this);

    QComboBox *combobox_row  = new QComboBox(this);
    combobox_row->addItem(tr("1进8出"));
    combobox_row->addItem(tr("6进6出"));
    combobox_row->addItem(tr("1进6出"));
    connect(combobox_row,SIGNAL(currentIndexChanged(int)),this,SLOT(change_combobox_row(int)));

    QVBoxLayout *v_layout1  = new QVBoxLayout;
    v_layout1->addWidget(label_device);
    v_layout1->addSpacing(5);
    v_layout1->addWidget(label_IP);
    v_layout1->addSpacing(5);
    v_layout1->addWidget(label_port);
    v_layout1->addSpacing(5);
    v_layout1->addWidget(label_num);

    QVBoxLayout *v_layout2  = new QVBoxLayout;
    v_layout2->addWidget(combobox_device);
    v_layout2->addSpacing(5);
    QSpacerItem *v_spacter  = new QSpacerItem(40,20,QSizePolicy::Expanding);
    v_layout2->addSpacerItem(v_spacter);
    v_layout2->addWidget(ip);
    v_layout2->addSpacing(5);
    QSpacerItem *v_spacter1  = new QSpacerItem(40,20,QSizePolicy::Expanding);
    v_layout2->addSpacerItem(v_spacter1);
    v_layout2->addWidget(port);
    v_layout2->addSpacing(5);
    QSpacerItem *v_spacter2  = new QSpacerItem(40,20,QSizePolicy::Expanding);
    v_layout2->addSpacerItem(v_spacter2);
    v_layout2->addWidget(combobox_row);

    QHBoxLayout *h_layout   = new QHBoxLayout;
    h_layout->addLayout(v_layout1);
    h_layout->addSpacing(10);
    h_layout->addLayout(v_layout2);

    QPushButton *Ok_btn      = new QPushButton(tr("确定"));
    Ok_btn->resize(60,40);
    Ok_btn->setMinimumSize(50,35);
    Ok_btn->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    Ok_btn->setFocus();
    connect(Ok_btn,SIGNAL(clicked()),this,SLOT(change_Ok_btn()));
    QPushButton *Cancle_btn  = new QPushButton(tr("取消"));
    Cancle_btn->resize(50,35);
    Cancle_btn->setMinimumSize(50,35);
    Cancle_btn->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    connect(Cancle_btn,SIGNAL(clicked()),this,SLOT(change_Cancle_btn()));

    QHBoxLayout *h_layout1  = new QHBoxLayout;
    h_layout1->addWidget(Ok_btn);
    h_layout1->addSpacing(20);
    h_layout1->addWidget(Cancle_btn);

    QVBoxLayout *v_layout   = new QVBoxLayout;
    v_layout->addLayout(h_layout);
    v_layout->addSpacing(10);
    v_layout->addLayout(h_layout1);

    setLayout(v_layout);

    setMaximumSize(340,320);
    setMinimumSize(340,320);
}

void Changedevice::change_combobox_name(int index)
{
    name_index  = index;
    ip->setText(IP_list.at(name_index));
    port->setText(port_list.at(name_index));
}

void Changedevice::change_combobox_row(int index)
{
    row_index   = index;
}

void Changedevice::change_Ok_btn()
{
    QString name    = this->name.at(name_index);
    QString IP      = this->ip->text();
    QString port    = this->port->text();
    int index;
    switch(row_index){
    case 0:
        index   = 8;
        break;
    case 1:
        index   = 8;
        break;
    case 2:
        index   = 6;
        break;
    }
    if(!check_IP(IP)){
        reject();
        return ;
    }
    emit change_data(name,IP,port,index);

    accept();
}

void Changedevice::change_Cancle_btn()
{
    this->reject();
}

bool Changedevice::check_IP(const QString ip)
{
    QRegExp rx("((2[0-4]\\d|25[0-5]|[01]?\\d\\d?)\\.){3}(2[0-4]\\d|25[0-5]|[01]?\\d\\d?)");

    if(!rx.exactMatch(ip)){
        QMessageBox::warning(this,tr("错误"),tr("输入的IP地址有误，请重新输入！"));
        return false;
    }
    return true;
}
