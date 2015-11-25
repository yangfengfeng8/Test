#include "log_event.h"
#include "ui_log_event.h"

Log_Event::Log_Event(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Log_Event)
{
    ui->setupUi(this);

    QPalette palette;
    palette.setBrush(QPalette::Window,QBrush(QColor(Qt::white)));
//    palette.setBrush();
    setAutoFillBackground(true);
    setPalette(palette);
}

Log_Event::~Log_Event()
{
    delete ui;
}
