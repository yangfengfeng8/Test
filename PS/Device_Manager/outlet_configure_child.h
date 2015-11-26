#ifndef OUTLET_CONFIGURE_CHILD_H
#define OUTLET_CONFIGURE_CHILD_H

#include <QWidget>
#include "base.h"

namespace Ui {
class Outlet_configure_child;
}

class Outlet_configure_child : public QWidget
{
    Q_OBJECT

public:
    explicit Outlet_configure_child(QWidget *parent = 0);
    ~Outlet_configure_child();

    void setName(Device_Name name);

    void setPortName(QString name);

    void setInterval(int on_delay,int off_delay);

    void setdevice_port(int device_port);

signals:
    void send_Interval(Device_Name,int device_port, int on_delay,int off_delay);

    void send_Interval();

private slots:
    void on_Cancle_clicked();

    void on_Apply_clicked();

private:
    Ui::Outlet_configure_child *ui;

    Device_Name name;
    QString port_name;
    int on_interval;
    int off_interval;
    int device_port;
};

#endif // OUTLET_CONFIGURE_CHILD_H
