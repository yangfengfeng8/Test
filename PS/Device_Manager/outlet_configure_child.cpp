#include "outlet_configure_child.h"
#include "ui_outlet_configuration_child.h"
#include <QPalette>
#include <QMessageBox>

Outlet_configure_child::Outlet_configure_child(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Outlet_configure_child)
{
    ui->setupUi(this);
    QPalette palette;
    palette.setBrush(QPalette::Window,QBrush(QColor(Qt::white)));
    setAutoFillBackground(true);
    setPalette(palette);
}

Outlet_configure_child::~Outlet_configure_child()
{
    delete ui;
}

void Outlet_configure_child::setName(QString name)
{
    this->name  = name;
    ui->lineEdit->setText(this->name + "-" + port_name);
}

void Outlet_configure_child::setPortName(QString name)
{
    this->port_name  = name;
    ui->lineEdit->setText(this->name+"-"+port_name);
}

void Outlet_configure_child::setInterval(int on_delay, int off_delay)
{
    ui->on_slider->setValue(on_delay);
    ui->off_slider->setValue(off_delay);
}

void Outlet_configure_child::setdevice_port(int device_port)
{
    this->device_port   = device_port;
}

void Outlet_configure_child::on_Cancle_clicked()
{
    emit send_Interval();
}

void Outlet_configure_child::on_Apply_clicked()
{
    QMessageBox messagebox;
    if(messagebox.information(this,tr("Update Success"),tr("on-delay: %1s, off-delay: %2s").arg(ui->on_slider->value()).arg(ui->off_slider->value()),"Ok","Cancle")){
        return ;
    }
    emit send_Interval(name,device_port,ui->on_slider->value(),ui->off_slider->value());
}
