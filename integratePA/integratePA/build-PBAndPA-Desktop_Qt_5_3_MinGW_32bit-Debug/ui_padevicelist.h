/********************************************************************************
** Form generated from reading UI file 'padevicelist.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PADEVICELIST_H
#define UI_PADEVICELIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PADeviceList
{
public:
    QVBoxLayout *verticalLayout;
    QTreeWidget *treeWidget;
    QTableWidget *tableWidget;

    void setupUi(QWidget *PADeviceList)
    {
        if (PADeviceList->objectName().isEmpty())
            PADeviceList->setObjectName(QStringLiteral("PADeviceList"));
        PADeviceList->resize(420, 625);
        verticalLayout = new QVBoxLayout(PADeviceList);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        treeWidget = new QTreeWidget(PADeviceList);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(treeWidget->sizePolicy().hasHeightForWidth());
        treeWidget->setSizePolicy(sizePolicy);
        treeWidget->setStyleSheet(QStringLiteral(""));
        treeWidget->setFrameShape(QFrame::NoFrame);
        treeWidget->setFrameShadow(QFrame::Sunken);
        treeWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        treeWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        treeWidget->setRootIsDecorated(true);

        verticalLayout->addWidget(treeWidget);

        tableWidget = new QTableWidget(PADeviceList);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (tableWidget->rowCount() < 12)
            tableWidget->setRowCount(12);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        tableWidget->setItem(0, 0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        tableWidget->setItem(1, 0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setItem(1, 1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setItem(2, 0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setItem(2, 1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setItem(3, 0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setItem(3, 1, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setItem(4, 0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setItem(4, 1, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setItem(5, 0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setItem(5, 1, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setItem(6, 0, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget->setItem(6, 1, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget->setItem(7, 0, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget->setItem(7, 1, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget->setItem(8, 0, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget->setItem(8, 1, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget->setItem(9, 0, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget->setItem(9, 1, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget->setItem(10, 0, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget->setItem(10, 1, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget->setItem(11, 0, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget->setItem(11, 1, __qtablewidgetitem31);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setMinimumSize(QSize(0, 0));
        tableWidget->setStyleSheet(QString::fromUtf8(" QHeaderView{background: white;margin: 0px;border: 0px;min-height: 30px;}QScrollBar{\n"
"	background-color: url();}QTableView::item:alternate {\n"
"    background: rgb(209, 231, 254);\n"
"}QTableView{	margin-left: -1px;\n"
"}QTableView::item:selected { /*\350\242\253\351\200\211\344\270\255\347\232\204index*/color: black;background: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #FAFBFE,stop: 1 #DCDEF1);border-left:0px;\n"
"}QHeaderView::section:horizontal, QTableCornerButton::section {\n"
"    background-color: white;\n"
"	border:1px solid rgb(240,240,245);\n"
"	border-left: 0px;\n"
"    border-width: 0 1px 1px 0;\n"
"	padding: 2px;\n"
"}"));
        tableWidget->setFrameShape(QFrame::Panel);
        tableWidget->setFrameShadow(QFrame::Sunken);
        tableWidget->setLineWidth(1);
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setShowGrid(false);
        tableWidget->setRowCount(12);
        tableWidget->horizontalHeader()->setDefaultSectionSize(100);
        tableWidget->horizontalHeader()->setMinimumSectionSize(25);
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setMinimumSectionSize(25);

        verticalLayout->addWidget(tableWidget);


        retranslateUi(PADeviceList);

        QMetaObject::connectSlotsByName(PADeviceList);
    } // setupUi

    void retranslateUi(QWidget *PADeviceList)
    {
        PADeviceList->setWindowTitle(QApplication::translate("PADeviceList", "Form", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("PADeviceList", "Parameter", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("PADeviceList", "Value", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("PADeviceList", "\346\226\260\345\273\272\350\241\214", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("PADeviceList", "1", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem4->setText(QApplication::translate("PADeviceList", "2", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem5->setText(QApplication::translate("PADeviceList", "3", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem6->setText(QApplication::translate("PADeviceList", "4", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem7->setText(QApplication::translate("PADeviceList", "6", 0));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->item(0, 0);
        ___qtablewidgetitem8->setText(QApplication::translate("PADeviceList", "Name:", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->item(0, 1);
        ___qtablewidgetitem9->setText(QApplication::translate("PADeviceList", "Programmable attenuator/matrix", 0));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->item(1, 0);
        ___qtablewidgetitem10->setText(QApplication::translate("PADeviceList", "Software:", 0));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->item(1, 1);
        ___qtablewidgetitem11->setText(QApplication::translate("PADeviceList", "1.0.4.2", 0));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->item(2, 0);
        ___qtablewidgetitem12->setText(QApplication::translate("PADeviceList", "Firmware:", 0));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->item(2, 1);
        ___qtablewidgetitem13->setText(QApplication::translate("PADeviceList", "Unknown", 0));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->item(3, 0);
        ___qtablewidgetitem14->setText(QApplication::translate("PADeviceList", "User:", 0));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->item(3, 1);
        ___qtablewidgetitem15->setText(QApplication::translate("PADeviceList", "Unknown", 0));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->item(4, 0);
        ___qtablewidgetitem16->setText(QApplication::translate("PADeviceList", "IP address:", 0));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->item(4, 1);
        ___qtablewidgetitem17->setText(QApplication::translate("PADeviceList", "Unknown", 0));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->item(5, 0);
        ___qtablewidgetitem18->setText(QApplication::translate("PADeviceList", "Subnet mask:", 0));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->item(5, 1);
        ___qtablewidgetitem19->setText(QApplication::translate("PADeviceList", "Unknown", 0));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->item(6, 0);
        ___qtablewidgetitem20->setText(QApplication::translate("PADeviceList", "Gateway:", 0));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->item(6, 1);
        ___qtablewidgetitem21->setText(QApplication::translate("PADeviceList", "Unknown", 0));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->item(7, 0);
        ___qtablewidgetitem22->setText(QApplication::translate("PADeviceList", "Port:", 0));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->item(7, 1);
        ___qtablewidgetitem23->setText(QApplication::translate("PADeviceList", "Unknown", 0));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->item(8, 0);
        ___qtablewidgetitem24->setText(QApplication::translate("PADeviceList", "Type:", 0));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->item(8, 1);
        ___qtablewidgetitem25->setText(QApplication::translate("PADeviceList", "Unknown", 0));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->item(9, 0);
        ___qtablewidgetitem26->setText(QApplication::translate("PADeviceList", "dB range:", 0));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->item(9, 1);
        ___qtablewidgetitem27->setText(QApplication::translate("PADeviceList", "Unknown", 0));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget->item(10, 0);
        ___qtablewidgetitem28->setText(QApplication::translate("PADeviceList", "In port count:", 0));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget->item(10, 1);
        ___qtablewidgetitem29->setText(QApplication::translate("PADeviceList", "Unknown", 0));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget->item(11, 0);
        ___qtablewidgetitem30->setText(QApplication::translate("PADeviceList", "Out port count:", 0));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget->item(11, 1);
        ___qtablewidgetitem31->setText(QApplication::translate("PADeviceList", "Unknown", 0));
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem31->setToolTip(QApplication::translate("PADeviceList", "unknown", 0));
#endif // QT_NO_TOOLTIP
        tableWidget->setSortingEnabled(__sortingEnabled);

#ifndef QT_NO_TOOLTIP
        tableWidget->setToolTip(QString());
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class PADeviceList: public Ui_PADeviceList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PADEVICELIST_H
