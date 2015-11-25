#include "all_btn.h"

All_btn::All_btn(QList<Device_Name> name, QWidget *parent) : QDialog(parent),name(name),name_index(0),on_off_index(0)
{
    QFont font;
    font.setPointSize(15);
    setFont(font);
    label_name  = new QLabel(tr("设备 名称："),this);
    label_on_off    = new QLabel(tr("开关 状态："),this);
    label_interval  = new QLabel(tr("时间间隔(s):"),this);

    combobox_name   = new QComboBox(this);
    combobox_name->addItems(name);
    connect(combobox_name,SIGNAL(currentIndexChanged(int)),this,SLOT(combobox_name_currentIndex(int)));

    combobox_on_off = new QComboBox(this);
    combobox_on_off->addItem(tr("断开"));
    combobox_on_off->addItem(tr("闭合"));
    connect(combobox_on_off,SIGNAL(currentIndexChanged(int)),this,SLOT(combobox_on_off_currentIndex(int)));

    spinbox_interval    = new QSpinBox(this);
    spinbox_interval->setMinimum(1);
    spinbox_interval->setMaximum(65536);

    QVBoxLayout *v_layout1  = new QVBoxLayout;
    v_layout1->addWidget(label_name);
    v_layout1->addSpacing(10);
    v_layout1->addWidget(label_on_off);
    v_layout1->addSpacing(10);
    v_layout1->addWidget(label_interval);

    QVBoxLayout *v_layout2  = new QVBoxLayout;
    v_layout2->addWidget(combobox_name);
    v_layout2->addSpacing(10);
    v_layout2->addWidget(combobox_on_off);
    v_layout2->addSpacing(10);
    v_layout2->addWidget(spinbox_interval);

    QHBoxLayout *h_layout   = new QHBoxLayout;
    h_layout->addLayout(v_layout1);
    h_layout->addSpacing(20);
    h_layout->addLayout(v_layout2);

    QPushButton *Ok_btn      = new QPushButton(tr("确定"));
    Ok_btn->resize(60,40);
    Ok_btn->setMinimumSize(50,35);
    Ok_btn->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    Ok_btn->setFocus();
    connect(Ok_btn,SIGNAL(clicked()),this,SLOT(All_ok_btn()));
    QPushButton *Cancle_btn  = new QPushButton(tr("取消"));
    Cancle_btn->resize(50,35);
    Cancle_btn->setMinimumSize(50,35);
    Cancle_btn->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    connect(Cancle_btn,SIGNAL(clicked()),this,SLOT(All_Cancle_btn()));

    QHBoxLayout *h_layout1  = new QHBoxLayout;
    h_layout1->addWidget(Ok_btn);
    h_layout1->addSpacing(20);
    h_layout1->addWidget(Cancle_btn);

    QVBoxLayout *v_layout   = new QVBoxLayout;
    v_layout->addLayout(h_layout);
    v_layout->addSpacing(10);
    v_layout->addLayout(h_layout1);
    setLayout(v_layout);

    setMaximumSize(300,260);
    setMinimumSize(300,260);

    setWindowTitle(tr("设置%1开关状态").arg(name.at(0)));
}

void All_btn::All_ok_btn()
{
    Device_Name name    = this->name.at(name_index);
    if(on_off_index == 0){
        emit all_btn_send(name,spinbox_interval->value(),OFF);
    }
    else {
        emit all_btn_send(name,spinbox_interval->value(),ON);
    }
    this->accept();
}

void All_btn::All_Cancle_btn()
{
    this->reject();
}

void All_btn::combobox_name_currentIndex(int index)
{
    name_index  = index;
    setWindowTitle(tr("设置%1开关状态").arg(name.at(0)));
}

void All_btn::combobox_on_off_currentIndex(int index)
{
    on_off_index    = index;
}

