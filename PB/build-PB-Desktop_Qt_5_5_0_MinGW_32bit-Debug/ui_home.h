/********************************************************************************
** Form generated from reading UI file 'home.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOME_H
#define UI_HOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Home
{
public:
    QVBoxLayout *verticalLayout_4;
    QFrame *home_frame_alarms;
    QVBoxLayout *verticalLayout;
    QLabel *home_label_alarms;
    QLabel *home_label_alarms_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_11;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_8;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_10;
    QLabel *label_13;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_14;
    QTableWidget *tableWidget_2;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *Home)
    {
        if (Home->objectName().isEmpty())
            Home->setObjectName(QStringLiteral("Home"));
        Home->resize(884, 673);
        Home->setStyleSheet(QLatin1String("QFrame {\n"
"	margin: 10px;\n"
"	border: 1px solid rgb(124, 119, 119);\n"
"}"));
        verticalLayout_4 = new QVBoxLayout(Home);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        home_frame_alarms = new QFrame(Home);
        home_frame_alarms->setObjectName(QStringLiteral("home_frame_alarms"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(home_frame_alarms->sizePolicy().hasHeightForWidth());
        home_frame_alarms->setSizePolicy(sizePolicy);
        home_frame_alarms->setStyleSheet(QStringLiteral(""));
        home_frame_alarms->setFrameShape(QFrame::StyledPanel);
        home_frame_alarms->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(home_frame_alarms);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        home_label_alarms = new QLabel(home_frame_alarms);
        home_label_alarms->setObjectName(QStringLiteral("home_label_alarms"));
        home_label_alarms->setMinimumSize(QSize(0, 30));
        home_label_alarms->setMaximumSize(QSize(16777211, 50));
        home_label_alarms->setStyleSheet(QLatin1String("QLabel {\n"
"	margin: 0px;\n"
"	background-color: rgb(189, 255, 233);\n"
"	color: blue;\n"
"	border-top: 0px;\n"
"	border-right: 0px;\n"
"	border-left: 0px;\n"
"}"));

        verticalLayout->addWidget(home_label_alarms);

        home_label_alarms_2 = new QLabel(home_frame_alarms);
        home_label_alarms_2->setObjectName(QStringLiteral("home_label_alarms_2"));
        home_label_alarms_2->setMinimumSize(QSize(0, 60));
        home_label_alarms_2->setStyleSheet(QLatin1String("QLabel {\n"
"	padding: 10px;\n"
"	color: green;\n"
"	background-color: white;\n"
"	margin: 0px;\n"
"	border: 0px;\n"
"}"));

        verticalLayout->addWidget(home_label_alarms_2);


        verticalLayout_4->addWidget(home_frame_alarms);

        frame = new QFrame(Home);
        frame->setObjectName(QStringLiteral("frame"));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMinimumSize(QSize(0, 220));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 30));
        label->setStyleSheet(QLatin1String("QLabel {\n"
"	margin: 0px;\n"
"	background-color: rgb(189, 255, 233);\n"
"	color: blue;\n"
"	border-top: 0px;\n"
"	border-right: 0px;\n"
"	border-left: 0px;\n"
"}"));

        verticalLayout_2->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QLatin1String("QLabel {\n"
"	padding-left: 10px;\n"
"	color: green;\n"
"	background-color: white;\n"
"	margin: 0px;\n"
"	border: 0px;\n"
"	padding: 5px;\n"
"}"));

        horizontalLayout->addWidget(label_2);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QLatin1String("QLabel {\n"
"	padding-left: 10px;\n"
"	color: green;\n"
"	background-color: white;\n"
"	margin: 0px;\n"
"	border: 0px;\n"
"	padding: 5px;\n"
"}"));

        horizontalLayout->addWidget(label_3);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QLatin1String("QLabel {\n"
"	padding-left: 10px;\n"
"	color: green;\n"
"	background-color: white;\n"
"	margin: 0px;\n"
"	border: 0px;\n"
"	padding: 5px;\n"
"}"));

        horizontalLayout_2->addWidget(label_4);

        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QLatin1String("QLabel {\n"
"	padding-left: 10px;\n"
"	color: green;\n"
"	background-color: white;\n"
"	margin: 0px;\n"
"	border: 0px;\n"
"	padding: 5px;\n"
"}"));

        horizontalLayout_2->addWidget(label_5);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_11 = new QLabel(frame);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setStyleSheet(QLatin1String("QLabel {\n"
"	padding-left: 10px;\n"
"	color: green;\n"
"	background-color: white;\n"
"	margin: 0px;\n"
"	border: 0px;\n"
"	padding: 5px;\n"
"}"));

        horizontalLayout_3->addWidget(label_11);

        label_12 = new QLabel(frame);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setStyleSheet(QLatin1String("QLabel {\n"
"	padding-left: 10px;\n"
"	color: green;\n"
"	background-color: white;\n"
"	margin: 0px;\n"
"	border: 0px;\n"
"	padding: 5px;\n"
"}"));

        horizontalLayout_3->addWidget(label_12);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setStyleSheet(QLatin1String("QLabel {\n"
"	padding-left: 10px;\n"
"	color: green;\n"
"	background-color: white;\n"
"	margin: 0px;\n"
"	border: 0px;\n"
"	padding: 5px;\n"
"}"));

        horizontalLayout_4->addWidget(label_6);

        label_7 = new QLabel(frame);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setStyleSheet(QLatin1String("QLabel {\n"
"	padding-left: 10px;\n"
"	color: green;\n"
"	background-color: white;\n"
"	margin: 0px;\n"
"	border: 0px;\n"
"	padding: 5px;\n"
"}"));

        horizontalLayout_4->addWidget(label_7);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_8 = new QLabel(frame);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setStyleSheet(QLatin1String("QLabel {\n"
"	padding-left: 10px;\n"
"	color: green;\n"
"	background-color: white;\n"
"	margin: 0px;\n"
"	border: 0px;\n"
"	padding: 5px;\n"
"}"));

        horizontalLayout_5->addWidget(label_8);

        label_9 = new QLabel(frame);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setStyleSheet(QLatin1String("QLabel {\n"
"	padding-left: 10px;\n"
"	color: green;\n"
"	background-color: white;\n"
"	margin: 0px;\n"
"	border: 0px;\n"
"	padding: 5px;\n"
"}"));

        horizontalLayout_5->addWidget(label_9);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_10 = new QLabel(frame);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setStyleSheet(QLatin1String("QLabel {\n"
"	padding-left: 10px;\n"
"	color: green;\n"
"	background-color: white;\n"
"	margin: 0px;\n"
"	border: 0px;\n"
"	padding: 5px;\n"
"}"));

        horizontalLayout_6->addWidget(label_10);

        label_13 = new QLabel(frame);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setStyleSheet(QLatin1String("QLabel {\n"
"	padding-left: 10px;\n"
"	color: green;\n"
"	background-color: white;\n"
"	margin: 0px;\n"
"	border: 0px;\n"
"	padding: 5px;\n"
"}"));

        horizontalLayout_6->addWidget(label_13);


        verticalLayout_2->addLayout(horizontalLayout_6);


        verticalLayout_4->addWidget(frame);

        frame_2 = new QFrame(Home);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy1);
        frame_2->setStyleSheet(QStringLiteral("background-color: white;"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_2);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(frame_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setMinimumSize(QSize(0, 30));
        label_14->setStyleSheet(QLatin1String("QLabel {\n"
"	margin: 0px;\n"
"	background-color: rgb(189, 255, 233);\n"
"	color: blue;\n"
"	border-top: 0px;\n"
"	border-right: 0px;\n"
"	border-left: 0px;\n"
"}"));

        verticalLayout_3->addWidget(label_14);

        tableWidget_2 = new QTableWidget(frame_2);
        if (tableWidget_2->columnCount() < 3)
            tableWidget_2->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (tableWidget_2->rowCount() < 4)
            tableWidget_2->setRowCount(4);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));
        tableWidget_2->setStyleSheet(QString::fromUtf8("QTableView, QHeaderView, QTableView::item {\n"
"    background: white;\n"
"	margin: 0px;\n"
"	border-left: 0px;\n"
"	border-top: 0px solid  rgb(124, 119, 119);\n"
"	min-height: 30px;\n"
"	border-bottom: 0px;\n"
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
        tableWidget_2->setGridStyle(Qt::SolidLine);
        tableWidget_2->setRowCount(4);
        tableWidget_2->setColumnCount(3);
        tableWidget_2->horizontalHeader()->setMinimumSectionSize(30);
        tableWidget_2->horizontalHeader()->setStretchLastSection(true);
        tableWidget_2->verticalHeader()->setVisible(false);
        tableWidget_2->verticalHeader()->setStretchLastSection(false);

        verticalLayout_3->addWidget(tableWidget_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        pushButton = new QPushButton(frame_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(0, 37));
        pushButton->setMaximumSize(QSize(80, 16777215));
        pushButton->setStyleSheet(QStringLiteral("background-color: url();"));

        horizontalLayout_7->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_7);


        verticalLayout_4->addWidget(frame_2);


        retranslateUi(Home);

        QMetaObject::connectSlotsByName(Home);
    } // setupUi

    void retranslateUi(QWidget *Home)
    {
        Home->setWindowTitle(QApplication::translate("Home", "Form", 0));
        home_label_alarms->setText(QApplication::translate("Home", "Action Alarms", 0));
        home_label_alarms_2->setText(QApplication::translate("Home", "No Alarms Present", 0));
        label->setText(QApplication::translate("Home", "Switched Power Station Parameters", 0));
        label_2->setText(QApplication::translate("Home", "Name:", 0));
        label_3->setText(QApplication::translate("Home", "Power Station", 0));
        label_4->setText(QApplication::translate("Home", "Contact:", 0));
        label_5->setText(QApplication::translate("Home", "Unknown", 0));
        label_11->setText(QApplication::translate("Home", "Location:", 0));
        label_12->setText(QApplication::translate("Home", "Unknown", 0));
        label_6->setText(QApplication::translate("Home", "Rating:", 0));
        label_7->setText(QApplication::translate("Home", "1\317\206\357\274\21416A ", 0));
        label_8->setText(QApplication::translate("Home", "User\357\274\232", 0));
        label_9->setText(QApplication::translate("Home", "Administrator", 0));
        label_10->setText(QApplication::translate("Home", "UpTime\357\274\232", 0));
        label_13->setText(QApplication::translate("Home", "0 Days 0 Hours 9 Minutes", 0));
        label_14->setText(QApplication::translate("Home", "Recent Device Events", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Home", "Date", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Home", "Time", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Home", "Event", 0));
        pushButton->setText(QApplication::translate("Home", "More Event", 0));
    } // retranslateUi

};

namespace Ui {
    class Home: public Ui_Home {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOME_H
