#include "alarm_status.h"
#include "ui_alarm_status.h"

Alarm_Status::Alarm_Status(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Alarm_Status)
{
    ui->setupUi(this);
}

Alarm_Status::~Alarm_Status()
{
    delete ui;
}
