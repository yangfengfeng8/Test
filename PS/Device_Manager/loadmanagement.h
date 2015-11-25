#ifndef LOADMANAGEMENT_H
#define LOADMANAGEMENT_H

#include <QWidget>

namespace Ui {
class LoadManagement;
}

class LoadManagement : public QWidget
{
    Q_OBJECT

public:
    explicit LoadManagement(QWidget *parent = 0);
    ~LoadManagement();

private:
    Ui::LoadManagement *ui;
};

#endif // LOADMANAGEMENT_H
