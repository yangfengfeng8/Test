#include "mainwindow.h"
#include <QApplication>
#include "./dialog/loginin.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QIcon icon(":/image/HBTE.ico");
    a.setWindowIcon(icon);
    a.setApplicationName("PowerStation");

    LoginIn login;

    if(login.exec()){
        MainWindow w;
        w.show();
        login.hide();
        return a.exec();
    }
    else {
       return 0;
    }
/*
//读取实际电流；
//  01 03 00 branch 00 00 crc16;
  branch: 代表通道号；
  00 00 : 代表实际电流值，实际电流值扩大100倍；

//设置电流最大值：
  01 06 00 branch 00 00 crc16;
  00 : 代表此时是设置最大值；
  branch: 代表通道号；
  00 00 ：代表设置的最大电流值，

//设置电流最小值：
  01 06 01 branch 00 00 crc16;
  01: 代表此时是设置电路最小值；
  branch: 代表通道号；
  00 00 : 代表设置的最小电流值；

//蜂鸣器控制；
  01 05 00 FF FF 00 crc16;
  00 FF: 代表此时控制的是蜂鸣器；
  FF 00: 表示此时打开蜂鸣器；
  00 00：表示此时关闭蜂鸣器；
*/
}
