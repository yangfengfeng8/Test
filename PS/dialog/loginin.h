#ifndef LOGININ_H
#define LOGININ_H

#include <QWidget>
#include <QDialog>
#include <QMap>

class QLabel;
class QLineEdit;
class QSharedMemory;

class LoginIn : public QDialog
{
    Q_OBJECT
public:
    LoginIn(QWidget *parent = 0);

    bool check_valid();

    void get_UserInfo();

    void loadFromSharedMem();

public slots:
    void Login_Ok_btn();

    void Login_Cancle_btn();

signals:
    void login_user(QString &,QString &);

private:
    QLabel *label_name;
    QLabel *label_psd;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_psd;

    QMap<QString,QString> userInfo;
    QSharedMemory *share_userinfo;

    QString name;
    QString psd;
};

#endif // LOGININ_H
