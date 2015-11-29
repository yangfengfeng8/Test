#include "control_confirmation.h"
#include "ui_control_confirmation.h"
#include <QPalette>

Control_Confirmation::Control_Confirmation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Control_Confirmation)
{
    ui->setupUi(this);

    QPalette palette;
    palette.setBrush(QPalette::Window,QBrush(QColor(Qt::white)));
    setAutoFillBackground(true);
    setPalette(palette);
    flag    = 0;
}

Control_Confirmation::~Control_Confirmation()
{
    delete ui;
}

void Control_Confirmation::set_nothing(QString name)
{
    this->name  = name;
    setWindowTitle(tr("%1 Outlets Confirmation").arg(this->name));
    ui->label->setText("No Outlets selected for contain special characters.");
    ui->groupBox->setHidden(true);
    flag    = 0;
}

void Control_Confirmation::set_hint(QString name, int row)
{
    this->row   = row;
    this->name  = name;
    ui->label->setText("All accessible outlets selected for Off Delayed.");
    setWindowTitle(tr("%1 Outlets Confirmation").arg(this->name));
    for(int i=row;i<8;i++){
        ui->groupBox->findChild<QFrame*>(tr("frame_%1").arg(i+1))->setHidden(true);
    }
    ui->groupBox->setHidden(false);
    flag    = 1;
}

void Control_Confirmation::set_hint(QString name, QString dump, int row)
{
    this->row   = row;
    this->name  = name;
    dump       = dump;
    ui->groupBox->setHidden(false);
    ui->label->setText("All accessible outlets selected for On Delayed.");
    setWindowTitle(tr("%1 Outlets Confirmation").arg(this->name));
    for(int i=row;i<8;i++){
        ui->groupBox->findChild<QFrame*>(tr("frame_%1").arg(i+1))->setHidden(true);
    }
    flag    = 1;
}

void Control_Confirmation::set_on_delay(int device_port, int on_delay)
{
    ui->groupBox->findChild<QLabel*>(tr("label%1").arg(device_port))->setText(tr("Outlet %1 will turn on in").arg(device_port));
    ui->groupBox->findChild<QLabel*>(tr("label_%1").arg(device_port))->setText(tr("%1").arg(on_delay));
    ui->groupBox->findChild<QFrame*>(tr("frame_%1").arg(device_port))->setHidden(false);

    on_off    = ON;
    if(on_delay){
        Is_Delay    = 1;
    }
    else {
        Is_Delay    = 0;
    }
}

void Control_Confirmation::set_on_delay(int device_port)
{
    ui->groupBox->findChild<QLabel*>(tr("label%1").arg(device_port))->setText(tr("Outlet %1 will turn off in").arg(device_port));
    ui->groupBox->findChild<QLabel*>(tr("label_%1").arg(device_port))->setText("Immediately on");
    ui->groupBox->findChild<QFrame*>(tr("frame_%1").arg(device_port))->setHidden(false);
    on_off    = ON;
    Is_Delay    = 0;
}

void Control_Confirmation::set_off_delay(int device_port, int off_delay)
{
    ui->groupBox->findChild<QLabel*>(tr("label%1").arg(device_port))->setText(tr("Outlet %1 will turn off in").arg(device_port));
    ui->groupBox->findChild<QLabel*>(tr("label_%1").arg(device_port))->setText(tr("%1").arg(off_delay));
    ui->groupBox->findChild<QFrame*>(tr("frame_%1").arg(device_port))->setHidden(false);
    on_off    = OFF;
    Is_Delay    = 1;
}

void Control_Confirmation::set_off_delay(int device_port)
{
    ui->groupBox->findChild<QLabel*>(tr("label%1").arg(device_port))->setText(tr("Outlet %1 will turn off in").arg(device_port));
    ui->groupBox->findChild<QLabel*>(tr("label_%1").arg(device_port))->setText("Immediately off");
    ui->groupBox->findChild<QFrame*>(tr("frame_%1").arg(device_port))->setHidden(false);
    on_off    = OFF;
    Is_Delay    = 0;
}

void Control_Confirmation::on_Applay_clicked()
{
    if(flag){
        emit send_ok(name,Is_Delay,on_off);
    }
    this->accept();
}

void Control_Confirmation::on_Cancle_clicked()
{
    emit send_cancle();
    this->reject();
}
