#include "loadmanagement.h"
#include "ui_loadmanagement.h"
#include <QPalette>

LoadManagement::LoadManagement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoadManagement)
{
    ui->setupUi(this);
    QPalette palette;
    palette.setBrush(QPalette::Window,QBrush(QColor(Qt::white)));
//    palette.setBrush();
    setAutoFillBackground(true);
    setPalette(palette);
}

LoadManagement::~LoadManagement()
{
    delete ui;
}
