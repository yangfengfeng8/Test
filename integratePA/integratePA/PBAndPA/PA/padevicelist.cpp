#include "padevicelist.h"
#include "ui_padevicelist.h"
#include "paPortName.h"
#include "pabase.h"

#include <QStyleFactory>
#include <QRegExp>
#include <QDebug>
#include <QProcess>
#include <QFile>

PADeviceList::PADeviceList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PADeviceList)
{
    ui->setupUi(this);

    initPADeviceList();
}

PADeviceList::~PADeviceList()
{
    delete ui;
}

void PADeviceList::initPADeviceList()
{
    initTreeWidget();

    initTableWidget();

    initAddDevice();

    initPAPortName();

    getDeviceList();
}

void PADeviceList::initTreeWidget()
{
    treeWidget  = ui->treeWidget;
    treeWidget->setStyle(QStyleFactory::create("windows"));
    treeWidget->setHeaderLabels(QStringList() << QString("Device List") << QString("Status"));
    treeWidget->setHeaderHidden(true);

    treeWidget->setColumnWidth(0,150);

    topItem = new QTreeWidgetItem(treeWidget);
    topItem->setText(0,QString("Device list"));
    topItem->setText(1,QString("Status"));

    treeWidget->expandAll();

    createContextMenu();
}

void PADeviceList::initTableWidget()
{
    tableWidget = ui->tableWidget;
    tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    tableWidget->setFocusPolicy(Qt::NoFocus);
}

void PADeviceList::createContextMenu()
{
    treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);

    menu   = new QMenu(this);

    actionConnect   = menu->addAction(QString("Connect"),this,SLOT(connectDevice()));
    actionDisconnect    = menu->addAction(QString("Disconnect"),this,SLOT(disconnectDevice()));

    menu->addSeparator();

    actionAddDevice = menu->addAction(QString("Add device"),this,SLOT(addDevice()));
    actionDeldevice = menu->addAction(QString("Delete device"),this,SLOT(deleteDevice()));

    menu->addSeparator();

    actionPing  = menu->addAction(QString("Ping"),this,SLOT(pingDevice()));
    actionReboot    = menu->addAction(QString("Reboot"),this,SLOT(rebootDevice()));
    actionPortName  = menu->addAction(QString("Port naming"),this,SLOT(portNameDevice()));

    setActionEnable(false);
}

void PADeviceList::initAddDevice()
{
    pAAddDevice = new PAAddDevice(this);
    connect(pAAddDevice,SIGNAL(readyIP(QString)),this,SLOT(dectionIP(QString)));
    connect(pAAddDevice,SIGNAL(errors(QString)),this,SIGNAL(errors(QString)));
    pAAddDevice->hide();
}

void PADeviceList::initPAPortName()
{
    paPortName  = new PAPortName(this);
    connect(this,SIGNAL(getDevicePortNameForPAPortName(QString)),paPortName,SLOT(setPortName(QString)));
    connect(paPortName,SIGNAL(changePortName(QString)),this,SIGNAL(changeDevicePortNameForTab(QString)));

    paPortName->hide();
}

//显示右键菜单；
void PADeviceList::on_treeWidget_customContextMenuRequested(const QPoint &pos)
{
    QTreeWidgetItem *item   = treeWidget->itemAt(pos);
    if((item != NULL) && (item->parent() != 0)){
        changeItem(item);
    }
    changeContextMenuStatus();
    menu->exec(QCursor::pos());
}

void PADeviceList::changeContextMenuStatus()
{
    setActionEnable(topItem->childCount() != 0);
    if(topItem->childCount() > 0){
        actionConnect->setEnabled(currentItem->text(1) == "disconnect");
        actionDisconnect->setEnabled(currentItem->text(1) == "connect");
    }
}

void PADeviceList::changeItem(QTreeWidgetItem *item)
{
    currentItem = item;
    emit changeCurrentIPForMainWindow(item->text(0));
    emit changeCurrentStatus(item->text(1));
}

void PADeviceList::setActionEnable(bool Bool)
{
    actionDeldevice->setEnabled(Bool);
    actionConnect->setEnabled(Bool);
    actionDisconnect->setEnabled(Bool);
    actionPing->setEnabled(Bool);
    actionReboot->setEnabled(Bool);
    actionPortName->setEnabled(Bool);
}

void PADeviceList::setTreeWidgetColor(QColor Color, QTreeWidgetItem *Item)
{
    Item->setForeground(0,Color);
    Item->setForeground(1,Color);
}

QTreeWidgetItem *PADeviceList::addTreeWidgetItem(QString IP, QString Status)
{
    QTreeWidgetItem *item   = new QTreeWidgetItem;
    item->setText(0,IP);
    item->setText(1,Status);
    return item;
}

//连接设备；
void PADeviceList::connectDevice()
{
    emit connectDeviceForTab(currentItem->text(0));
}

//断开连接；
void PADeviceList::disconnectDevice()
{
    emit disconnectDeviceForTab(currentItem->text(0));

    setTreeWidgetColor(QColor(Qt::black),currentItem);
    currentItem->setText(1,QString("disconnect"));
    changeItem(currentItem);
}

//添加设备;
void PADeviceList::addDevice()
{
    pAAddDevice->exec();
}

//删除设备；
void PADeviceList::deleteDevice()
{
    emit deleteDeviceForTab(currentItem->text(0));
    topItem->removeChild(currentItem);
    if(topItem->childCount() > 0){
        changeItem(topItem->child(0));
        if(currentItem->text(1) == "connect"){
            connectDevice();
        }
    }
}

//ping设备；
void PADeviceList::pingDevice()
{
    QProcess process;
    process.startDetached(QString("ping %1 -t").arg(currentItem->text(0)));
    process.waitForStarted();
    process.waitForFinished();
}

//重启设备；
void PADeviceList::rebootDevice()
{
    emit rebootDeviceForTab(currentItem->text(0));
}

//设备断开重命名；
void PADeviceList::portNameDevice()
{
    emit searchDevicePortNameForTab(currentItem->text(0));
    paPortName->exec();
}

void PADeviceList::dectionIP(const QString &IP)
{
    if(isExists(IP)){
        emit errors(QString("Add device failed: IP address already exists. Please enter again."));
        return ;
    }
    emit connectDeviceForTab(IP);
}

void PADeviceList::connectSuccess(const QString &IP)
{
    if(isExists(IP)){
        setTreeWidgetColor(QColor(Qt::blue),currentItem);
        currentItem->setText(1,QString("connect"));
        changeItem(currentItem);
        return ;
    }
    changeItem(addTreeWidgetItem(IP,QString("connect")));
    setTreeWidgetColor(QColor(Qt::blue),currentItem);
    topItem->addChild(currentItem);
}

void PADeviceList::disconnectSuccess(const QString &IP)
{
    if(currentItem->text(0) != IP){
        return ;
    }
    setTreeWidgetColor(QColor(Qt::black),currentItem);
    currentItem->setText(1,QString("disconnect"));
    changeItem(currentItem);
}

bool PADeviceList::isExists(QString IP)
{
    for(int i=0;i<topItem->childCount();i++){
        if(IP == topItem->child(i)->text(0)){
            return true;
        }
    }
    return false;
}

void PADeviceList::saveDeviceList()
{
    QString str;
    if(createPADeviceList()){
        QFile file("./PA/device.ini");
        if(!file.open(QIODevice::WriteOnly)){
            qDebug()<<file.errorString();
        }
        QTextStream in(&file);
        for(int i = 0; topItem->childCount(); i++){
            str += topItem->text(i) + QString("\n");
            in << str;
            str.clear();
        }
        file.close();
    }
}

bool PADeviceList::createPADeviceList()
{
    dir.setCurrent(QDir::currentPath());
    if(!dir.exists("./PA")){
        if(!dir.mkdir("PA")){
            return false;
        }
    }
    return true;
}

void PADeviceList::getDeviceList()
{
    QFile file("./PA/device.ini");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<file.errorString();
    }
    QString str;
    QTextStream out(&file);
    while(!out.atEnd()){
        str = out.readLine();
        tableWidget->item(4,1)->setText(str);
        str.clear();
    }
    file.close();
}

//更新表格数据；
void PADeviceList::displayData(const QStringList &List)
{
    updateDeviceType(List);
}

void PADeviceList::updateDeviceType(QStringList List)
{

}

void PADeviceList::on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    column  = column;
    changeItem(item);
    if(currentItem->parent() == 0){
        return ;
    }
    connectDevice();
}

//从底层获取数据类型；
void PADeviceList::getDeviceType(const QString &Firmware)
{
    if (Firmware == QString("HBTE-PA-4-4-4-127-0.5")){
        paPortName->setTable(currentItem->text(0),QString("4-4"));
    }
    else if (Firmware == QString("HBTE-PA-5-5-4-127-0.5")){
        paPortName->setTable(currentItem->text(0),QString("5-5"));
    }
    else if (Firmware == QString("HBTE-PA-8-8-4-127-0.5")){
        paPortName->setTable(currentItem->text(0),QString("8-8"));
    }
    else if (Firmware == QString("HBTE-PA-8-8-4-60-0.5")){
        paPortName->setTable(currentItem->text(0),QString("8-8"));
    }
    else if(Firmware == QString("HBTE-PA-8-2-4-127-0.5")){
        paPortName->setTable(currentItem->text(0),QString("8-2"));
    }
    else if (Firmware == QString("HBTE-PA-16-2-4-127-0.5")){
        paPortName->setTable(currentItem->text(0),QString("16-2"));
    }
    else if (Firmware == QString("HBTE-PA-16-3-3.8-127-1")){
        paPortName->setTable(currentItem->text(0),QString("16-3"));
    }
    else if (Firmware == QString("HBTE-PA-16-4-4-127-0.5")){
        paPortName->setTable(currentItem->text(0),QString("16-4"));
    }
    else if (Firmware == QString("HBTE-PA-32-32-4-127-0.5")){
        paPortName->setTable(currentItem->text(0),QString("32-32"));
    }
    else if (Firmware == QString("HBTE-PAM-8*8-4-60-0.5")){
        paPortName->setTable(currentItem->text(0),QString("8*8"));
    }
    else if (Firmware == QString("HBTE-PAM-8*8-4-63-0.5")){
        paPortName->setTable(currentItem->text(0),QString("8*8"));
    }
    else if (Firmware == QString("HBTE-PAM-8*8-4-90-0.5")){
        paPortName->setTable(currentItem->text(0),QString("8*8"));
    }
    else if (Firmware == QString("HBTE-PAM-16*8-4-60-0.5")){
        paPortName->setTable(currentItem->text(0),QString("16*8"));
    }
    else if (Firmware == QString("HBTE-PAM-16*8-4-63-0.5")){
        paPortName->setTable(currentItem->text(0),QString("16*8"));
    }
    else if (Firmware == QString("HBTE-PAM-16*8-4-90-0.5")){
        paPortName->setTable(currentItem->text(0),QString("16*8"));
    }
    else if (Firmware == QString("HBTE-PAM-16*16-4-60-0.5")){
        paPortName->setTable(currentItem->text(0),QString("16*16"));
    }
    else if (Firmware == QString("HBTE-PAM-16*16-4-63-0.5")){
        paPortName->setTable(currentItem->text(0),QString("16*16"));
    }
    else if (Firmware == QString("HBTE-PAM-16*16-4-90-0.5")){
        paPortName->setTable(currentItem->text(0),QString("16*16"));
    }
    else if (Firmware == QString("HBTE-PAM-32*16-4-63-0.5")){
        paPortName->setTable(currentItem->text(0),QString("32*16"));
    }
    else if (Firmware == QString("HBTE-PAM-32*32-4-60-0.5")){
        paPortName->setTable(currentItem->text(0),QString("32*32"));
    }
}

void PADeviceList::closed()
{
    saveDeviceList();
}












PAAddDevice::PAAddDevice(QWidget *parent)
{
    initPAAddDevice();
}

PAAddDevice::~PAAddDevice()
{

}

void PAAddDevice::initPAAddDevice()
{
    labelIP = new QLabel(this);
    labelIP->setText(QString("Device IP:"));
    labelIP->setAlignment(Qt::AlignRight | Qt::AlignCenter);
    labelIP->setMinimumWidth(60);
    labelIP->setMaximumWidth(60);

    lineEditIP  = new QLineEdit(this);
    lineEditIP->setMinimumHeight(30);

    labelType   = new QLabel(QString("Type:"),this);
    labelType->setAlignment(Qt::AlignRight | Qt::AlignCenter);
    labelType->setMinimumWidth(60);
    labelType->setMaximumWidth(60);

    lineEditType    = new QLineEdit(this);
    lineEditType->setMinimumHeight(30);
    lineEditType->setReadOnly(true);
    lineEditType->setText(QString("Programmable attenuation/matrix"));

    btnConnect  = new QPushButton(this);
    btnConnect->setText(QString("Connect"));
    btnConnect->setMinimumHeight(25);
    btnConnect->setMaximumHeight(25);
    btnConnect->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    connect(btnConnect,SIGNAL(clicked(bool)),this,SLOT(connectClicked()));

    btnCancel   = new QPushButton(this);
    btnCancel->setText(QString("Cancel"));
    btnCancel->setMinimumHeight(25);
    btnCancel->setMaximumHeight(25);
    btnCancel->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    connect(btnCancel,SIGNAL(clicked(bool)),this,SLOT(cancelClicked()));

    setMinimumSize(378,150);
    setMaximumSize(378,150);

    initLayout();

    setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);

    setWindowTitle(QString("%1").arg(Version));
}

void PAAddDevice::initLayout()
{
    QHBoxLayout *h_layout1  = new QHBoxLayout;
    h_layout1->addWidget(labelIP);
    h_layout1->addWidget(lineEditIP);
    h_layout1->setContentsMargins(0,0,0,0);
    h_layout1->setSpacing(6);

    QHBoxLayout *h_layout2  = new QHBoxLayout;
    h_layout2->addWidget(labelType);
    h_layout2->addWidget(lineEditType);
    h_layout2->setContentsMargins(0,0,0,0);
    h_layout2->setSpacing(6);

    QHBoxLayout *h_layout3  = new QHBoxLayout;
    h_layout3->addWidget(btnConnect);
    h_layout3->addWidget(btnCancel);
    h_layout3->setContentsMargins(0,0,0,0);
    h_layout3->setSpacing(6);

    QVBoxLayout *v_layout   = new QVBoxLayout;
    v_layout->addLayout(h_layout1);
    v_layout->addLayout(h_layout2);
    v_layout->addLayout(h_layout3);

    setLayout(v_layout);
}

bool PAAddDevice::checkIPFormat(const QString IP)
{
    QRegExp rx("((2[0-4]\\d|25[0-5]|[01]?\\d\\d?)\\.){3}(2[0-4]\\d|25[0-5]|[01]?\\d\\d?)");

    if(!rx.exactMatch(IP)){
        emit errors(QString("Wrong IP address, please input again."));
        return false;
    }
    return true;
}

void PAAddDevice::connectClicked()
{
    if(lineEditIP->text().isEmpty()){
        emit errors(QString("Wrong IP address, please input again."));
        this->reject();
        return ;
    }
    if(!checkIPFormat(lineEditIP->text())){
        return ;
    }
    emit readyIP(lineEditIP->text());
    this->accept();
}

void PAAddDevice::cancelClicked()
{
    lineEditIP->clear();
    this->reject();
}

