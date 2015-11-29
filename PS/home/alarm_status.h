#ifndef ALARM_STATUS_H
#define ALARM_STATUS_H

#include <QWidget>
#include "base.h"

namespace Ui {
class Alarm_Status;
}

class Alarm_Status : public QWidget
{
    Q_OBJECT

public:
    explicit Alarm_Status(QWidget *parent = 0);
    ~Alarm_Status();

    void get_alarm_information(Device_Name name, int device_port, Alarm alarm);

private slots:
    void on_checkBox_buzzer_stateChanged(int arg1);

    void on_buzzer_close_clicked();

signals:
    void close_buzzer();

    void change_buzzer_status(int index);

private:
    Ui::Alarm_Status *ui;
    int index;
};

#endif // ALARM_STATUS_H
