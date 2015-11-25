/********************************************************************************
** Form generated from reading UI file 'outlet_status.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OUTLET_STATUS_H
#define UI_OUTLET_STATUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Outlet_Status
{
public:
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableWidget *tableWidget;

    void setupUi(QWidget *Outlet_Status)
    {
        if (Outlet_Status->objectName().isEmpty())
            Outlet_Status->setObjectName(QStringLiteral("Outlet_Status"));
        Outlet_Status->resize(497, 465);
        Outlet_Status->setStyleSheet(QStringLiteral("background-color: white;"));
        verticalLayout_2 = new QVBoxLayout(Outlet_Status);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(Outlet_Status);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setStyleSheet(QLatin1String("QFrame {\n"
"	margin: 10px;\n"
"};"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 40));
        label->setStyleSheet(QLatin1String("QLabel {\n"
"	margin: 0px;\n"
"	background-color: rgb(189, 255, 233);\n"
"	color: blue;\n"
"	border-top: 0px;\n"
"	border-right: 0px;\n"
"	border-left: 0px;\n"
"}"));

        verticalLayout->addWidget(label);

        tableWidget = new QTableWidget(frame);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (tableWidget->rowCount() < 8)
            tableWidget->setRowCount(8);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(2, 1, __qtablewidgetitem3);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setStyleSheet(QString::fromUtf8("QTableView, QHeaderView, QTableView::item {\n"
"    background: white;\n"
"	margin: 0px;\n"
"	border-left: 0px;\n"
"	border-top: 0px solid  rgb(124, 119, 119);\n"
"	min-height: 30px;\n"
"	border-bottom: 0px;\n"
"	text-align: center;\n"
"}\n"
"\n"
"QTableView::item:alternate {\n"
"    background: rgb(209, 231, 254);\n"
"}\n"
"\n"
"QTableView::item:selected { /*\350\242\253\351\200\211\344\270\255\347\232\204index*/\n"
"    color: black;\n"
"    background: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 0, y2: 1,\n"
"        stop: 0 #FAFBFE,\n"
"        stop: 1 #DCDEF1);\n"
"}\n"
"\n"
"QHeaderView::section:horizontal, QTableCornerButton::section {\n"
"    background-color: rgb(0,255,255);\n"
"    border: 1px solid rgb(153, 153, 153);\n"
"    border-width: 0 1px 1px 0;\n"
"}"));
        tableWidget->setRowCount(8);
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tableWidget);


        verticalLayout_2->addWidget(frame);


        retranslateUi(Outlet_Status);

        QMetaObject::connectSlotsByName(Outlet_Status);
    } // setupUi

    void retranslateUi(QWidget *Outlet_Status)
    {
        Outlet_Status->setWindowTitle(QApplication::translate("Outlet_Status", "Form", 0));
        label->setText(QApplication::translate("Outlet_Status", "TextLabel", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Outlet_Status", "#", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Outlet_Status", "State", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Outlet_Status", "Name", 0));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->item(2, 1);
        ___qtablewidgetitem3->setText(QApplication::translate("Outlet_Status", "d", 0));
        tableWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class Outlet_Status: public Ui_Outlet_Status {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUTLET_STATUS_H
