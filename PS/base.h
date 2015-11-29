#ifndef BASE
#define BASE

#include <QTreeWidgetItem>
#include <QList>
#include <QComboBox>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
#include <QDebug>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QDialog>
#include <QTimer>
#include <QObject>

enum Alarm{Low_Alarm,Normal,OverLoad};//低于最小值，正常，超载；

enum ON_OFF{OFF,ON};
enum Connected{connected,disconnected};

typedef QString Device_Name;

typedef struct {
    QString Name;
    QString psd;
}UserInfo;

typedef struct {
    ON_OFF power_port;
    int device_port;
    int max_current;    //电流最大值；
    int min_current;
    int actual_current;
    QString describe;
    int on_delay;
    int off_delay;
}Current_status;

class Timer_New : public QObject
{
    Q_OBJECT
public:
    Timer_New(int device_port,QObject *parent = 0);
    ~Timer_New(){}

    void set_info(int interval);

signals:
    void time_out(int device_port);

public slots:
    void timeout();

private:
    int device_port;
    int Interval;
    QTimer timer;
};


class PushButtonPrivat : public QPushButton
{
    Q_OBJECT
public:
    PushButtonPrivat(int device_port, QWidget *parent);
signals:
    void button_status(int);

public slots:
    void clicked();

private:
    int device_port;
};

class Device_Info : public QObject
{
    Q_OBJECT
public:
    Device_Info(QString IP,QString name,int port,int row,QObject *parent = 0);

    ~Device_Info(){
        for(int i=0;i<Row;i++){

        }

    }

    inline QTreeWidgetItem* item(){return Item;}

    inline QString ip()const {return IP;}
    inline QString name()const {return Name;}
    inline int port()const {return Port;}
    inline int row()const {return Row;}
    inline Connected connect()const{return Connect;}
    inline Current_status current_status(int index){return current.value(index);}

    inline void set_ip(const QString ip){IP  = ip;Item->setText(1,IP);}
    inline void set_name(const QString name){this->Name = name;Item->setText(0,Name);}
    inline void set_port(const int port){this->Port  = port;}
    inline void set_row(const int row){this->Row = row;}
    inline void set_connect(const Connected connect){this->Connect = connect;}
    inline void set_Current_status(int index,Current_status current_status){this->current.insert(index,current_status);}

    inline void set_Current_status(int device_port,int max_current,int min_current,int actual_current,int on_delay,int off_delay,QString describe){
        Current_status current_status;
        current_status.max_current  = max_current;
        current_status.min_current  = min_current;
        current_status.actual_current   = actual_current;
        current_status.describe = describe;
        current_status.power_port   = OFF;
        current_status.on_delay     = on_delay;
        current_status.off_delay    = off_delay;
        this->current.insert(device_port,current_status);
    }
    inline void change_Current_status(int device_port,int max_current){
        Current_status current_status   = this->current_status(device_port);
        current_status.max_current  = max_current;
        current.insert(device_port,current_status);
    }
    inline void change_Current_status(int device_port, int actual_current,int useless){
        Current_status current_status   = this->current_status(device_port);
        current_status.max_current  = actual_current;
        useless = useless;
        current.insert(device_port,current_status);
    }
    inline void change_Current_status(int device_port, int min_current, int dump,int useless){
        useless = useless;
        dump    = dump;
        Current_status current_status   = this->current_status(device_port);
        current_status.min_current  = min_current;
        current.insert(device_port,current_status);
    }

    inline void change_Current_status(int device_port, QString describe){
        Current_status current_status   = this->current_status(device_port);
        current_status.describe = describe;
        current.insert(device_port,current_status);
    }
    inline void change_Current_status(int device_port,ON_OFF on_off){
        Current_status current_status   = this->current_status(device_port);
        current_status.power_port   = on_off;
        current.insert(device_port,current_status);
    }
    inline void change_Current_status(QString dump,int device_port,int on_delay,int off_delay){
        dump    = dump;
        Current_status current_status   = this->current_status(device_port);
        current_status.off_delay        = off_delay;
        current_status.on_delay         = on_delay;
        current.insert(device_port,current_status);
    }

    inline int size(){return current.size();}

signals:
    //设置端口状态；
    void set_one_off(Device_Name name,int device_port,ON_OFF);

public slots:
    void timeout(int device_port);

    void set_all_btn(Device_Name name, int Is_delay, ON_OFF on_off);

    void connected_success(Device_Name name);

private:
    QObject *parent;
    QString IP;
    QString Name;
    int Port;
    int Row;
    ON_OFF on_off;
    QTreeWidgetItem *Item;
    Connected Connect;
    QMap<int,Current_status> current;
    QMap<int,Timer_New*> on_timer;
    QMap<int,Timer_New*> off_timer;
};

#endif // BASE

