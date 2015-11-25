#ifndef ALARM_STATUS_H
#define ALARM_STATUS_H

#include <QWidget>

namespace Ui {
class Alarm_Status;
}

class Alarm_Status : public QWidget
{
    Q_OBJECT

public:
    explicit Alarm_Status(QWidget *parent = 0);
    ~Alarm_Status();

private:
    Ui::Alarm_Status *ui;
};

#endif // ALARM_STATUS_H
