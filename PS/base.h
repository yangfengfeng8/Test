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


class PushButtonPrivat : public QPushButton
{
    Q_OBJECT
public:
    PushButtonPrivat(int device_port, QWidget *parent)
        : QPushButton(parent)
        ,device_port(device_port)
    {
        connect(this,SIGNAL(clicked(bool)),this,SLOT(clicked()));
    }
signals:
    void button_status(int);

public slots:
    void clicked(){
        emit button_status(device_port);
    }

private:
    int device_port;
};

class Device_Info : public QObject
{
    Q_OBJECT
public:
    Device_Info(QString IP,QString name,int port,int row,QObject *parent = 0)
        : QObject(parent),IP(IP),Name(name),Port(port),Row(row),parent(parent)
    {
        Item    = new QTreeWidgetItem;
        Item->setText(0,name);
        Item->setText(1,IP);

        Connect = disconnected;

        btn_id  = 0;

        QObject::connect(&timer,SIGNAL(timeout()),this,SLOT(timeout()));
    }
    ~Device_Info(){}

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
    void set_one_off(Device_Name name,int device_port,ON_OFF);

public slots:
    void set_all_btn(Device_Name name,int interval,ON_OFF on_off){
        if(name != Name){
            return ;
        }
        if(Connect == disconnected){
            QMessageBox::warning((QWidget*)parent,tr("警告"),tr("%1设备没有连接网络，请先连接网络！").arg(name),tr("确定"));
            return ;
        }
        timer.start(interval*1000);
        this->on_off    = on_off;
    }

    void timeout(){
        emit set_one_off(Name,btn_id,on_off);
        btn_id++;
        if(btn_id >= Row){
            btn_id  = 0;
            timer.stop();
        }
    }

private:
    QObject *parent;
    QString IP;
    QString Name;
    int Port;
    int Row;
    int btn_id;
    ON_OFF on_off;
    QTimer timer;
    QTreeWidgetItem *Item;
    Connected Connect;
    QMap<int,Current_status> current;
};

#endif // BASE

