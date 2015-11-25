#include "outlet_status.h"
#include "ui_outlet_status.h"

Outlet_Status::Outlet_Status(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Outlet_Status)
{
    ui->setupUi(this);
}

Outlet_Status::~Outlet_Status()
{
    delete ui;
}
