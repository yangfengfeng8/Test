#include "loginin.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <QSharedMemory>
#include <QBuffer>
#include <QDataStream>

LoginIn::LoginIn(QWidget *parent)
    : QDialog(parent)
{
    label_name  = new QLabel(this);
    label_name->setText(tr("用户名："));

    lineEdit_name   = new QLineEdit(this);
    lineEdit_name->setPlaceholderText(tr("请输入用户名："));

    label_psd   = new QLabel(this);
    label_psd->setText(tr("密码："));

    lineEdit_psd    = new QLineEdit(this);
    lineEdit_psd->setEchoMode(QLineEdit::Password);
    lineEdit_psd->setPlaceholderText(tr("请输入密码："));

    QVBoxLayout *v_layout   = new QVBoxLayout;
    v_layout->addWidget(label_name);
    v_layout->addSpacing(10);
    v_layout->addWidget(label_psd);

    QVBoxLayout *v_layout2  = new QVBoxLayout;
    v_layout2->addWidget(lineEdit_name);
    v_layout2->addSpacing(10);
    v_layout2->addWidget(lineEdit_psd);

    QHBoxLayout *h_layout   = new QHBoxLayout;
    h_layout->addLayout(v_layout);
    h_layout->addSpacing(20);
    h_layout->addLayout(v_layout2);

    QPushButton *Ok_btn      = new QPushButton(tr("确定"));
    Ok_btn->resize(60,40);
    Ok_btn->setMinimumSize(50,35);
    Ok_btn->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    Ok_btn->setFocus();
    connect(Ok_btn,SIGNAL(clicked()),this,SLOT(Login_Ok_btn()));
    QPushButton *Cancle_btn  = new QPushButton(tr("取消"));
    Cancle_btn->resize(50,35);
    Cancle_btn->setMinimumSize(50,35);
    Cancle_btn->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    connect(Cancle_btn,SIGNAL(clicked(bool)),this,SLOT(Login_Cancle_btn()));
    QHBoxLayout *h_layout1  = new QHBoxLayout;
    h_layout1->addWidget(Ok_btn);
    h_layout1->addSpacing(20);
    h_layout1->addWidget(Cancle_btn);

    QVBoxLayout *v_layout3  = new QVBoxLayout;
    v_layout3->addLayout(h_layout);
    v_layout3->addSpacing(10);
    v_layout3->addLayout(h_layout1);

    setLayout(v_layout3);

    get_UserInfo();

    share_userinfo  = new QSharedMemory("SHAREFILE",this);
    loadFromSharedMem();
}

bool LoginIn::check_valid()
{
    if(userInfo.isEmpty()){
        if(lineEdit_name->text() == "root" && lineEdit_psd->text() == "123456"){
            return true;
        }
        else {
            return false;
        }
    }
    else {
        int flag;
        foreach(QString str,userInfo.keys()){
            if((str == lineEdit_name->text()) && (userInfo.value(str) == lineEdit_psd->text())){
                name    = str;
                psd     = userInfo.value(str);
                flag    = 1;
                break;
            }
            else{
                flag    = 0;
            }
        }
        if(flag){
            return true;
        }
        else {
            return false;
        }
    }
}

void LoginIn::Login_Ok_btn()
{
    if(check_valid()){
        emit login_user(name,psd);
        this->accept();
    }
    else {
        if(lineEdit_name->text().isEmpty() || lineEdit_psd->text().isEmpty()){
            QMessageBox::warning(this,tr("登录失败"),tr("用户名或密码不能为空！"));
            return ;
        }
        QMessageBox::warning(this,tr("登录失败"),tr("用户名和密码不一致！"),tr("确定"));
        return ;
    }
}

void LoginIn::Login_Cancle_btn()
{
    this->reject();
}

void LoginIn::get_UserInfo()
{
    QFile file("userinfo.ini");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<file.errorString();
        qDebug()<<"123";
    }
    QTextStream out(&file);
    QStringList list;
    while(!out.atEnd()){
        QString str;
        str = out.readLine();
        list    = str.split(";");
        if(!list.at(0).isEmpty()){
            userInfo.insert(list.at(0),list.at(1));
        }
        list.clear();
    }
    file.close();
}

void LoginIn::loadFromSharedMem()
{
    if(share_userinfo->isAttached()){
        share_userinfo->detach();
    }
    QBuffer buffer;
    buffer.open(QBuffer::ReadWrite);
    QDataStream in(&buffer);
    QString str;

    in << name << psd;

    int size    = buffer.size();
    if(!share_userinfo->create(size)){
        return ;
    }
    share_userinfo->lock();
    char *to    = (char *)share_userinfo->data();
    const char *from  = buffer.data().data();
    memcpy(to,from,qMin(share_userinfo->size(),size));
    share_userinfo->unlock();
}

