#include "home.h"
#include "ui_home.h"
#include <QFile>
#include <QDateTime>

Home::Home(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);

    connect(&timer,SIGNAL(timeout()),this,SLOT(timeout()));
    timer.start(60 * 1000);

    Init();
}

Home::~Home()
{
    delete ui;
}

void Home::Init()
{
    uptime  = 0;
    day     = 0;
    hour    = 0;
    min     = 0;
}

void Home::open_data_log()
{
    QString str = QDateTime::currentDateTime().toString("yyyy.MM.dd");
    QFile file("./log/data/str");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Truncate)){
        qDebug()<<file.errorString();
    }
    QTextStream out(&file);
    QString str1;
    QList<QString> list;
    while(!out.atEnd()){
        str1 = out.readLine();
        list.prepend(str1);
    }
    for(int i=0;i<10;i++){
        display(list.at(0).section(";",0,0),list.at(0).section(";",1,1),list.at(";",2));
        this->str.append(list.at(i));
    }
}

void Home::display(QString date, QString time, QString data,int row)
{
    ui->tableWidget->model()->setData(ui->tableWidget->model()->index(row,0),date);
    ui->tableWidget->model()->setData(ui->tableWidget->model()->index(row,1),time);
    ui->tableWidget->model()->setData(ui->tableWidget->model()->index(row,2),data);
}

void Home::get_alarm_information(Device_Name name,int device_port,Alarm alarm)
{
    switch(alarm){
    case Low_Alarm:ui->home_label_alarms_2->setText(tr("%1 of the %2 port current value is lower than the minimum current value!!!").arg(device_port).arg(name));
        break;
    case Normal:ui->home_label_alarms_2->setText("No Alarms Present");
        break;
    case OverLoad:ui->home_label_alarms_2->setText(tr("%1 of the %2 port current value is more than the maximum current value!!!").arg(device_port).arg(name));
        break;
    }
}

void Home::get_current_information(QString power)
{
    ui->label_power->setText(power);
}

void Home::update_log(QString info)
{
    str.prepend(info);
    str.removeLast();
    for(int i=0;i<10;i++){
        display(str.at(i).section(";",0,0),str.at(i).section(";",1,1),str.at(i).section(";",2));
    }
}

void Home::timeout()
{
    uptime++;
    if(uptime == 60){
        uptime  = 0;
        hour++;
    }
    if(hour == 24){
        hour    = 1;
        day++;
    }
    ui->label_uptime->setText(tr("%1 days %2 hour %3 minute").arg(day).arg(hour).arg(uptime));
}
