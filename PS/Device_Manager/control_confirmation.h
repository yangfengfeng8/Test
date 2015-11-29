#ifndef CONTROL_CONFIRMATION_H
#define CONTROL_CONFIRMATION_H

#include <QDialog>
#include "base.h"

namespace Ui {
class Control_Confirmation;
}

class Control_Confirmation : public QDialog
{
    Q_OBJECT

public:
    explicit Control_Confirmation(QWidget *parent = 0);
    ~Control_Confirmation();

    void set_nothing(QString name);
    void set_hint(QString name,int row);
    void set_hint(QString name, QString dump, int row);
    void set_on_delay(int device_port,int on_delay);
    void set_on_delay(int device_port);
    void set_off_delay(int device_port,int off_delay);
    void set_off_delay(int device_port);

private slots:
    void on_Applay_clicked();

    void on_Cancle_clicked();

signals:
    void send_ok(Device_Name,int flag,ON_OFF);

    void send_cancle();

private:
    Ui::Control_Confirmation *ui;
    int row;
    Device_Name name;
    ON_OFF on_off;
    int flag;
    int Is_Delay;
};

#endif // CONTROL_CONFIRMATION_H
