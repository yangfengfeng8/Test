#include "outlet_configuration.h"
#include "ui_outlet_configuration.h"
#include <QTableWidget>
#include <QScrollBar>

Outlet_Configuration::Outlet_Configuration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Outlet_Configuration)
{
    ui->setupUi(this);

}

Outlet_Configuration::~Outlet_Configuration()
{
    delete ui;
}
