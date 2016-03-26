/********************************************************************************
** Form generated from reading UI file 'pacontrol.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PACONTROL_H
#define UI_PACONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PAControl
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *onRow;
    QPushButton *oncolumn;
    QPushButton *offRow;
    QPushButton *offColumn;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_4;
    QSpinBox *spinBox;
    QSlider *horizontalSlider;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QComboBox *comboBox;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QFrame *frame1;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_11;
    QPushButton *pushButton_10;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QSpacerItem *horizontalSpacer_2;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *PAControl)
    {
        if (PAControl->objectName().isEmpty())
            PAControl->setObjectName(QStringLiteral("PAControl"));
        PAControl->resize(1229, 588);
        verticalLayout = new QVBoxLayout(PAControl);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tableWidget = new QTableWidget(PAControl);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(tableWidget);

        groupBox = new QGroupBox(PAControl);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(0, 60));
        groupBox->setMaximumSize(QSize(16777215, 60));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        frame = new QFrame(groupBox);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        onRow = new QPushButton(frame);
        onRow->setObjectName(QStringLiteral("onRow"));
        onRow->setMinimumSize(QSize(0, 30));

        horizontalLayout_2->addWidget(onRow);

        oncolumn = new QPushButton(frame);
        oncolumn->setObjectName(QStringLiteral("oncolumn"));
        oncolumn->setMinimumSize(QSize(0, 30));

        horizontalLayout_2->addWidget(oncolumn);

        offRow = new QPushButton(frame);
        offRow->setObjectName(QStringLiteral("offRow"));
        offRow->setMinimumSize(QSize(0, 30));

        horizontalLayout_2->addWidget(offRow);

        offColumn = new QPushButton(frame);
        offColumn->setObjectName(QStringLiteral("offColumn"));
        offColumn->setMinimumSize(QSize(0, 30));

        horizontalLayout_2->addWidget(offColumn);


        horizontalLayout->addWidget(frame);

        frame_2 = new QFrame(groupBox);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_2);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        spinBox = new QSpinBox(frame_2);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMinimumSize(QSize(0, 30));
        spinBox->setAlignment(Qt::AlignCenter);
        spinBox->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBox->setMaximum(200);

        horizontalLayout_4->addWidget(spinBox);

        horizontalSlider = new QSlider(frame_2);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMinimumSize(QSize(0, 30));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(horizontalSlider);

        pushButton = new QPushButton(frame_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(0, 30));

        horizontalLayout_4->addWidget(pushButton);

        pushButton_2 = new QPushButton(frame_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 30));

        horizontalLayout_4->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(frame_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(0, 30));

        horizontalLayout_4->addWidget(pushButton_3);

        comboBox = new QComboBox(frame_2);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMinimumSize(QSize(0, 30));

        horizontalLayout_4->addWidget(comboBox);

        pushButton_4 = new QPushButton(frame_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(0, 30));

        horizontalLayout_4->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(frame_2);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(0, 30));

        horizontalLayout_4->addWidget(pushButton_5);


        horizontalLayout->addWidget(frame_2);

        frame1 = new QFrame(groupBox);
        frame1->setObjectName(QStringLiteral("frame1"));
        frame1->setFrameShape(QFrame::StyledPanel);
        frame1->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame1);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_11 = new QPushButton(frame1);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setMinimumSize(QSize(0, 30));

        horizontalLayout_3->addWidget(pushButton_11);

        pushButton_10 = new QPushButton(frame1);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setMinimumSize(QSize(0, 30));

        horizontalLayout_3->addWidget(pushButton_10);

        pushButton_12 = new QPushButton(frame1);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setMinimumSize(QSize(0, 30));

        horizontalLayout_3->addWidget(pushButton_12);

        pushButton_13 = new QPushButton(frame1);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setMinimumSize(QSize(0, 30));

        horizontalLayout_3->addWidget(pushButton_13);


        horizontalLayout->addWidget(frame1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(groupBox);

        textBrowser = new QTextBrowser(PAControl);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout->addWidget(textBrowser);


        retranslateUi(PAControl);

        QMetaObject::connectSlotsByName(PAControl);
    } // setupUi

    void retranslateUi(QWidget *PAControl)
    {
        PAControl->setWindowTitle(QApplication::translate("PAControl", "Form", 0));
        groupBox->setTitle(QString());
        onRow->setText(QApplication::translate("PAControl", "On Row", 0));
        oncolumn->setText(QApplication::translate("PAControl", "On Col", 0));
        offRow->setText(QApplication::translate("PAControl", "Off Row", 0));
        offColumn->setText(QApplication::translate("PAControl", "Off Col", 0));
        pushButton->setText(QApplication::translate("PAControl", "Send", 0));
        pushButton_2->setText(QApplication::translate("PAControl", "Max", 0));
        pushButton_3->setText(QApplication::translate("PAControl", "0", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("PAControl", "0.5", 0)
         << QApplication::translate("PAControl", "1", 0)
         << QApplication::translate("PAControl", "2", 0)
         << QApplication::translate("PAControl", "5", 0)
        );
        pushButton_4->setText(QApplication::translate("PAControl", "+", 0));
        pushButton_5->setText(QApplication::translate("PAControl", "-", 0));
        pushButton_11->setText(QApplication::translate("PAControl", "Lock", 0));
        pushButton_10->setText(QApplication::translate("PAControl", "Unlock", 0));
        pushButton_12->setText(QApplication::translate("PAControl", "All Lock", 0));
        pushButton_13->setText(QApplication::translate("PAControl", "All Unlock", 0));
    } // retranslateUi

};

namespace Ui {
    class PAControl: public Ui_PAControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PACONTROL_H
