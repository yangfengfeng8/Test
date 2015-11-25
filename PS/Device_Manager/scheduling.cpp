#include "scheduling.h"
#include "ui_scheduling.h"

Scheduling::Scheduling(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Scheduling)
{
    ui->setupUi(this);
}

Scheduling::~Scheduling()
{
    delete ui;
}
