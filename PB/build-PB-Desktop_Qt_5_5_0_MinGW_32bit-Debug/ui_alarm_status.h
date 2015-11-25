/********************************************************************************
** Form generated from reading UI file 'alarm_status.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALARM_STATUS_H
#define UI_ALARM_STATUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Alarm_Status
{
public:
    QVBoxLayout *verticalLayout_2;
    QFrame *home_frame_label_alarm_status;
    QVBoxLayout *verticalLayout;
    QLabel *home_label_alarm_status_1;
    QLabel *home_label_alarm_status_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Alarm_Status)
    {
        if (Alarm_Status->objectName().isEmpty())
            Alarm_Status->setObjectName(QStringLiteral("Alarm_Status"));
        Alarm_Status->resize(530, 390);
        Alarm_Status->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
""));
        verticalLayout_2 = new QVBoxLayout(Alarm_Status);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        home_frame_label_alarm_status = new QFrame(Alarm_Status);
        home_frame_label_alarm_status->setObjectName(QStringLiteral("home_frame_label_alarm_status"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(home_frame_label_alarm_status->sizePolicy().hasHeightForWidth());
        home_frame_label_alarm_status->setSizePolicy(sizePolicy);
        home_frame_label_alarm_status->setStyleSheet(QLatin1String("QFrame {\n"
"	margin: 10px;\n"
"	border: 1px solid rgb(124, 119, 119);\n"
"};"));
        home_frame_label_alarm_status->setFrameShape(QFrame::StyledPanel);
        home_frame_label_alarm_status->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(home_frame_label_alarm_status);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        home_label_alarm_status_1 = new QLabel(home_frame_label_alarm_status);
        home_label_alarm_status_1->setObjectName(QStringLiteral("home_label_alarm_status_1"));
        home_label_alarm_status_1->setMinimumSize(QSize(0, 30));
        home_label_alarm_status_1->setMaximumSize(QSize(16777211, 50));
        home_label_alarm_status_1->setStyleSheet(QLatin1String("QLabel {\n"
"	margin: 0px;\n"
"	background-color: rgb(189, 255, 233);\n"
"	color: blue;\n"
"	border-top: 0px;\n"
"	border-right: 0px;\n"
"	border-left: 0px;\n"
"}"));

        verticalLayout->addWidget(home_label_alarm_status_1);

        home_label_alarm_status_2 = new QLabel(home_frame_label_alarm_status);
        home_label_alarm_status_2->setObjectName(QStringLiteral("home_label_alarm_status_2"));
        home_label_alarm_status_2->setMinimumSize(QSize(0, 120));
        home_label_alarm_status_2->setStyleSheet(QLatin1String("QLabel {\n"
"	padding: 10px;\n"
"	color: green;\n"
"	background-color: white;\n"
"	margin: 0px;\n"
"	border: 0px;\n"
"}"));

        verticalLayout->addWidget(home_label_alarm_status_2);


        verticalLayout_2->addWidget(home_frame_label_alarm_status);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        retranslateUi(Alarm_Status);

        QMetaObject::connectSlotsByName(Alarm_Status);
    } // setupUi

    void retranslateUi(QWidget *Alarm_Status)
    {
        Alarm_Status->setWindowTitle(QApplication::translate("Alarm_Status", "Form", 0));
        home_label_alarm_status_1->setText(QApplication::translate("Alarm_Status", "Device Alarm Status", 0));
        home_label_alarm_status_2->setText(QApplication::translate("Alarm_Status", "No Alarms Present", 0));
    } // retranslateUi

};

namespace Ui {
    class Alarm_Status: public Ui_Alarm_Status {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALARM_STATUS_H
