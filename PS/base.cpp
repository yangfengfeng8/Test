#include "base.h"

Timer_New::Timer_New(int device_port,QObject *parent) : QObject(parent)
{
    connect(&timer,SIGNAL(timeout()),this,SLOT(timeout()));
    this->device_port   = device_port;
}

void Timer_New::set_info(int interval)
{
    this->Interval  = interval;
    timer.start(Interval*1000);
}

void Timer_New::timeout()
{
    emit time_out(device_port);
    timer.stop();
}


PushButtonPrivat::PushButtonPrivat(int device_port, QWidget *parent)
    : QPushButton(parent)
    ,device_port(device_port)
{
    connect(this,SIGNAL(clicked(bool)),this,SLOT(clicked()));
}

void PushButtonPrivat::clicked()
{
    emit button_status(device_port);
}


Device_Info::Device_Info(QString IP, QString name, int port, int row, QObject *parent)
    : QObject(parent),IP(IP),Name(name),Port(port),Row(row),parent(parent)
{
    Item    = new QTreeWidgetItem;
    Item->setText(0,name);
    Item->setText(1,IP);

    Connect = disconnected;

    for(int i=0;i<Row;i++){
        Timer_New *timer = new Timer_New(i,this);
        QObject::connect(timer,SIGNAL(time_out(int)),this,SLOT(timeout(int)));
        on_timer.insert(i,timer);

        Timer_New *timer1 = new Timer_New(i,this);
        QObject::connect(timer1,SIGNAL(time_out(int)),this,SLOT(timeout(int)));
        off_timer.insert(i,timer1);
    }
}

void Device_Info::timeout(int device_port)
{
    emit set_one_off(Name,device_port,on_off);
}

void Device_Info::set_all_btn(Device_Name name,int Is_delay, ON_OFF on_off)
{
    if(name != Name){
        return ;
    }
    if(Connect == disconnected){
        QMessageBox::warning((QWidget*)parent,tr("警告"),tr("%1设备没有连接网络，请先连接网络！").arg(name),tr("确定"));
        return ;
    }
    if(on_off == ON){
        for(int i=0;i < Row;i++){
            QMap<int,Timer_New *>::Iterator it;
            it  = on_timer.find(i);
            if(Is_delay){
                it.value()->set_info(current.value(i).on_delay);
            }
            else{
                it.value()->set_info(0);
            }
        }
    }
    else {
        for(int i=0;i<Row;i++){
            QMap<int,Timer_New *>::Iterator it;
            it  = off_timer.find(i);
            if(Is_delay){
                it.value()->set_info(current.value(i).off_delay);
            }
            else{
                it.value()->set_info(0);
            }
        }
    }
    this->on_off    = on_off;
}

void Device_Info::connected_success(Device_Name name)
{
    if(this->name() != name){
        return ;
    }
    for(int i=0;i<Row;i++){

    }
}
