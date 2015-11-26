#include "outlet_configuration.h"
#include "ui_outlet_configuration.h"
#include <QPalette>

Outlet_Configuration::Outlet_Configuration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Outlet_Configuration)
{
    ui->setupUi(this);
    QPalette palette;
    palette.setBrush(QPalette::Window,QBrush(QColor(Qt::white)));
    setAutoFillBackground(true);
    setPalette(palette);
}

Outlet_Configuration::~Outlet_Configuration()
{
    delete ui;
}

void Outlet_Configuration::set_Device_Name(Device_Name name)
{
    setWindowTitle(tr("%1 Outlet Configuration").arg(name));
}

void Outlet_Configuration::set_row(int row)
{
    for(int i=0;i<row;i++){
        ui->groupBox->findChild<QFrame*>(tr("frame_%1").arg(i+1))->setHidden(false);
    }
    for(int i=row;i<8;i++){
        ui->groupBox->findChild<QFrame*>(tr("frame_%1").arg(i+1))->setHidden(true);
    }
}

void Outlet_Configuration::set_on_delay(int device_port, int on_delay)
{
    ui->groupBox->findChild<QLabel*>(tr("label_on_%1").arg(device_port+1))->setText(tr("%1 seconds").arg(on_delay));
}

void Outlet_Configuration::set_off_delay(int device_port, int off_delay)
{
    ui->groupBox->findChild<QLabel*>(tr("label_off_%1").arg(device_port+1))->setText(tr("%1 seconds").arg(off_delay));
}

void Outlet_Configuration::set_describe(int device_port, QString describe)
{
    ui->groupBox->findChild<QLabel*>(tr("label%1").arg(device_port+1))->setText(describe);
}
