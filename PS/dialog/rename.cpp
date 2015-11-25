#include "rename.h"

Rename::Rename(QMap<QString, Device_Info *> device_info, QWidget *parent)
    : QDialog(parent)
    , device_info(device_info)
{
    foreach(QString str,device_info.keys()){
        name << str;
        row  << device_info.value(str)->row();
    }

    QFont font;
    font.setPixelSize(20);
    QLabel *label_message   = new QLabel(this);
    label_message->setText(tr("当前挑选的设备："));
    label_message->setFont(font);
    QComboBox *combox   = new QComboBox(this);
    combox->addItems(name);
    combox->setFont(font);
    connect(combox,SIGNAL(currentIndexChanged(int)),this,SLOT(combobox_change_slot(int)));
    combox->setCurrentIndex(0);
    QLabel *label_device_name   = new QLabel(this);
    label_device_name->setText(tr("设备名称："));
    label_device_name->setFont(font);
    label.append(label_device_name);
    QLineEdit *lineEdit = new QLineEdit(this);
    lineEdit->setFont(font);
    lineEdit->setText(name.at(0));
    lineEdit->setFocus();
    lineEdit->selectAll();
    list.append(lineEdit);

    QHBoxLayout *h_layout   = new QHBoxLayout;
    h_layout->addWidget(label_message);
    h_layout->addSpacing(20);
    h_layout->addWidget(combox);

    QHBoxLayout *h_layout1  = new QHBoxLayout;
    h_layout1->addWidget(label_device_name);
    h_layout1->addSpacing(20);
    h_layout1->addWidget(lineEdit);
    v_layout    = new QVBoxLayout;
    v_layout->addLayout(h_layout);
    v_layout->addSpacing(10);
    v_layout->addLayout(h_layout1);

    for(int i=0;i<8;i++){
        QLabel *label   = new QLabel(this);
        label->setText(tr("port%1 :").arg(i+1));
        label->setFont(font);
        this->label.append(label);
        QLineEdit *lineEdit = new QLineEdit(this);
        list.append(lineEdit);
        lineEdit->setFont(font);

        QHBoxLayout *h_layout    = new QHBoxLayout;
        h_layout->addWidget(label);
        h_layout->addSpacing(45);
        h_layout->addWidget(lineEdit);
        v_layout->addSpacing(10);
        v_layout->addLayout(h_layout);
    }
    for(int i=0;i<row.at(0);i++){
        list.at(i+1)->setText(device_info.value(name.at(0))->current_status(i).describe);
    }

    QPushButton *Ok_btn      = new QPushButton(tr("确定"));
    Ok_btn->resize(60,40);
    Ok_btn->setMinimumSize(50,35);
    Ok_btn->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    Ok_btn->setFocus();
    connect(Ok_btn,SIGNAL(clicked()),this,SLOT(Rename_Ok_btn_slot()));
    QPushButton *Cancle_btn  = new QPushButton(tr("取消"));
    Cancle_btn->resize(50,35);
    Cancle_btn->setMinimumSize(50,35);
    Cancle_btn->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    connect(Cancle_btn,SIGNAL(clicked()),this,SLOT(Rename_Cancle_btn_slot()));

    QHBoxLayout *h_layout2   = new QHBoxLayout;
    h_layout2->addWidget(Ok_btn);
    h_layout2->addSpacing(20);
    h_layout2->addWidget(Cancle_btn);
    v_layout->addLayout(h_layout2);

    setLayout(v_layout);

    setMaximumSize(420,500);
    setMinimumSize(420,500);

    combobox_change_slot(0);
}

void Rename::Rename_Ok_btn_slot()
{
    QString oldName;
    oldName = name.at(index);
    QString newName;
    newName = list.at(0)->text();
    if(newName.isEmpty()){
        QMessageBox::warning(this,tr("输入错误"),tr("输入设备名为空，请确认后再次输入！"));
        this->reject();
        return ;
    }
    if(newName != oldName){
        if((device_info.find(newName) != device_info.end()) && (device_info.find(newName).key() == newName)){
            QMessageBox::warning(this,tr("输入错误"),tr("设备名%1已存在，请重新输\n入新的设备名!").arg(newName));
            this->reject();
            return ;
        }
    }
    QStringList str;

    for(int i=0;i<row.at(index);i++){
        str << list.at(i+1)->text();
    }

    emit rename(newName,oldName,str);
    this->accept();
}

void Rename::Rename_Cancle_btn_slot()
{
    this->reject();
}

void Rename::combobox_change_slot(int index)
{
    this->index = index;
    if(row.at(index) > 6){
        list.at(7)->show();
        list.at(8)->show();
        label.at(7)->show();
        label.at(8)->show();
    }
    else if(row.at(index) == 6){
        list.at(7)->hide();
        list.at(8)->hide();
        label.at(7)->hide();
        label.at(8)->hide();
    }
    for(int i=0;i<row.at(index);i++){
        list.at(i+1)->setText(device_info.value(name.at(index))->current_status(i).describe);
    }
    list.at(0)->setText(name.at(index));
    list.at(0)->setFocus();
    list.at(0)->selectAll();
}
