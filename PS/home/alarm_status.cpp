#include "alarm_status.h"
#include "ui_alarm_status.h"
#include <QPalette>

Alarm_Status::Alarm_Status(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Alarm_Status)
{
    ui->setupUi(this);

    QPalette palette;
    palette.setBrush(QPalette::Window,QBrush(QColor(Qt::white)));
//    palette.setBrush();
    setAutoFillBackground(true);
    setPalette(palette);

    ui->buzzer_close->setEnabled(false);
}

Alarm_Status::~Alarm_Status()
{
    delete ui;
}

void Alarm_Status::get_alarm_information(Device_Name name, int device_port, Alarm alarm)
{
    switch(alarm){
    case Low_Alarm:ui->home_label_alarm_status_2->setText(tr("%1 of the %2 port current value is lower than the minimum current value!!!").arg(device_port).arg(name));
        if(index){
            ui->buzzer_close->setEnabled(true);
        }
        break;
    case Normal:ui->home_label_alarm_status_2->setText("No Alarms Present");
        ui->buzzer_close->setEnabled(false);
        break;
    case OverLoad:ui->home_label_alarm_status_2->setText(tr("%1 of the %2 port current value is more than the maximum current value!!!").arg(device_port).arg(name));
        if(index){
            ui->buzzer_close->setEnabled(true);
        }
        break;
    }
}

void Alarm_Status::on_checkBox_buzzer_stateChanged(int arg1)
{
    index   = arg1;
    if(index == 2){
        ui->checkBox_buzzer->setText("Enable Buzzer");
    }
    else {
        ui->checkBox_buzzer->setText("Disenable Buzzer");
    }
    emit change_buzzer_status(arg1);
}

void Alarm_Status::on_buzzer_close_clicked()
{
    emit close_buzzer();
}
