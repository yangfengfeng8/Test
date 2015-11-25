#include "curve_widget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

Curve_Widget::Curve_Widget(Device_Name name, int row, QList<int> ele_max, QWidget *parent) : QWidget(parent)
    ,name(name),row(row),ele_max(ele_max)
{
    for(int i=0;i<8;i++){
        Curve *curve    = new Curve(i,ele_max.at(i),QColor(Qt::green));
        curve_manage.insert(i,curve);
        connect(this,SIGNAL(send_actual(int,int)),curve,SLOT(recv_data(int,int)));
        connect(this,SIGNAL(send_max(int,int)),curve,SLOT(get_ele_max(int,int)));
    }
    display_curve(this->row);

    QHBoxLayout *h_layout   = new QHBoxLayout;
    for(int i=0;i<8;i+=2){
        h_layout->addWidget(curve_manage.value(i));
    }
    QHBoxLayout *h_layout2  = new QHBoxLayout;
    for(int i=1;i<8;i+=2){
        h_layout2->addWidget(curve_manage.value(i));
    }
    QVBoxLayout *v_layout   = new QVBoxLayout;
    v_layout->addLayout(h_layout);
    v_layout->addLayout(h_layout2);
    setLayout(v_layout);
}

void Curve_Widget::display_curve(int row)
{
    switch(row){
    case 1:
        curve_manage.value(0)->show();
        for(int i=1;i<8;i++){
            curve_manage.value(i)->hide();
        }
        break;
    case 4:
        for(int i=4;i<8;i++){
            curve_manage.value(i)->hide();
            curve_manage.value(i-4)->show();
        }
        break;
    case 6:
        for(int i=6;i<8;i++){
            curve_manage.value(i)->hide();
        }
        for(int i=0;i<6;i++){
            curve_manage.value(i)->show();
        }
        break;
    case 8:
        for(int i=0;i<8;i++){
            curve_manage.value(i)->show();
        }
        break;
    }
}

void Curve_Widget::get_actual(Device_Name name, int device_port, int actual)
{
    if(this->name != name){
        return ;
    }
    emit send_actual(device_port,actual);
}

void Curve_Widget::get_max(Device_Name name, int device_port, int max)
{
    if(this->name != name){
        return ;
    }
    emit send_max(device_port,max);
}

void Curve_Widget::change_name(Device_Name name, int row, QList<int> ele_max)
{
    this->name  = name;
    this->row   = row;
    display_curve(this->row);
    emit clear_info();
    for(int i=0;i<row;i++){
        emit send_max(i,ele_max.at(i));
    }
}



