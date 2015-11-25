#ifndef OUTLET_CONFIGURE_CHILD_H
#define OUTLET_CONFIGURE_CHILD_H

#include <QWidget>

namespace Ui {
class Outlet_configure_child;
}

class Outlet_configure_child : public QWidget
{
    Q_OBJECT

public:
    explicit Outlet_configure_child(QWidget *parent = 0);
    ~Outlet_configure_child();

private:
    Ui::Outlet_configure_child *ui;
};

#endif // OUTLET_CONFIGURE_CHILD_H
