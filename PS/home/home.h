#ifndef HOME_H
#define HOME_H

#include <QWidget>
#include "base.h"
#include <QTimer>

namespace Ui {
class Home;
}

class Home : public QWidget
{
    Q_OBJECT

public:
    explicit Home(QWidget *parent = 0);
    ~Home();

    void Init();

    void open_data_log();

    void display(QString date,QString time,QString data,int row);

public slots:
    //获取断开信息,判断是否报警；
    void get_alarm_information(Device_Name name, int device_port, Alarm alarm);

    void get_current_information(QString power);

    void update_log(QString info);

    void timeout();

private:
    Ui::Home *ui;
    QTimer timer;
    int uptime;
    int day;
    int hour;
    int min;
    QList<QString> str;
};

#endif // HOME_H
