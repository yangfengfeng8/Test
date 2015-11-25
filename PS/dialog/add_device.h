#ifndef ADD_DEVICE_H
#define ADD_DEVICE_H

#include <QDialog>
class QLabel;
class QLineEdit;
class QComboBox;

enum Device_Type{EIGHTIN_EIGHTOUT,ONEIN_SIXOUT,SIXIN_SIXOUT};

typedef struct {
    QString name;
    QString IP;
    QString Port;
    Device_Type index;
}Device_data;

class Add_device : public QDialog
{
    Q_OBJECT
public:
    Add_device(QWidget *parent = 0);

    bool check_IP(const QString ip);

public slots:

    void add_device_OK_slot();

    void add_device_Cancle_slot();

signals:
    void data(Device_data&);

private:
    QLabel *device_name;
    QLabel *IP_Address;
    QLabel *IP_Port;
    QLabel *Number;

    QLineEdit *Input_name;
    QLineEdit *Input_IP;
    QLineEdit *Input_Port;
    QComboBox *Input_Num;
};

#endif // ADD_DEVICE_H
