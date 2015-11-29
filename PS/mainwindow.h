#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidgetItem>
#include <QContextMenuEvent>
#include <QCloseEvent>
#include "dialog/add_device.h"
#include "base.h"
#include "logic/logicaction.h"
#include "dialog/all_btn.h"
#include "curve/curve_widget.h"
#include "home/alarm_status.h"
#include "home/home.h"
#include "Device_Manager/control.h"
#include "Device_Manager/loadmanagement.h"
#include "Device_Manager/outlet_configuration.h"
#include "Device_Manager/scheduling.h"
#include "Event/log_event.h"
#include "./Device_Manager/outlet_configure_child.h"
#include "./Device_Manager/control_confirmation.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void Init_curve_widget();

    void Init_interface();

    void Init_control_confirmation();

//自定义窗口；
    void come_true_widget();

    void GetPrevious_device();

    void Get_UserInfo();

    void Save_Record_device();

    void Save_UserInfo();

    void Init_TreeWidget();

    void add_Treewidget();

    void add_statusBar();

    void Init_tableWidget(int row = 8,int column = 5);

    void Create_tableWidget(int row = 8,int column = 5);

    void Change_tableWidget();

    void Change_tableWidget(int row);

    void Change_tableWidget(int device_port,int max);

    void Change_tableWidget(int device_port,int min,QString dump);

    void Change_tableWidget(int device_port,int actual,int dump);

    void Change_tableWidget(int device_port,QString describe);

    void CreateItemMenu();

    void update_interface();

    void change_contex_menu_status(Device_Info *d_info);


protected:
    void closeEvent(QCloseEvent *);

private slots:
    void on_action_Device_triggered();
//更改网络设置；
    void on_actionChang_Net_triggered();
//添加用户；
    void on_actionAdd_User_triggered();
//删除用户；
    void on_actionDelete_User_triggered();
//更改用户密码；
    void on_actionChang_Passwd_triggered();
//设备重命名；
    void on_actionRename_Device_triggered();

    void on_actionCheck_Power_triggered();
//软件版本；
    void on_actionAbout_triggered();
//帮助手册；
    void on_actionHelp_F1_triggered();
//连接服务端；
    void on_action_connect_triggered();
//断开连接；
    void on_action_disconnect_triggered();
//折叠全部；
    void onaction_fold_triggered();
//右键菜单；
    void on_treeWidget_customContextMenuRequested(const QPoint &pos);
//添加设备；
    void on_action_add_device_triggered();
//删除设备；
    void on_action_del_device_triggered();

    void display_tableWidget(Device_data&);
//单机切换设备显示；
    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

    void receive_max_eletric(QStringList &);

    void rename_device(QString &newName, QString& oldName, QStringList &);

    void change_device(QString &name,QString &IP,QString &port,int &index);

    void Add_user(QString &name,QString &password);

    void get_user();
//更新右下角时间；
    void timerout();

    void button_status(int device_port);

    void connected_fail(Device_Name &name,QString &error);

    void disconnect_successed(Device_Name name);

    void connect_successed(Device_Name name);

    void get_button_status(Device_Name name, int device_port, ON_OFF on_off);

    void get_Max_eletric(Device_Name name,int device_port,int Max);

    void get_Min_eletric(Device_Name name,int device_port,int Min);

    void get_actual_eletric(Device_Name name,int device_port,int actual);

    void search_information(int device_port);

    void on_action_btn_triggered();

    void on_action_all_btn_triggered();

    void close_tabWidget(int index);

    //打开相关页面;
    void on_action_OverView_triggered();

    void on_action_Alarm_Status_triggered();

    void on_action_Load_Management_triggered();

    void on_action_control_triggered();

    void on_actionConfiguration_triggered();

    void on_actionScheduling_triggered();

    void on_actionLog_event_triggered();

    void set_Max_eletric(int device_port,int val);

    void set_Min_eletric(int device_port,int val);

    void set_Describe(int device_port,QString str);

    void open_configure_child(int device_port);

    void get_on_off_delay(Device_Name name,int device_port,int on_delay,int off_delay);

    void get_on_off_delay();

    void set_all_on_off(int index);

    void start_all_on_off(Device_Name name, int Is_delay, ON_OFF flag);

    void get_operation(Device_Name name,QString str);

    void get_operation(Device_Name name, QString str,QString target_name);

    //存储相关操作日志；
    void save_info_change_buzzer(int index);

    void close_buzzer();

    void on_close_btn_clicked();

signals:
    void send_to_setMaxEle(QStringList &);

    void connected_status(Device_Name &,QString &IP,int port,int row,Connected);


    //设置电流最大值；
    void set_Max_eletric(Device_Name,int device_port,int val);

    //查询电流最大值；
    void search_Max_eletric(Device_Name);

    //设置电流最小值；
    void set_Min_eletric(Device_Name,int device_port,int val);

    //设置开关状态；
    void set_on_off(Device_Name,int,ON_OFF);

    //查询开关状态；
    void search_on_off(Device_Name);

    void search_device_information(Device_Name,int device_port);

    //更新tabwidget的实时电流；
    void send_real_eletric(int device_port,int val);

    //更新tabwidget开关状态；
    void send_on_off_status(int device_port,ON_OFF status);

    //更新tabwidget电流最大值；
    void send_Max_eletric(int device_port,int val);

    //更新tabwidget电流最小值；
    void send_Min_eletric(int device_port,int val);

    //更新tabwidget表格大小；
    void send_row(int row);

    //更新tabwidget表格名称；
    void send_name(Device_Name name);

    //更新tabwidget的端口描述信息；
    void send_Describe(int device_port,QString str);

    void all_btn_on_off(Device_Name name,int Is_delay,ON_OFF on_off);

    void change_name(Device_Name name,int row,QList<int> ele_max);

    //Outlet_configuration 更新数据；
    void send_Control_configuration_Device_Name(Device_Name name);

    void send_Control_configuration_row(int row);

    void send_Control_configuration_on_delay(int device_port,int on_delay);

    void send_Control_configuration_off_delay(int device_port,int off_delay);

    void send_display_operation(Device_Name,QString str);

    void send_display_operation(Device_Name,QString str,QString target_name);

    void save_info(Device_Name,QString);


private:
    Ui::MainWindow *ui;

    QLabel *label_bar_url;
    QLabel *label_device_name_bar;
    QLabel *label_ip_bar;
    QLabel *label_time_bar;

    QTimer *timer;

    QTreeWidgetItem *item;
    QTreeWidgetItem *top_item;

    QMenu *device_child_menu;

    QAction *action_fold;
    QAction *action_add_device;
    QAction *action_del_device;

    QAction *action_connect;
    QAction *action_disconnect;
    QAction *action_change_net;
    QAction *action_rename;

    QMap<QString,Device_Info*> device_info;
    Device_Info *d_info;   //新添加的设备信息；

    QPixmap pix_on;
    QPixmap pix_off;

    Add_device *add_device;

    QMap<QString,QString> userinfo;

    UserInfo d_userinfo;

    LogicAction *logicAction;

    Curve_Widget *curve_widget;

    QTabWidget *tabWidget;

    Alarm_Status *alarm_status;
    Home *home;
    Control *control;
    LoadManagement *loadManagement;
    Outlet_Configuration *outlet_configuration;
    Scheduling *scheduling;
    Log_Event *log_event;

    Outlet_configure_child *outlet_configure_child;
    Control_Confirmation *control_confirmation;
};

#endif // MAINWINDOW_H
