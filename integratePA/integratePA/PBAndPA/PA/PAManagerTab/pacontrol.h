#ifndef CONTROL_H
#define CONTROL_H

#include <QWidget>
#include <QSplitter>
#include <QTableWidget>
#include <QTextBrowser>
#include "PA/pabase.h"

namespace Ui {
class PAControl;
}

class PAControl : public QWidget
{
    Q_OBJECT

public:
    explicit PAControl(QWidget *parent = 0);
    ~PAControl();

    void initPAControl();

    void initTableWidget();

    void initTextBrowser();

    void initLayout();

    void setRowColumn(const int &Row,const int &Column,const QVariant &Var);

    void setMatrix(const int &Row, const int &Column,const QVariant &Var);

    void setNoMatrix(const int &Row, const int &Column);

    void setItemValue(const int &Row, const int &Column, const QString &Str);

public slots:
    void getDeviceType(const QString &Firmware);

private:
    Ui::PAControl *ui;

    QSplitter *splitter;

    QTableWidget *tableWidget;
    QTextBrowser *textBrowser;

    int row;
    int column;
};

#endif // CONTROL_H
