#include "adduser.h"
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QTimer>
#include <QDebug>

AddUser::AddUser(QWidget *parent)
    : QDialog(parent)
{
    Label_username  = new QLabel(this);
    Label_username->setText(tr("用户名："));

    LineEdit_username   = new QLineEdit(this);
    LineEdit_username->setPlaceholderText(tr("请输入用户名"));

    Label_psd   = new QLabel(this);
    Label_psd->setText(tr("密码："));

    LineEdit_psd    = new QLineEdit(this);
    LineEdit_psd->setPlaceholderText(tr("请输入6-8位密码"));
    connect(LineEdit_psd,SIGNAL(textChanged(QString)),this,SLOT(sltDisplayLast(QString)));
    LineEdit_psd->setMaxLength(8);

    timer   = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(sltDisplayStr()));

    Label_confire_psd   = new QLabel(this);
    Label_confire_psd->setText(tr("确认密码："));

    LineEdit_confire_psd    = new QLineEdit(this);
    LineEdit_confire_psd->setPlaceholderText(tr("请再次输入密码"));
    connect(LineEdit_confire_psd,SIGNAL(textChanged(QString)),this,SLOT(sltDisplayLast_confire(QString)));
    LineEdit_confire_psd->setMaxLength(8);

    timer2  = new QTimer(this);
    connect(timer2,SIGNAL(timeout()),this,SLOT(sltDisplayStr_confire()));

    QVBoxLayout *v_layout1  = new QVBoxLayout;
    v_layout1->addWidget(Label_username);
    v_layout1->addSpacing(10);
    v_layout1->addWidget(Label_psd);
    v_layout1->addSpacing(10);
    v_layout1->addWidget(Label_confire_psd);

    QVBoxLayout *v_layout2  = new QVBoxLayout;
    v_layout2->addWidget(LineEdit_username);
    v_layout2->addSpacing(10);
    v_layout2->addWidget(LineEdit_psd);
    v_layout2->addSpacing(10);
    v_layout2->addWidget(LineEdit_confire_psd);

    QHBoxLayout *h_layout   = new QHBoxLayout;
    h_layout->addLayout(v_layout1);
    h_layout->addSpacing(20);
    h_layout->addLayout(v_layout2);

    QPushButton *Ok_btn      = new QPushButton(tr("确定"));
    Ok_btn->resize(60,40);
    Ok_btn->setMinimumSize(50,35);
    Ok_btn->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    Ok_btn->setFocus();
    connect(Ok_btn,SIGNAL(clicked()),this,SLOT(AddUser_Ok_btn()));
    QPushButton *Cancle_btn  = new QPushButton(tr("取消"));
    Cancle_btn->resize(50,35);
    Cancle_btn->setMinimumSize(50,35);
    Cancle_btn->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    connect(Cancle_btn,SIGNAL(clicked()),this,SLOT(AddUser_Cancle_btn()));

    QHBoxLayout *h_layout1  = new QHBoxLayout;
    h_layout1->addWidget(Ok_btn);
    h_layout1->addSpacing(20);
    h_layout1->addWidget(Cancle_btn);

    QVBoxLayout *v_layout3  = new QVBoxLayout;
    v_layout3->addLayout(h_layout);
    v_layout3->addSpacing(10);
    v_layout3->addLayout(h_layout1);

    setLayout(v_layout3);

    setWindowTitle(tr("添加用户"));
}

void AddUser::sltDisplayLast(const QString &str)
{
    timer->stop();

    if(str.length() > psd.length()){
        psd += str.right(1);
    }
    else {
        psd.remove(psd.length()-1,1);
    }

    QString temp;
    for(int i=0;i<str.length()-1;i++){
        temp    += "*";
    }
    temp += str.right(1);
    disconnect(LineEdit_psd,SIGNAL(textChanged(QString)),this,SLOT(sltDisplayLast(QString)));
    LineEdit_psd->setText(temp);
    connect(LineEdit_psd,SIGNAL(textChanged(QString)),this,SLOT(sltDisplayLast(QString)));

    timer->start(500);
}

void AddUser::sltDisplayStr()
{
    timer->stop();
    QString temp;
    for(int i=0;i<psd.length();i++){
        temp    += "*";
    }
    disconnect(LineEdit_psd,SIGNAL(textChanged(QString)),this,SLOT(sltDisplayLast(QString)));
    LineEdit_psd->setText(temp);
    connect(LineEdit_psd,SIGNAL(textChanged(QString)),this,SLOT(sltDisplayLast(QString)));
}

void AddUser::sltDisplayLast_confire(const QString &str)
{
    timer2->stop();

    if(str.length() > psd_again.length()){
        psd_again += str.right(1);
    }
    else {
        psd_again.remove(psd_again.length()-1,1);
    }

    QString temp;
    for(int i=0;i<str.length()-1;i++){
        temp    += "*";
    }
    temp += str.right(1);
    disconnect(LineEdit_confire_psd,SIGNAL(textChanged(QString)),this,SLOT(sltDisplayLast_confire(QString)));
    LineEdit_confire_psd->setText(temp);
    connect(LineEdit_confire_psd,SIGNAL(textChanged(QString)),this,SLOT(sltDisplayLast_confire(QString)));

    timer2->start(500);
}

void AddUser::sltDisplayStr_confire()
{
    timer2->stop();
    QString temp;
    for(int i=0;i<psd_again.length();i++){
        temp    += "*";
    }
    disconnect(LineEdit_confire_psd,SIGNAL(textChanged(QString)),this,SLOT(sltDisplayLast_confire(QString)));
    LineEdit_confire_psd->setText(temp);
    connect(LineEdit_confire_psd,SIGNAL(textChanged(QString)),this,SLOT(sltDisplayLast_confire(QString)));
}

void AddUser::AddUser_Ok_btn()
{
    QString name;
    name    = LineEdit_username->text();
    if(name.isEmpty() || psd.isEmpty() || psd_again.isEmpty()){
        QMessageBox::warning(this,tr("添加失败"),tr("用户名、密码不能为\n空，请重试！！！"));
        return ;
    }
    if(psd != psd_again){
        QMessageBox::warning(this,tr("添加失败"),tr("两次输入的密码不\n一致，请重试！！！"));
        return ;
    }
    if(psd.length() < 6){
        QMessageBox::warning(this,tr("添加失败"),tr("输入密码的长度不得小于6，请重试！！！"));
        return ;
    }
    emit userInfo(name,psd);
    accept();
}

void AddUser::AddUser_Cancle_btn()
{
    reject();
}

