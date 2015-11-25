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


}
