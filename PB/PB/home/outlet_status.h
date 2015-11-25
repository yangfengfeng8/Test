#ifndef OUTLET_STATUS_H
#define OUTLET_STATUS_H

#include <QWidget>

namespace Ui {
class Outlet_Status;
}

class Outlet_Status : public QWidget
{
    Q_OBJECT

public:
    explicit Outlet_Status(QWidget *parent = 0);
    ~Outlet_Status();

private:
    Ui::Outlet_Status *ui;
};

#endif // OUTLET_STATUS_H
