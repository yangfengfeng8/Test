#ifndef ALL_BTN_H
#define ALL_BTN_H

#include <QDialog>
#include <QWidget>
#include "base.h"
#include <QSpinBox>

class All_btn : public QDialog
{
    Q_OBJECT
public:
    explicit All_btn(QList<Device_Name> name,QWidget *parent = 0);
    ~All_btn(){}


signals:
    void all_btn_send(Device_Name name,int interval,ON_OFF);

public slots:
    void All_ok_btn();

    void All_Cancle_btn();

    void combobox_name_currentIndex(int index);

    void combobox_on_off_currentIndex(int index);

private:
    QLabel *label_name;
    QLabel *label_on_off;
    QLabel *label_interval;
    QComboBox *combobox_name;
    QComboBox *combobox_on_off;
    QSpinBox *spinbox_interval;
    QList<Device_Name> name;

    int name_index;
    int on_off_index;
};

#endif // ALL_BTN_H
