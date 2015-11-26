#ifndef CONTROL_H
#define CONTROL_H

#include <QWidget>
#include "base.h"

class QLabel;
class QPushButton;
class QTableWidgetItem;
class QAbstractItemModel;

namespace Ui {
class Control;
}

class Control : public QWidget
{
    Q_OBJECT

public:
    explicit Control(QWidget *parent = 0);
    ~Control();

    void Init_tabWidget(int row = 4, int column = 9);

private slots:
    void on_Control_All_Trigger_clicked();

    void on_Control_All_ComboBox_currentIndexChanged(int index);

    void on_control_tableWidget_itemChanged(QTableWidgetItem *item);

    void get_Max(int device_port,int val);

    void get_Min(int device_port,int val);

    void get_Describe(int device_port,QString str);

    void get_btn_status(int device_port, ON_OFF status);

    void get_real_eletric(int device_port,int real_eletric);

    void get_row(int row);

signals:
    void set_Max(int device_port,int val);

    void set_Min(int device_port,int val);

    void set_Describe(int device_port,QString str);

    void set_btn_status(int device_port);

    void search_btn_status(int device_port);

    void modification(int device_port);

    void set_all_on_off(int status);

private:
    Ui::Control *ui;

    int row;
    int column;
    int index;
    QMap<int,double> max;
    QMap<int,double> min;

    QPixmap pix_on;
    QPixmap pix_off;
    QAbstractItemModel *model;
};

#endif // CONTROL_H
