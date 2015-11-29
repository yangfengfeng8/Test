#include "logicaction.h"

LogicAction::LogicAction(QObject *parent) : QObject(parent)
{

}

LogicAction::~LogicAction()
{
}

void LogicAction::connect_ready(Device_Name &name, QString &IP,int port,int row,Connected status)
{
    if(status == connected){
        QMap<Device_Name,LogicActionPrivate *>::const_iterator temp = d_info.find(name);
        if(temp != d_info.end() && temp.key() == name){
            temp.value()->get_tcpSocket()->connectToHost(IP,port);
        }
        else {
            LogicActionPrivate *logicActionPrivate = new LogicActionPrivate(name,this,row);
            d_info.insert(name,logicActionPrivate);
            connect(logicActionPrivate->get_tcpSocket(),SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));
            connect(logicActionPrivate->get_tcpSocket(),SIGNAL(disconnected()),this,SLOT(disconnected()));
            connect(logicActionPrivate->get_tcpSocket(),SIGNAL(connected()),this,SLOT(connect_success()));

            connect(logicActionPrivate,SIGNAL(return_one_on_off(Device_Name,int,ON_OFF)),this,SIGNAL(return_one_on_off(Device_Name,int,ON_OFF)));
            connect(logicActionPrivate,SIGNAL(return_one_actual_eletric(Device_Name,int,int)),this,SIGNAL(return_one_actual_eletric(Device_Name,int,int)));
            connect(logicActionPrivate,SIGNAL(return_one_Max_eletric(Device_Name,int,int)),this,SIGNAL(return_one_Max_eletric(Device_Name,int,int)));
            connect(logicActionPrivate,SIGNAL(return_operation(Device_Name,QString)),this,SIGNAL(return_operation(Device_Name,QString)));
            connect(logicActionPrivate,SIGNAL(return_operation(Device_Name,QString,QString)),this,SIGNAL(return_operation(Device_Name,QString,QString)));

            connect(this,SIGNAL(search_on_off(Device_Name)),logicActionPrivate,SLOT(search_on_off(Device_Name)));
            connect(this,SIGNAL(search_device_information(Device_Name,int)),logicActionPrivate,SLOT(search_device_information(Device_Name,int)));
            connect(this,SIGNAL(search_Max_eletric(Device_Name)),logicActionPrivate,SLOT(search_Max_eletric(Device_Name)));
            connect(this,SIGNAL(set_on_off(Device_Name,int,ON_OFF)),logicActionPrivate,SLOT(set_on_off(Device_Name,int,ON_OFF)));

            logicActionPrivate->get_tcpSocket()->connectToHost(IP,port);
        }
    }
    else if(status == ::disconnected){
        d_info.value(name)->get_tcpSocket()->abort();
    }
}

void LogicAction::displayError(QAbstractSocket::SocketError)
{
    QTcpSocket *tcpSocket   = dynamic_cast<QTcpSocket *>(this->sender());
    QString error   = tcpSocket->errorString();
    foreach(Device_Name name,d_info.keys()){
        if(d_info.value(name)->get_tcpSocket() == tcpSocket){
            d_info.remove(name);
            emit connect_error(name,error);
            return ;
        }
    }
}

void LogicAction::disconnected()
{
    QTcpSocket *tcpSocket   = dynamic_cast<QTcpSocket *>(this->sender());
    foreach(Device_Name name,d_info.keys()){
        if(d_info.value(name)->get_tcpSocket() == tcpSocket){
            d_info.remove(name);
            tcpSocket->close();
            emit disconnect_successed(name);
            return ;
        }
    }
}

void LogicAction::connect_success()
{
    QTcpSocket *tcpSocket   = dynamic_cast<QTcpSocket *>(this->sender());
    foreach(Device_Name name,d_info.keys()){
        if(d_info.value(name)->get_tcpSocket() == tcpSocket){
            emit connect_successed(name);
            return ;
        }
    }
}

LogicActionPrivate::LogicActionPrivate(Device_Name name, QObject *parent, int row)
    : QObject(parent),row(row),name(name)
{
    Init_data();
}

LogicActionPrivate::~LogicActionPrivate()
{
    tcpSocket->abort();
}

void LogicActionPrivate::Init_data()
{
    timer   = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timeout()));

    RT_timer    = new QTimer(this);
    connect(RT_timer,SIGNAL(timeout()),this,SLOT(RT_timeout()));

    max_timer   = new QTimer(this);
    connect(max_timer,SIGNAL(timeout()),this,SLOT(max_timerout()));

    btn_timer   = new QTimer(this);
    connect(btn_timer,SIGNAL(timeout()),this,SLOT(btn_timeout()));

    search_timer    = new QTimer(this);
    connect(search_timer,SIGNAL(timeout()),this,SLOT(search_timeout()));

    tcpSocket   = new QTcpSocket(this);
    connect(tcpSocket,SIGNAL(connected()),this,SLOT(connect_success()));
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readMessage()));
    connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(disconnected()));

    btn_id      = 0;
    btn_id2     = 0;
    actual_id   = 0;
    max_id      = 0;
    search_id   = 0;

    port_status = 0;
}

//02 查询各支路状态；
void LogicActionPrivate::search_one_on_off(int branch)
{
    list.clear();
    list.append(01);
    list.append(02);
    list.append(00);
    list.append(branch);
    list.append(00);
    list.append(01);
    quint16 sum = qChecksum(list,list.size());
    list.append(sum & 0xff);
    list.append((sum >> 8) & 0xff);

    for(int i=0;i<list.size();i++){
        tx[i]   = list.at(i);
    }
    if(tcpSocket->state() == QAbstractSocket::ConnectedState){
        tcpSocket->write(tx,list.size());
    }
    QString str;
    str = tr("01 02 00 %1 00 01 %2 %3").arg(branch,2,16,QLatin1Char('0')).arg(list.at(6),2,16,QLatin1Char('0')).arg(list.at(7),2,16,QLatin1Char('0'));
    emit return_operation(name,str);
}

//03 功能码代表查询实时电流；
void LogicActionPrivate::search_RT_eletric(int branch)
{
    list.clear();
    list.append(01);
    list.append(03);
    list.append(00);
    list.append(branch);
    list.append(00);
    list.append(01);
    quint16 sum = qChecksum(list,list.size());
    list.append(sum & 0xff);
    list.append((sum >> 8) & 0xff);

    for(int i=0;i<list.size();i++){
        tx[i]   = list.at(i);
    }
    if(tcpSocket->state() == QAbstractSocket::ConnectedState){
        tcpSocket->write(tx,list.size());
    }
    QString str;
    str = tr("01 03 00 %1 00 01 %2 %3").arg(branch,2,16,QLatin1Char('0')).arg(list.at(6),2,16,QLatin1Char('0')).arg(list.at(7),2,16,QLatin1Char('0'));
    emit return_operation(name,str);
}

//04 查询各支路电流最大值；
void LogicActionPrivate::search_Max_eletric(int branch)
{
    list.clear();
    list.append(01);
    list.append(04);
    list.append(00);
    list.append(branch);
    list.append(00);
    list.append(01);
    quint16 sum = qChecksum(list,list.size());
    list.append(sum & 0xff);
    list.append((sum >> 8) & 0xff);

    for(int i=0;i<list.size();i++){
        tx[i]   = list.at(i);
    }
    if(tcpSocket->state() == QAbstractSocket::ConnectedState){
        tcpSocket->write(tx,list.size());
    }
    QString str;
    tr("01 04 00 %1 00 01 %2 %3").arg(branch,2,16,QLatin1Char('0')).arg(list.at(6),2,16,QLatin1Char('0')).arg(list.at(7),2,16,QLatin1Char('0'));
    emit return_operation(name,str);
}
//06 设置电流最小值；
void LogicActionPrivate::search_Min_eletric(int branch)
{
    list.clear();
    list.append(01);
    list.append(06);
    list.append(00);
    list.append(branch);
    list.append(00);
    list.append(01);
    quint16 sum = qChecksum(list,list.size());
    list.append(sum & 0xff);
    list.append((sum >> 8) & 0xff);

    for(int i=0;i<list.size();i++){
        tx[i]   = list.at(i);
    }
    if(tcpSocket->state() == QAbstractSocket::ConnectedState){
        tcpSocket->write(tx,list.size());
    }
    QString str;
    tr("01 06 00 %1 00 01 %2 %3").arg(branch,2,16,QLatin1Char('0')).arg(list.at(6),2,16,QLatin1Char('0')).arg(list.at(7),2,16,QLatin1Char('0'));
    emit return_operation(name,str);
}

//查询设备信息；
void LogicActionPrivate::search_Device_info(Device_Name name)
{
    if(this->name != name){
        return ;
    }
    QString str;
    str = "$TA Y\r\n";
    if(tcpSocket->state() == QAbstractSocket::ConnectedState){
        tcpSocket->write(str.toLatin1().constData());
    }
}

//查询版本信息；
void LogicActionPrivate::search_version(Device_Name name)
{
    if(this->name != name){
        return ;
    }
    QString str;
    str = "$TA Q\r\n";
    if(tcpSocket->state() == QAbstractSocket::ConnectedState){
        tcpSocket->write(str.toLatin1().constData());
    }
}

//查询设备型号信息；
void LogicActionPrivate::search_Device_model(Device_Name name)
{
    if(this->name != name){
        return ;
    }
    QString str;
    str = "$TA Z\r\n";
    if(tcpSocket->state() == QAbstractSocket::ConnectedState){
        tcpSocket->write(str.toLatin1().constData());
    }
}

//查询端口名称；
void LogicActionPrivate::search_Port_Name(Device_Name name)
{
    if(this->name != name){
        return ;
    }
    QString str;
    str = "$TA W\r\n";
    if(tcpSocket->state() == QAbstractSocket::ConnectedState){
        tcpSocket->write(str.toLatin1().constData());
    }
}

//05 设置某一支路的开关状态；01 05 00 00 FF 00 8C 3A 开 01 05 00 00 00 00 CD CA 关
void LogicActionPrivate::set_on_off(Device_Name name,int branch, ON_OFF on_off)
{
    if(this->name != name){
        return ;
    }
    list.clear();
    list.append(01);
    list.append(05);
    list.append(00);
    list.append(branch);
    if(on_off == ON){
        list.append(0x0FF);
    }
    else {
        list.append(00);
    }
    list.append(00);
    quint16 sum = qChecksum(list,list.size());
    list.append(sum & 0xff);
    list.append((sum >> 8) & 0xff);

    for(int i=0;i<list.size();i++){
        tx[i]   = list.at(i);
    }
    if(tcpSocket->state() == QAbstractSocket::ConnectedState){
        tcpSocket->write(tx,list.size());
    }
    QString str;
    str = tr("01 05 00 %1 00 01 %2 %3").arg(branch,2,16,QLatin1Char('0')).arg(list.at(6),2,16,QLatin1Char('0')).arg(list.at(7),2,16,QLatin1Char('0'));
    emit return_operation(name,str);
}

void LogicActionPrivate::search_on_off(Device_Name name)
{
    if(this->name != name){
        return ;
    }
    btn_id2 = 0;
    btn_id  = 0;
    btn_timer->start(200);
}

//查询设备的一些信息；
void LogicActionPrivate::search_device_information(Device_Name name, int device_port)
{
    if(this->name != name){
        return ;
    }
    this->device_port   = device_port;
    search_id   = 0;
    search_timer->start(100);
}

void LogicActionPrivate::search_Max_eletric(Device_Name name)
{
    if(this->name != name){
        return ;
    }
    max_id  = 0;
    max_timer->start(200);
}

quint16 LogicActionPrivate::qChecksum(const QList<quint8> list, quint8 len)
{
    uint crc    = 0xffff;
    for(uint i=0;i<len;i++){
        crc = crc ^ (list.at(i));
        for(int j = 0;j<8;j++){
            if(crc&1)
            {
                crc>>=1;
                crc^=0xA001;
            }
            else
                crc>>=1;
        }
    }
    return (crc);
}

void LogicActionPrivate::parseCmd()
{
    if(rv_list.size() < 2)
        return ;

    QString str;
    for(int i=0;i<rv_list.size();i++){
        str += tr("%1 ").arg(rv_list.at(i),2,16,QLatin1Char('0'));
    }
    emit return_operation(name,str,tcpSocket->peerName());

    quint16 temp    = qChecksum(rv_list,rv_list.size()-2);
    if(temp != (rv_list.at(rv_list.size()-2) | (rv_list.at(rv_list.size()-1) << 8))){
        return ;
    }
    if(rv_list.at(0) != 0x01){
        return ;
    }
    switch(rv_list.at(1)){
    case 0x02: set_one_on_off(btn_id2,rv_list.at(3));
        if(rv_list.at(3)){
            emit return_one_on_off(name,btn_id2,ON);
        }
        else{
            emit return_one_on_off(name,btn_id2,OFF);
        }
        btn_id2++;
        break;
    case 0x05: if(rv_list.at(4) == 0xff){
                    set_one_on_off(rv_list.at(3),1);
                    emit return_one_on_off(name,rv_list.at(3),ON);
                }
                else if(rv_list.at(5) == 0x00){
                    set_one_on_off(rv_list.at(3),0);
                    emit return_one_on_off(name,rv_list.at(3),OFF);
                }break;
    case 0x03:
            emit return_one_actual_eletric(name,rv_list.at(3),rv_list.at(3));
        break;
    case 0x04:
            emit return_one_Max_eletric(name,rv_list.at(3),rv_list.at(3));
        break;
    }
}

void LogicActionPrivate::parseCmd(QString cmd)
{
    QString str;
    if(cmd.indexOf("$TA,Z",0) != -1){   //查询设备型号信息;
        str = cmd.section("$TA,Z",1);
        qDebug()<<str;
    }
    else if(cmd.indexOf("$TA,Y",0) != -1){  //查询设备配置信息;
        str = cmd.section("$TA,Y",1);
        qDebug()<<str;
    }
    else if(cmd.indexOf("$TA,Q",0) != -1){   //设备版本查询
        str = cmd.section("$TA,Y",1);
        qDebug()<<str;
    }
    else if(cmd.indexOf("$TA,W",0) != -1){   //端口命名；
        str = cmd.section("$TA,W",1);
        qDebug()<<str;
    }
}

void LogicActionPrivate::set_one_on_off(int branch, int status)
{
    port_status &= ~(1 << branch);
    port_status |= (status << branch);
}

void LogicActionPrivate::readMessage()
{
    QByteArray temp;
    QString str;
    temp	= tcpSocket->readAll();
    str     = temp.data();

    if(str.indexOf("$TA",0) != -1){
        parseCmd(str);
        return ;
    }
    bool m;
    QDataStream out(&temp,QIODevice::ReadWrite);

    rv_list.clear();
    while(!out.atEnd()){
        quint8 outchar;
        out >> outchar;
        str = tr("%1").arg(outchar,2,16);
        rv_list.append(str.toInt(&m,16));
    }
    parseCmd();    
}

void LogicActionPrivate::disconnected()
{
    timer->stop();
    RT_timer->stop();
}

void LogicActionPrivate::timeout()
{
    search_one_on_off(btn_id);

    search_version(name);
    search_Device_info(name);
    search_Device_model(name);

    btn_id++;
    if(btn_id == row){
        btn_id  = 0;
        timer->stop();
        RT_timer->start(100);
    }
}

void LogicActionPrivate::RT_timeout()
{
    RT_timer->stop();
    if(port_status & (1 << actual_id)){
        search_RT_eletric(actual_id);
    }
    actual_id++;
    if(actual_id == row){
        actual_id = 0;
    }    
    RT_timer->start(100);
}

void LogicActionPrivate::max_timerout()
{
    max_timer->stop();
    if(max_id < row){
        search_Max_eletric(max_id);
        max_timer->start(200);
    }
    max_id++;
}

void LogicActionPrivate::min_timeout()
{
    min_timer->stop();
}

void LogicActionPrivate::btn_timeout()
{
    btn_timer->stop();
    if(btn_id < row){
        search_one_on_off(btn_id);
        btn_timer->start(200);
    }
    btn_id++;
}

void LogicActionPrivate::search_timeout()
{
    switch(search_id){
    case 0: search_one_on_off(device_port);search_id++;break;
    case 1: search_Max_eletric(device_port);search_id++;break;
    case 2: search_Port_Name(name);search_id++;break;
    case 4: search_Min_eletric(device_port);search_id++;search_timer->stop();break;
    }
}

void LogicActionPrivate::connect_success()
{
    timer->start(100);
}

