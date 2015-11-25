#ifndef ADDUSER_H
#define ADDUSER_H

#include <QWidget>
#include <QDialog>
class QLabel;
class QLineEdit;

class AddUser : public QDialog
{
    Q_OBJECT
public:
    AddUser(QWidget *parent = 0);

public slots:
    void sltDisplayLast(const QString &);
    void sltDisplayStr();

    void sltDisplayLast_confire(const QString &);
    void sltDisplayStr_confire();

    void AddUser_Ok_btn();
    void AddUser_Cancle_btn();

signals:
    void userInfo(QString &name,QString &password);

private:
    QLabel *Label_username;
    QLabel *Label_psd;
    QLabel *Label_confire_psd;
    QLineEdit *LineEdit_username;
    QLineEdit *LineEdit_psd;
    QLineEdit *LineEdit_confire_psd;

    QTimer *timer;
    QTimer *timer2;

    QString psd;
    QString psd_again;
};

#endif // ADDUSER_H
