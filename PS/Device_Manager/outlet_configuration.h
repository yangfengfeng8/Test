#ifndef OUTLET_CONFIGURATION_H
#define OUTLET_CONFIGURATION_H

#include <QWidget>

namespace Ui {
class Outlet_Configuration;
}

class Outlet_Configuration : public QWidget
{
    Q_OBJECT

public:
    explicit Outlet_Configuration(QWidget *parent = 0);
    ~Outlet_Configuration();

private:
    Ui::Outlet_Configuration *ui;
};

#endif // OUTLET_CONFIGURATION_H
