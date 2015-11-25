#include "outlet_configure_child.h"
#include "ui_outlet_configuration_child.h"

Outlet_configure_child::Outlet_configure_child(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Outlet_configure_child)
{
    ui->setupUi(this);
}

Outlet_configure_child::~Outlet_configure_child()
{
    delete ui;
}
