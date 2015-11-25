#ifndef RENAME_H
#define RENAME_H

#include "base.h"

class Rename : public QDialog
{
    Q_OBJECT
public:
    Rename(QMap<QString,Device_Info *> device_info,QWidget *parent = 0);
    ~Rename(){}

public slots:
    void Rename_Ok_btn_slot();
    void Rename_Cancle_btn_slot();
    void combobox_change_slot(int);

signals:
    void rename(QString &,QString &,QStringList&);

private:
    QList<QLineEdit*> list;
    QList<QLabel*> label;
    QList<int> row;
    int index;
    QStringList name;
    QVBoxLayout *v_layout;
    QMap<QString,Device_Info*> device_info;
};

#endif // RENAME_H
