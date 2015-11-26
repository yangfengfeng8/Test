#include "control.h"
#include "ui_control.h"
#include <QAbstractItemModel>
#include <QDebug>
#include <QSplitter>
#include "./Device_Manager/outlet_configure_child.h"

Control::Control(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Control)
{
    ui->setupUi(this);

    pix_on.load(":/image/green.png");
    pix_off.load(":/image/gray.png");

    QPalette palette;
    palette.setBrush(QPalette::Window,QBrush(QColor(Qt::white)));
    setAutoFillBackground(true);
    setPalette(palette);

    model   = ui->control_tableWidget->model();

    QSplitter *splitter   = new QSplitter(Qt::Vertical);
    splitter->addWidget(ui->control_tableWidget);
    splitter->addWidget((QWidget *)ui->textBrowser);
    splitter->setHandleWidth(0);
    splitter->setCollapsible(0,false);
    splitter->setCollapsible(1,false);
    ui->verticalLayout->addWidget(splitter);

    Init_tabWidget(8);

    index   = 0;
}

Control::~Control()
{
    delete ui;
}

void Control::Init_tabWidget(int row,int column)
{
    ui->control_tableWidget->setRowCount(row);
    ui->control_tableWidget->setColumnCount(column);

    ui->control_tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->control_tableWidget->setRowCount(row);
    ui->control_tableWidget->setColumnCount(column);

    for(int i=0;i<8;i++){
        QLabel  *label      = new QLabel;
        label->setPixmap(pix_off);
        label->setObjectName(tr("%1").arg(i));
        label->setMaximumSize(pix_off.width()+12,pix_off.height()+12);
        label->setMinimumSize(pix_off.width()+12,pix_off.height()+12);
        QWidget *widget_2   = new QWidget;
        QHBoxLayout *h_layout_2 = new QHBoxLayout;
        h_layout_2->addWidget(label);
        widget_2->setLayout(h_layout_2);
        ui->control_tableWidget->setCellWidget(i,1,widget_2);

        PushButtonPrivat *btn    = new PushButtonPrivat(i,this);

        QFont font;
        font.setPixelSize(12);
        btn->setFont(font);
        btn->setText(tr("Trigger"));
        btn->setEnabled(true);
        btn->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
        btn->setMaximumSize(55,40);
        btn->setMinimumSize(55,40);
        connect(btn,SIGNAL(button_status(int)),this,SIGNAL(set_btn_status(int)));

        QWidget *widget     = new QWidget;
        QHBoxLayout *h_layout   = new QHBoxLayout;
        h_layout->addWidget(btn);
        widget->setLayout(h_layout);
        ui->control_tableWidget->setCellWidget(i,3,widget);

        PushButtonPrivat *search    = new PushButtonPrivat(i,this);

        search->setFont(font);
        search->setText(tr("query"));
        search->setEnabled(true);
        search->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
        search->setMaximumSize(55,40);
        search->setMinimumSize(55,40);
        connect(btn,SIGNAL(button_status(int)),this,SIGNAL(search_btn_status(int)));

        QWidget *widget_3     = new QWidget;
        QHBoxLayout *h_layout_3   = new QHBoxLayout;
        h_layout_3->addWidget(search);
        widget_3->setLayout(h_layout_3);
        ui->control_tableWidget->setCellWidget(i,4,widget_3);

        PushButtonPrivat *modification    = new PushButtonPrivat(i,this);

        modification->setFont(font);
        modification->setText(tr("amend"));
        modification->setEnabled(true);
        modification->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
        modification->setMaximumSize(55,40);
        modification->setMinimumSize(55,40);
        connect(modification,SIGNAL(button_status(int)),this,SIGNAL(modification(int)));

        QWidget *widget_4     = new QWidget;
        QHBoxLayout *h_layout_4   = new QHBoxLayout;
        h_layout_4->addWidget(modification);
        widget_4->setLayout(h_layout_4);
        ui->control_tableWidget->setCellWidget(i,7,widget_4);
    }    
    ui->control_tableWidget->setMinimumHeight(8*60);
}

void Control::on_Control_All_Trigger_clicked()
{
    emit set_all_on_off(index);
}

void Control::on_Control_All_ComboBox_currentIndexChanged(int index)
{
    this->index = index;
}

void Control::on_control_tableWidget_itemChanged(QTableWidgetItem *item)
{
    switch (item->column()){
    case 5: emit set_Max(item->row(),(item->text().toInt() * 100));
        break;
    case 6: emit set_Min(item->row(),item->text().toInt());
        break;
    case 8: emit set_Describe(item->row(),item->text());
        break;
    }
}

void Control::get_Max(int device_port, int val)
{
    model->setData(model->index(device_port,5),(double)val);
    max.insert(device_port,(double)val);
}

void Control::get_Min(int device_port, int val)
{
    model->setData(model->index(device_port,6),(double)val);
}

void Control::get_Describe(int device_port, QString str)
{
    model->setData(model->index(device_port,8),str);
}

void Control::get_btn_status(int device_port, ON_OFF status)
{
    if(status == ON){
        ui->control_tableWidget->cellWidget(device_port,1)->findChild<QLabel *>(tr("%1").arg(device_port))->setPixmap(pix_on);
    }
    else {
        ui->control_tableWidget->cellWidget(device_port,1)->findChild<QLabel *>(tr("%1").arg(device_port))->setPixmap(pix_off);
    }
}

void Control::get_real_eletric(int device_port, int real_eletric)
{
    model->setData(model->index(device_port,2),tr("%1 A").arg(real_eletric));
}

void Control::get_row(int row)
{
    for(int i=0;i<row;i++){
        ui->control_tableWidget->setRowHidden(i,false);
    }
    for(int i=row;i < 8;i++){
        ui->control_tableWidget->setRowHidden(i,true);
    }
    ui->control_tableWidget->setMinimumHeight(row*60);
}

