#ifndef CURVE_WIDGET_H
#define CURVE_WIDGET_H

#include <QWidget>
#include "curve/curve.h"

class Curve_Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Curve_Widget(Device_Name name, int row, QList<int> ele_max, QWidget *parent = 0);

    void display_curve(int row);

signals:
    void send_actual(int device_port,int actual);

    void send_max(int device_port,int max);

    void clear_info();

public slots:
    void get_actual(Device_Name name,int device_port,int actual);

    void get_max(Device_Name name,int device_port,int max);

    void change_name(Device_Name name,int row,QList<int> ele_max);

private:
    Device_Name name;
    int row;
    QList<int> ele_max;

    QMap<int,Curve *> curve_manage;
};

#endif // CURVE_WIDGET_H
