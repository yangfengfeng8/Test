#include "paPortName.h"
#include "ui_paPortName.h"
#include <QFont>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QDebug>

#define COLOR_GRAY QColor(217,217,201)
#define COLOR_GRAY_1 QColor(217,214,201)

PAPortName::PAPortName(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PAPortName)
{
    ui->setupUi(this);
    modelIn = new QStandardItemModel;
    modelOut = new QStandardItemModel;
    ui->tableViewIn->setModel(modelIn);
    ui->tableViewOut->setModel(modelOut);
    ui->tableViewIn->verticalHeader()->setHidden(true); /* 隐藏竖列表头 */
    ui->tableViewIn->horizontalHeader()->setHidden(true);
    ui->tableViewOut->verticalHeader()->setHidden(true);
    ui->tableViewOut->horizontalHeader()->setHidden(true);

    /* 去掉右上角的?号 */
    Qt::WindowFlags flags=Qt::Dialog;
    flags |= Qt::WindowCloseButtonHint;
    setWindowFlags(flags);
    this->setWindowTitle("Port naming");

    /* 设置表格行列自适应大小 */
//    ui->tableViewIn->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    ui->tableViewOut->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableViewIn->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableViewOut->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableViewIn->setColumnWidth(0,70);
    ui->tableViewOut->setColumnWidth(0,70);

    ui->tableViewIn->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableViewOut->setSelectionMode(QAbstractItemView::NoSelection);

    m_in = 0;
    m_out = 0;

    connect(ui->PubExport,SIGNAL(clicked(bool)),this,SLOT(onExprtPubClicked()));
    connect(ui->PubImport,SIGNAL(clicked(bool)),this,SLOT(onImportPubClicked()));
    connect(ui->PubOK,SIGNAL(clicked(bool)),this,SLOT(onOKPubClicked()));
    connect(ui->PubClear,SIGNAL(clicked(bool)),this,SLOT(onClearPubClicked()));

    QTimer::singleShot(100,this,SLOT(showLater()));
}

PAPortName::~PAPortName()
{
    delete ui;
}

int PAPortName::setTable(QString strMsgIp,QString strMsgEqu)
{
    m_strEqu.clear();
    m_HexIn.clear();
    m_HexOut.clear();
    if(strMsgIp.section(':',1,1) == "...")
        return 0;
    modelIn->clear();
    modelOut->clear();
    QString strEqup = strMsgEqu;
    m_strEqu = strEqup;

    if(strEqup == "8*8")
    {
        initModel("8*8",8,8);
        m_in = 8;
        m_out = 8;
    }else if(strEqup == "8*6")
    {
         initModel("8*6",8,6);
         m_in = 8;
         m_out = 6;
    }else if(strEqup == "16*16")
    {
        initModel("16*16",16,16);
        m_in = 16;
        m_out = 16;
    }else if(strEqup == "16*08")
	{
		initModel("16*08",16,8);
		m_in = 16;
		m_out = 8;
    }else if(strEqup == "32*16")
    {
        initModel("32*16",32,16);
        m_in = 32;
        m_out = 16;
    }
    else if(strEqup == "16-02")
    {
        initModel("16-02",16,2);
        m_in = 16;
        m_out = 2;
    }else if(strEqup == "16-04")
    {
        initModel("16-04",16,4);
        m_in = 16;
        m_out = 4;
    }else if(strEqup == "32-32")
    {
        initModel("32-32",32,32);
        m_in = 32;
        m_out = 32;
    }else if(strEqup == "8-8")
    {
        initModel("8-8",8,8);
        m_in = 8;
        m_out = 8;
    }else if(strEqup == "16-03")
    {
        initModel("16-03",16,3);
        m_in = 16;
        m_out = 3;
    }else if(strEqup == "4-4")
    {
        initModel("4-4",4,4);
        m_in = 4;
        m_out = 4;
    }else if(strEqup == "8-2")
    {
        initModel("8-2",8,2);
        m_in = 8;
        m_out = 2;
    }else if(strEqup == "5-5")
    {
        initModel("5-5",5,5);
        m_in = 5;
        m_out = 5;
    }

    ui->tableViewIn->setColumnWidth(0,70);
    ui->tableViewOut->setColumnWidth(0,70);
    return 0;
}

void PAPortName::initModel(QString strEqup, int nIn, int nOut)
{   
    int nOuShu = 0;
    /* 设置表头 */


    if(strEqup == "8*8")
       {
           m_HexIn<<"IN1"<<"IN2"<<"IN3"<<"IN4"<<"IN5"<<"IN6"<<"IN7"<<"IN8";
           m_HexOut<<"OUT1"<<"OUT2"<<"OUT3"<<"OUT4"<<"OUT5"<<"OUT6"<<"OUT7"<<"OUT8";
       }else if(strEqup == "8*6")
       {
           m_HexIn<<"IN1"<<"IN2"<<"IN3"<<"IN4"<<"IN5"<<"IN6"<<"IN7"<<"IN8";
           m_HexOut<<"OUT1"<<"OUT2"<<"OUT3"<<"OUT4"<<"OUT5"<<"OUT6";
       }else if(strEqup == "16*16")
       {
           m_HexIn<<"IN1"<<"IN2"<<"IN3"<<"IN4"<<"IN5"<<"IN6"<<"IN7"<<"IN8"<<"IN9"<<"IN10"<<"IN11"<<"IN12"<<"IN13"<<"IN14"<<"IN15"<<"IN16";
           m_HexOut<<"OUT1"<<"OUT2"<<"OUT3"<<"OUT4"<<"OUT5"<<"OUT6"<<"OUT7"<<"OUT8"<<"OUT9"<<"OUT10"<<"OUT11"<<"OUT12"
                  <<"OUT13"<<"OUT14"<<"OUT15"<<"OUT16";
       }else if(strEqup == "32*16")
       {
           m_HexIn<<"IN1"<<"IN2"<<"IN3"<<"IN4"<<"IN5"<<"IN6"<<"IN7"<<"IN8"<<"IN9"<<"IN10"<<"IN11"<<"IN12"<<"IN13"<<"IN14"<<"IN15"<<"IN16"
                    <<"IN17"<<"IN18"<<"IN19"<<"IN20"<<"IN21"<<"IN22"<<"IN23"<<"IN24"<<"IN25"<<"IN26"<<"IN27"<<"IN28"<<"IN29"<<"IN30"<<"IN31"<<"IN32";
           m_HexOut<<"OUT1"<<"OUT2"<<"OUT3"<<"OUT4"<<"OUT5"<<"OUT6"<<"OUT7"<<"OUT8"<<"OUT9"<<"OUT10"<<"OUT11"<<"OUT12"
               <<"OUT13"<<"OUT14"<<"OUT15"<<"OUT16";
       }else if(strEqup == "16*08")
       {
           m_HexIn<<"IN1"<<"IN2"<<"IN3"<<"IN4"<<"IN5"<<"IN6"<<"IN7"<<"IN8"<<"IN9"<<"IN10"<<"IN11"<<"IN12"<<"IN13"<<"IN14"<<"IN15"<<"IN16";
           m_HexOut<<"OUT1"<<"OUT2"<<"OUT3"<<"OUT4"<<"OUT5"<<"OUT6"<<"OUT7"<<"OUT8";
       }else if(strEqup == "16-02")
       {
           m_HexIn<<"IN1"<<"IN2"<<"IN3"<<"IN4"<<"IN5"<<"IN6"<<"IN7"<<"IN8"<<"IN9"<<"IN10"<<"IN11"<<"IN12"<<"IN13"<<"IN14"<<"IN15"<<"IN16";
           m_HexOut<<"OUT1"<<"OUT2";
       }else if(strEqup == "16-04")
       {
            m_HexIn<<"IN1"<<"IN2"<<"IN3"<<"IN4"<<"IN5"<<"IN6"<<"IN7"<<"IN8"<<"IN9"<<"IN10"<<"IN11"<<"IN12"<<"IN13"<<"IN14"<<"IN15"<<"IN16";
            m_HexOut<<"OUT1"<<"OUT2"<<"OUT3"<<"OUT4";
       }else if(strEqup == "8-8")
       {
            m_HexIn<<"IN1"<<"IN2"<<"IN3"<<"IN4"<<"IN5"<<"IN6"<<"IN7"<<"IN8";
            m_HexOut<<"OUT1"<<"OUT2"<<"OUT3"<<"OUT4"<<"OUT5"<<"OUT6"<<"OUT7"<<"OUT8";
       }else if(strEqup == "32-32")
       {
            m_HexIn<<"IN1"<<"IN2"<<"IN3"<<"IN4"<<"IN5"<<"IN6"<<"IN7"<<"IN8"<<"IN9"<<"IN10"<<"IN11"<<"IN12"<<"IN13"<<"IN14"<<"IN15"<<"IN16"
                     <<"IN17"<<"IN18"<<"IN19"<<"IN20"<<"IN21"<<"IN22"<<"IN23"<<"IN24"<<"IN25"<<"IN26"<<"IN27"<<"IN28"<<"IN29"<<"IN30"<<"IN31"<<"IN32";
            m_HexOut<<"OUT1"<<"OUT2"<<"OUT3"<<"OUT4"<<"OUT5"<<"OUT6"<<"OUT7"<<"OUT8"<<"OUT9"<<"OUT10"<<"OUT11"<<"OUT12"<<"OUT13"<<"OUT14"<<"OUT15"<<"OUT16"
                      <<"OUT17"<<"OUT18"<<"OUT19"<<"OUT20"<<"OUT21"<<"OUT22"<<"OUT23"<<"OUT24"<<"OUT25"<<"OUT26"<<"OUT27"<<"OUT28"<<"OUT29"<<"OUT30"<<"OUT31"<<"OUT32";
       }else if(strEqup == "16-03")
       {
           m_HexIn<<"IN1"<<"IN2"<<"IN3"<<"IN4"<<"IN5"<<"IN6"<<"IN7"<<"IN8"<<"IN9"<<"IN10"<<"IN11"<<"IN12"<<"IN13"<<"IN14"<<"IN15"<<"IN16";
           m_HexOut<<"OUT1"<<"OUT2"<<"OUT3";
       }else if(strEqup == "4-4")
       {
           m_HexIn<<"IN1"<<"IN2"<<"IN3"<<"IN4";
           m_HexOut<<"OUT1"<<"OUT2"<<"OUT3"<<"OUT4";
       }else if(strEqup == "8-2")
       {
           m_HexIn<<"IN1"<<"IN2"<<"IN3"<<"IN4"<<"IN5"<<"IN6"<<"IN7"<<"IN8";
           m_HexOut<<"OUT1"<<"OUT2";
       }else if(strEqup == "5-5")
    {
        m_HexIn<<"IN1"<<"IN2"<<"IN3"<<"IN4"<<"IN5";
        m_HexOut<<"OUT1"<<"OUT2"<<"OUT3"<<"OUT4"<<"OUT5";
    }

    /* 设置Item */
    if((strEqup=="8*6") || (strEqup=="8*8") || (strEqup=="16*08") || (strEqup=="16*16") || (strEqup == "32*16")) /* 矩阵 */
    {
        nOuShu = 0;
        for(int i = 0; i < nIn; i++)
        {
            QStandardItem *item = new QStandardItem(QString("IN%1").arg(i + 1));
            QStandardItem *itemCol = new QStandardItem(QString(""));
            item->setTextAlignment(Qt::AlignCenter);
            itemCol->setTextAlignment(Qt::AlignCenter);
            modelIn->setItem(i,0,item);
            modelIn->setItem(i,1,itemCol);
            modelIn->item(i,0)->setEditable(false);
            if(nOuShu % 2 != 0)
            {
                modelIn->item(i,0)->setBackground(QBrush(COLOR_GRAY));
                modelIn->item(i,1)->setBackground(QBrush(COLOR_GRAY_1));
            }
            nOuShu ++;
        }
        nOuShu = 0;
        for(int i = 0; i < nOut; i++)
        {
            QStandardItem *item = new QStandardItem(QString("OUT%1").arg(i + 1));
            QStandardItem *itemCol = new QStandardItem(QString(""));
            item->setTextAlignment(Qt::AlignCenter);
            itemCol->setTextAlignment(Qt::AlignCenter);
            modelOut->setItem(i,0,item);
            modelOut->setItem(i,1,itemCol);
            modelOut->item(i,0)->setEditable(false);
            if(nOuShu % 2 != 0)
            {
                modelOut->item(i,0)->setBackground(QBrush(COLOR_GRAY));
                modelOut->item(i,1)->setBackground(QBrush(COLOR_GRAY_1));
            }
            nOuShu ++;
        }
    }else   /* 非矩阵 */
    {
        nOuShu = 0;
        for(int i = 0; i < nIn; i++)
        {
            QStandardItem *item = new QStandardItem(QString("IN%1").arg(i + 1));
            QStandardItem *itemCol = new QStandardItem(QString(""));
            item->setTextAlignment(Qt::AlignCenter);
            itemCol->setTextAlignment(Qt::AlignCenter);
            modelIn->setItem(i,0,item);
            modelIn->setItem(i,1,itemCol);
            modelIn->item(i,0)->setEditable(false);
            if(nOuShu % 2 != 0)
            {
                modelIn->item(i,0)->setBackground(QBrush(COLOR_GRAY));
                modelIn->item(i,1)->setBackground(QBrush(COLOR_GRAY_1));
            }
            nOuShu ++;
        }
        nOuShu = 0;
        for(int i = 0; i < nOut; i++)
        {
            QStandardItem *item = new QStandardItem(QString("OUT%1").arg(i + 1));
            QStandardItem *itemCol = new QStandardItem(QString(""));
            item->setTextAlignment(Qt::AlignCenter);
            itemCol->setTextAlignment(Qt::AlignCenter);
            modelOut->setItem(i,0,item);
            modelOut->setItem(i,1,itemCol);
            modelOut->item(i,0)->setEditable(false);
            if(nOuShu % 2 != 0)
            {
                modelOut->item(i,0)->setBackground(QBrush(COLOR_GRAY));
                modelOut->item(i,1)->setBackground(QBrush(COLOR_GRAY_1));
            }
            nOuShu ++;
        }
    }

    ui->tableViewIn->setColumnWidth(0,70);
    ui->tableViewOut->setColumnWidth(0,70);
}

/* ->设置表格 */
/**************************************
 * 时间：16/3/25
 * 修改人：杨跃勋；
 * 更改内容：1.将公共函数void setTableValue(QString strRecv) 更改为槽函数。
 *           2.将参数类型QString strRecv 更改为const QString &strRecv。
 *           3.将函数名称更改为setPortName。
 *
 *
 *
 */
void PAPortName::setPortName(const QString &strRecv)
{
    QStringList strListRecv;
    strListRecv = strRecv.split(QChar('-'));
    if(strListRecv.size() < 0)
    {
        QMessageBox::information(this,"Note:","The list is empty.",tr("OK"));
        return;
    }

    if(strListRecv.size() != (m_in + m_out))
    {
        return;
    }

    QString strPer;
    if((m_strEqu == "8*6") || (m_strEqu == "8*8") || (m_strEqu == "16*08") || (m_strEqu == "16*16") || (m_strEqu == "32*16"))
    {
        /* 矩阵 */
        for(int i = 0; i < m_in; i++)
        {
            strPer = strListRecv.at(i);
            if(((strPer.indexOf("IN") == 0) || (strPer.indexOf("OUT") == 0)) && (strPer.length() <= 5))
                modelIn->item(i,1)->setText("");
            else
                modelIn->item(i,1)->setText(strPer);
        }
        for(int i = 0; i < m_out; i++)
        {
            strPer = strListRecv.at(m_in + i);
            if(((strPer.indexOf("IN") == 0) || (strPer.indexOf("OUT") == 0)) && (strPer.length() <= 5))
                modelOut->item(i,1)->setText("");
            else
                modelOut->item(i,1)->setText(strPer);
        }
    }else
    {
        for(int i = 0; i < m_in; i++)
        {
            strPer = strListRecv.at(i);
            if(((strPer.indexOf("IN") == 0) || (strPer.indexOf("OUT") == 0)) && (strPer.length() <= 5))
                modelIn->item(i,1)->setText("");
            else
                modelIn->item(i,1)->setText(strPer);
        }
        for(int i = 0; i < m_out; i++)
        {
            strPer = strListRecv.at(m_in + i);
            if(((strPer.indexOf("IN") == 0) || (strPer.indexOf("OUT") == 0)) && (strPer.length() <= 5))
                modelOut->item(i,1)->setText("");
            else
                modelOut->item(i,1)->setText(strPer);
        }
    }

    ui->tableViewIn->setColumnWidth(0,70);
    ui->tableViewOut->setColumnWidth(0,70);
}

void PAPortName::clearTable()
{
    modelIn->clear();
    modelOut->clear();
}


void PAPortName::onExprtPubClicked()
{
    /* 获取数据 */
    QString strSave;
    strSave = m_strEqu + '\n';
    strSave += "In: ";
    for(int i = 0; i < m_in; i++)
    {
        if(modelIn->item(i,1)->text().length() > 15)
        {
            QMessageBox::information(this,"Note:",QString("The IN:%1 channel's name is too long(>15), please re_input.").arg(i + 1),tr("OK"));
            return;
        }else if(modelIn->item(i,1)->text().remove(QChar(' ')).isEmpty())
        {
            modelIn->item(i,1)->setText(m_HexIn.at(i));
        }
        strSave += modelIn->item(i,1)->text() + " ";
    }
    strSave += '\n';
    strSave += "Out: ";
    for(int i = 0; i < m_out; i++)
    {
        if(modelOut->item(i,1)->text().length() > 15)
        {
            QMessageBox::information(this,"Note:",QString("The OUT:%1 channel's name is too long(>15),please re_input.").arg(i + 1),tr("OK"));
            return;
        }else if(modelOut->item(i,1)->text().remove(QChar(' ')).isEmpty())
        {
           modelOut->item(i,1)->setText(m_HexOut.at(i));
        }
        strSave += modelOut->item(i,1)->text() + " ";
    }

    /* 保存数据 */
    QString strFileName = QFileDialog::getSaveFileName(this,tr("Save Port Data"),getenv("Home"),"(*.port)");
    if(strFileName.isEmpty())
        return;
    QFile file(strFileName);
    if(!file.open(QIODevice::WriteOnly))
        return;
    else
    {
        QTextStream streamFile(&file);
        streamFile<<strSave<<endl;
    }
    file.close();
}

void PAPortName::onImportPubClicked()
{
    QString strMsg;
    QString strEqu;
    QString strPer;
    QStringList strListMsg;
    QString strImportFileName = QFileDialog::getOpenFileName(this,"Open File","*.port");
    if(strImportFileName.isEmpty())
        return;
    QFile file(strImportFileName);
    if(!file.open(QIODevice::ReadOnly))
        return;
    QTextStream stream(&file);
    strEqu = stream.readLine();

    /* 判断设备类型 */
    if(strEqu.remove(QChar(' ')) != m_strEqu)
    {
        QMessageBox::information(this,"Note:","The file format is wrong.",tr("OK"));
        return;
    }

    /* 设置数据 */
    while(!stream.atEnd())
    {
        strMsg.clear();
        strListMsg.clear();
        strMsg = stream.readLine();
        if(!strMsg.isEmpty())
        {
            strListMsg = strMsg.split(QChar(' '));
            if(strListMsg.at(0) == "In:")
            {
                for(int i = 1; i < strListMsg.size(); i++)
                {
					if(!strListMsg.at(i).isEmpty())
					{
						strPer.clear();
						strPer = strListMsg.at(i);
                        if(strPer.length() > 15)
						{
                            QMessageBox::information(this,"Note:","The channel name is too long(>15),Please re_input.",tr("OK"));
							return;
						}
                        modelIn->item(i - 1,1)->setText(strPer);
					}
                }
            }else if(strListMsg.at(0) == "Out:")
            {
                for(int i = 1; i < strListMsg.size(); i++)
                {
					if(!strListMsg.at(i).isEmpty())
					{
						strPer.clear();
						strPer = strListMsg.at(i);
                        if(strPer.length() > 15)
						{
                            QMessageBox::information(this,"Note:","The channel name is too long(>15), please re_input.",tr("OK"));
							return;
						}
                        modelOut->item(i - 1,1)->setText(strPer);
					}
                }
            }
        }
    }
    file.close();
}

/* 按下OK按钮 */
/****************************************************************
 * 时间：16/3/25
 * 修改人：杨跃勋
 * 更改内容：去掉发送数据时的表头（$TA,W,）和表尾（*\r\n）。
 *
 *
 *
 */
void PAPortName::onOKPubClicked()
{
    QString strPortName;
    QString strItemText;

//    strPortName = "$TA,W,";

    if((m_strEqu == "8*8") || (m_strEqu == "16*16") || (m_strEqu == "16*08") || (m_strEqu == "8*6") || (m_strEqu == "32*16"))
    {   /* 矩阵 */
        /* 行 */
        for(int i = 0; i < m_in; i++)
        {
            strItemText.clear();
            strItemText = modelIn->item(i,1)->text();
            if(strItemText.remove(QChar(' ')).isEmpty())
            {
                modelIn->item(i,1)->setText(m_HexIn.at(i));
                strItemText = modelIn->item(i,1)->text();
            }
            if((strItemText.length() > 15) || (strItemText.indexOf(QChar('-')) != -1))
            {
                QMessageBox::information(this,"Note:",QString("The channel In%1 name length >15 or is empty, please re_input.").arg(i + 1),tr("OK"));
                return;
            }
            strPortName += strItemText + "-";
        }

        for(int i = 0;i < m_out; i++)
        {
            strItemText.clear();
            strItemText = modelOut->item(i,1)->text();
            if(strItemText.remove(QChar(' ')).isEmpty())
            {
                modelOut->item(i,1)->setText(m_HexOut.at(i));
                strItemText = modelOut->item(i,1)->text();
            }
            if((strItemText.length() > 15)  || (strItemText.indexOf(QChar('-')) != -1))
            {
                QMessageBox::information(this,"Note:",QString("The channel Out%1 name length >15 or is empty, please re_input.").arg(i + 1),tr("OK"));
                return;
            }
            if(i != (m_out - 1))
                strPortName += strItemText + "-";
            else if(i == (m_out - 1))
                strPortName += strItemText;
        }
    }else
    {

        for(int i = 0; i < m_in; i++)
        {
            strItemText.clear();
            strItemText = modelIn->item(i,1)->text();
            if(strItemText.remove(QChar(' ')).isEmpty())
            {
                modelIn->item(i,1)->setText(m_HexIn.at(i));
                strItemText = modelIn->item(i,1)->text();
            }
            if((strItemText.length() > 15) || (strItemText.indexOf(QChar('-')) != -1))
            {
                QMessageBox::information(this,"Note:",QString("The channel In%1 name length >15 or is empty, please re_input.").arg(i + 1),tr("OK"));
                return;
            }
            strPortName += strItemText + "-";
        }

        for(int i = 0;i < m_out; i++)
        {
            strItemText.clear();
            strItemText = modelOut->item(i,1)->text();
            if(strItemText.remove(QChar(' ')).isEmpty())
            {
                modelOut->item(i,1)->setText(m_HexOut.at(i));
                strItemText = modelOut->item(i,1)->text();
            }
            if((strItemText.length() > 15)  || (strItemText.indexOf(QChar('-')) != -1))
            {
                QMessageBox::information(this,"Note:",QString("The channel Out%1 name length >15 or is empty, please re_input.").arg(i + 1),tr("OK"));
                return;
            }
            if(i != (m_out - 1))
                strPortName += strItemText + "-";
            else if(i == (m_out - 1))
                strPortName += strItemText;
        }
    }
/*    strPortName += "*";
    strPortName += '\r';
    strPortName += '\n';
*/
    onClearPubClicked();

  qDebug()<<"strPortName:"<<strPortName;
    emit changePortName(strPortName);

}

void PAPortName::onClearPubClicked()
{
    for(int i = 0; i < m_in; i++)
    {
        modelIn->item(i,1)->setText("");
    }
    for(int i = 0; i < m_out; i++)
    {
        modelOut->item(i,1)->setText("");
    }
}

void PAPortName::showLater()
{
    this->resize(560,290);
}


