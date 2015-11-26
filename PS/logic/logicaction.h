#ifndef LOGICACTION_H
#define LOGICACTION_H

#include <QObject>
#include "base.h"
#include <QTcpSocket>
#include <QTimer>

class LogicActionPrivate : public QObject
{
    Q_OBJECT
public:
    LogicActionPrivate(Device_Name name,QObject *parent = 0, int row = 8);
    ~LogicActionPrivate();

    void Init_data();

    quint16 qChecksum(const QList<quint8> list, quint8 len);

    inline int get_row(void) const{return row;}

    inline QTcpSocket* get_tcpSocket(void) const{return tcpSocket;}

    void parseCmd();

    void set_one_on_off(int branch,int status);

    void search_one_on_off(int branch);

    void search_RT_eletric(int branch);

    void search_Max_eletric(int branch);

    void search_Device_info(Device_Name name);

    void search_version(Device_Name name);

public slots:
    void timeout();

    void RT_timeout();

    void max_timerout();

    void btn_timeout();

    void connect_success();

    void readMessage();

    void disconnected();

    void set_on_off(Device_Name name, int branch, ON_OFF on_off);

    void search_on_off(Device_Name name);

    void search_Max_eletric(Device_Name name);

signals:
    void return_one_on_off(Device_Name,int branch,ON_OFF);

    void return_one_Max_eletric(Device_Name,int,int);

    void return_one_actual_eletric(Device_Name,int,int);

private:
    QTcpSocket *tcpSocket;
    Device_Name name;
    QTimer *timer;
    QTimer *RT_timer;
    QTimer *btn_timer;
    QTimer *max_timer;

    QList<quint8> list;
    QList<quint8> rv_list;
    char tx[8];

    int btn_id;
    int btn_id2;
    int actual_id;
    int max_id;
    int row;
    quint8 port_status;
};

class LogicAction : public QObject
{
    Q_OBJECT
public:
    explicit LogicAction(QObject *parent = 0);
    ~LogicAction();

signals:
    void connect_error(Device_Name&,QString &);

    void return_one_on_off(Device_Name name,int branch,ON_OFF);

    void return_one_Max_eletric(Device_Name,int,int);

    void return_one_actual_eletric(Device_Name,int,int);

    void set_on_off(Device_Name,int,ON_OFF);

    void search_on_off(Device_Name);

    void search_Max_eletric(Device_Name);

public slots:
    void connect_ready(Device_Name &name, QString &IP, int port, int row, Connected status);

    void displayError(QAbstractSocket::SocketError);

    void disconnected();

private:
    QTcpSocket  *d_socket;

    QMap<Device_Name,LogicActionPrivate*> d_info;



    char tx[8];
};

#endif // LOGICACTION_H
