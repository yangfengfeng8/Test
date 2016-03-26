#include "pacontrol.h"
#include "ui_pacontrol.h"


PAControl::PAControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PAControl)
{
    ui->setupUi(this);

    initPAControl();
}

PAControl::~PAControl()
{
    delete ui;
}

void PAControl::initPAControl()
{
    initTableWidget();

    initTextBrowser();

    initLayout();
}

void PAControl::initTableWidget()
{
    tableWidget = ui->tableWidget;

    tableWidget->model()
}

void PAControl::initTextBrowser()
{
    textBrowser = ui->textBrowser;
}

void PAControl::initLayout()
{
    splitter    = new QSplitter(Qt::Vertical);
    splitter->addWidget(tableWidget);
    splitter->addWidget(ui->groupBox);
    splitter->addWidget(textBrowser);

    splitter->setHandleWidth(0);
    splitter->setStretchFactor(0,6);
    splitter->setStretchFactor(2,1);
    splitter->setCollapsible(0,false);
    splitter->setCollapsible(1,false);
    splitter->setCollapsible(2,false);

    ui->verticalLayout->addWidget(splitter);
}

void PAControl::setRowColumn(const int &Row, const int &Column,const QVariant &Var)
{
    row = Row;
    column = Column;

    setMatrix(row,column,Var);
}

void PAControl::setMatrix(const int &Row, const int &Column, const QVariant &Var)
{
    tableWidget->setRowCount(Row);
    tableWidget->setColumnCount(Column);

    QStringList rowHeaderList;
    for(int i=0; i < row; i++){
        rowHeaderList << QString("A%1").arg(i + 1);
    }
    tableWidget->setHorizontalHeaderLabels(rowHeaderList);

    QStringList columnHeaderList;
    for(int i = 0; i < column; i++){
        columnHeaderList << QString("B%1").arg(i + 1);
    }
    tableWidget->setVerticalHeaderLabels(columnHeaderList);

    tableWidget->horizontalHeader()->setHidden(false);
    tableWidget->verticalHeader()->setHidden(false);

    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    tableWidget->setMinimumHeight(row * 40);
    tableWidget->horizontalHeader()->setMinimumHeight(30);
    tableWidget->verticalHeader()->setMinimumWidth(30);

    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            setItemValue(i,j,Var.toString());
        }
    }
}

void PAControl::setNoMatrix(const int &Row, const int &Column)
{

}

void PAControl::setItemValue(const int &Row, const int &Column, const QString &Str)
{
    QTableWidgetItem *item  = new QTableWidgetItem();
    item->setTextAlignment(Qt::AlignCenter);
    item->setText(Str);
    item->setForeground(QBrush(QColor(Qt::black)));
    tableWidget->setItem(Row,Column,item);
}

void PAControl::getDeviceType(const QString &Firmware)
{
    if (Firmware == QString("HBTE-PA-4-4-4-127-0.5")){
//        setInfo(Attenuation,NoMatrix,NoDivide);
        setRowColumn(1,4,127);
//        setDeviceType(QString("4-4"));
    }
    else if (Firmware == QString("HBTE-PA-5-5-4-127-0.5")){
//        setInfo(Attenuation,NoMatrix,NoDivide);
        setRowColumn(1,5,127);
//        setDeviceType(QString("5-5"));
    }
    else if (Firmware == QString("HBTE-PA-8-8-4-127-0.5")){
//        setInfo(Attenuation,NoMatrix,NoDivide);
        setRowColumn(1,8,127);
//        setDeviceType(QString("8-8"));
    }
    else if (Firmware == QString("HBTE-PA-8-8-4-60-0.5")){
//        setInfo(Attenuation,NoMatrix,NoDivide);
        setRowColumn(1,8,60);
//        setDeviceType(QString("8-8"));
    }
    else if(Firmware == QString("HBTE-PA-8-2-4-127-0.5")){
//        setInfo(Attenuation,NoMatrix,Divide);
//        isSpecial   = Special;
        setRowColumn(1,8,127);
//        setDeviceType(QString("8-2"));
    }
    else if (Firmware == QString("HBTE-PA-16-2-4-127-0.5")){
//        setInfo(Attenuation,NoMatrix,Divide);
//        isSpecial   = NoSpecial;
        setRowColumn(1,16,127);
//        setDeviceType(QString("16-2"));
    }
    else if (Firmware == QString("HBTE-PA-16-3-3.8-127-1")){
//        setInfo(Attenuation,NoMatrix,Divide);
//        isSpecial   = NoSpecial;
        setRowColumn(1,16,127);
//        setDeviceType(QString("16-3"));
    }
    else if (Firmware == QString("HBTE-PA-16-4-4-127-0.5")){
//        setInfo(Attenuation,NoMatrix,Divide);
//        isSpecial = Special;
        setRowColumn(1,16,127);
//        setDeviceType(QString("16-4"));
    }
    else if (Firmware == QString("HBTE-PA-32-32-4-127-0.5")){
//        setInfo(Attenuation,NoMatrix,NoDivide);
        setRowColumn(1,32,127);
//        setDeviceType(QString("32-32"));
    }
    else if (Firmware == QString("HBTE-PAM-8*8-4-60-0.5")){
//        setInfo(AttenuationSwitch,Matrix,NoDivide);
        setRowColumn(8,8,60);
    }
    else if (Firmware == QString("HBTE-PAM-8*8-4-63-0.5")){
 //       setInfo(Attenuation,Matrix,NoDivide);
        setRowColumn(8,8,63);
//        setDeviceType(QString("8*8"));
    }
    else if (Firmware == QString("HBTE-PAM-8*8-4-90-0.5")){
//        setInfo(Attenuation,Matrix,NoDivide);
        setRowColumn(8,8,90);
//        setDeviceType(QString("8*8"));
    }
    else if (Firmware == QString("HBTE-PAM-16*8-4-60-0.5")){
//        setInfo(AttenuationSwitch,Matrix,NoDivide);
        setRowColumn(16,8,60);
//        setDeviceType(QString("16*8"));
    }
    else if (Firmware == QString("HBTE-PAM-16*8-4-63-0.5")){
//        setInfo(Attenuation,Matrix,NoDivide);
        setRowColumn(16,8,63);
//        setDeviceType(QString("16*8"));
    }
    else if (Firmware == QString("HBTE-PAM-16*8-4-90-0.5")){
//        setInfo(Attenuation,Matrix,NoDivide);
        setRowColumn(16,8,90);
//        setDeviceType(QString("16*8"));
    }
    else if (Firmware == QString("HBTE-PAM-16*16-4-60-0.5")){
//        setInfo(AttenuationSwitch,Matrix,NoDivide);
        setRowColumn(16,16,60);
//        setDeviceType(QString("16*16"));
    }
    else if (Firmware == QString("HBTE-PAM-16*16-4-63-0.5")){
//        setInfo(Attenuation,Matrix,NoDivide);
        setRowColumn(16,16,63);
//        setDeviceType(QString("16*16"));
    }
    else if (Firmware == QString("HBTE-PAM-16*16-4-90-0.5")){
//        setInfo(Attenuation,Matrix,NoDivide);
        setRowColumn(16,16,90);
//        setDeviceType(QString("16*16"));
    }
    else if (Firmware == QString("HBTE-PAM-32*16-4-63-0.5")){
//        setInfo(Attenuation,Matrix,NoDivide);
        setRowColumn(32,16,63);
//        setDeviceType(QString("32*16"));
    }
    else if (Firmware == QString("HBTE-PAM-32*32-4-60-0.5")){
//        setInfo(Attenuation,Matrix,NoDivide);
        setRowColumn(32,32,60);
//        setDeviceType(QString("32*32"));
    }
}
