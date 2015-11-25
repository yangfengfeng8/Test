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
}

Alarm_Status::~Alarm_Status()
{
    delete ui;
}
