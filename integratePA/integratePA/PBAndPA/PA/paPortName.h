#ifndef PAPortName_H
#define PAPortName_H

#include <QDialog>
#include <QStandardItemModel>
#include <QTimer>

namespace Ui {
class PAPortName;
}

class PAPortName : public QDialog
{
    Q_OBJECT

public:
    explicit PAPortName(QWidget *parent = 0);
    ~PAPortName();

    int  setTable(QString strMsgIp, QString strMsgEqu);
    void initModel(QString,int,int);
    void clearTable();

private slots:
    void onExprtPubClicked();
    void onImportPubClicked();
    void onOKPubClicked();
    void onClearPubClicked();
    void showLater();    

    void setPortName(const QString &strRecv);

signals:
    void changePortName(const QString&);

private:
    Ui::PAPortName *ui;
    QStandardItemModel *modelIn;
    QStandardItemModel *modelOut;
    QStringList m_HexIn,m_HexOut;
    int m_in,m_out;
    QString m_strEqu;
};

#endif // PAPortName_H
