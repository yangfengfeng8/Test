#ifndef CHANGEDEVICE_H
#define CHANGEDEVICE_H

#include "base.h"

class Changedevice : public QDialog
{
    Q_OBJECT
public:
    Changedevice(QMap<QString,Device_Info *> device_info,QWidget *parent = 0);
    ~Changedevice(){}

    bool check_IP(const QString ip);

public slots:
    void change_combobox_name(int);
    void change_combobox_row(int);

    void change_Ok_btn();
    void change_Cancle_btn();

signals:
    void change_data(QString &name,QString &IP,QString &port,int &);

private:
    QLineEdit *ip;
    QLineEdit *port;

    QStringList name;
    QStringList IP_list;
    QStringList port_list;
    int row_index;
    int name_index;
    QMap<QString,Device_Info *> device_info;
};

#endif // CHANGEDEVICE_H
