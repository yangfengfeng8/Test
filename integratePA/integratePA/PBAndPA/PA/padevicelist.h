#ifndef PADEVICELIST_H
#define PADEVICELIST_H

#include <QWidget>
#include <QMenu>
#include <QTreeWidget>
#include <QTableWidget>
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QDir>

class PAPortName;


class PAAddDevice : public QDialog
{
    Q_OBJECT

public:
    explicit PAAddDevice(QWidget *parent = 0);
    ~PAAddDevice();

    void initPAAddDevice();

    void initLayout();

    bool checkIPFormat(const QString IP);

signals:
    void readyIP(const QString &);

    void errors(const QString &);

public slots:
    void connectClicked();
    void cancelClicked();

private:
    QLabel *labelIP;
    QLabel *labelType;
    QLineEdit *lineEditIP;
    QLineEdit *lineEditType;

    QPushButton *btnConnect;
    QPushButton *btnCancel;
};


namespace Ui {
class PADeviceList;
}

class PADeviceList : public QWidget
{
    Q_OBJECT

public:
    explicit PADeviceList(QWidget *parent = 0);
    ~PADeviceList();

    void initPADeviceList();

    void initTreeWidget();

    void initTableWidget();

    void initLayout();

    void createContextMenu();

    void initAddDevice();

    void initPAPortName();

    void changeContextMenuStatus();

    void changeItem(QTreeWidgetItem *item);

    void setActionEnable(bool Bool);

    bool isExists(QString IP);

    void setTreeWidgetColor(QColor Color,QTreeWidgetItem *Item);

    QTreeWidgetItem* addTreeWidgetItem(QString IP,QString Status);

    void displayData(const QStringList &List);

    void saveDeviceList();

    bool createPADeviceList();

    void getDeviceList();

public slots:
    void connectDevice();

    void disconnectDevice();

    void addDevice();

    void deleteDevice();

    void pingDevice();

    void rebootDevice();

    void portNameDevice();

    void dectionIP(const QString &IP);

    void connectSuccess(const QString &IP);

    void disconnectSuccess(const QString &IP);

    void updateDeviceType(QStringList List);

    void getDeviceType(const QString &Firmware);

    void closed();

signals:
    void changeCurrentIPForMainWindow(QString IP);
    void changeCurrentStatus(QString Status);

    void errors(const QString &);

    void connectDeviceForTab(const QString &IP);
    void disconnectDeviceForTab(const QString &IP);
    void deleteDeviceForTab(const QString &IP);
    void rebootDeviceForTab(const QString &IP);
    void searchDevicePortNameForTab(const QString &IP);
    void changeDevicePortNameForTab(const QString &);

    void getDevicePortNameForPAPortName(const QString &);


private slots:
    void on_treeWidget_customContextMenuRequested(const QPoint &pos);

    void on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);

private:
    Ui::PADeviceList *ui;

    QMenu *menu;
    QAction *actionAddDevice;
    QAction *actionDeldevice;
    QAction *actionConnect;
    QAction *actionDisconnect;
    QAction *actionPing;
    QAction *actionReboot;
    QAction *actionPortName;

    QTreeWidgetItem *topItem;
    QTreeWidgetItem *currentItem;

    QTreeWidget *treeWidget;
    QTableWidget *tableWidget;

    PAAddDevice *pAAddDevice;

    int reNameRow;
    int reNameColumn;

    PAPortName *paPortName;

    QDir dir;
};




#endif // PADEVICELIST_H
