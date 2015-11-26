#ifndef OUTLET_CONFIGURATION_H
#define OUTLET_CONFIGURATION_H

#include <QWidget>
#include "base.h"

namespace Ui {
class Outlet_Configuration;
}

class Outlet_Configuration : public QWidget
{
    Q_OBJECT

public:
    explicit Outlet_Configuration(QWidget *parent = 0);
    ~Outlet_Configuration();

public slots:
    void set_Device_Name(Device_Name name);
    void set_row(int row);
    void set_on_delay(int device_port,int on_delay);
    void set_off_delay(int device_port,int off_delay);
    void set_describe(int device_port,QString describe);

private:
    Ui::Outlet_Configuration *ui;
};

#endif // OUTLET_CONFIGURATION_H
