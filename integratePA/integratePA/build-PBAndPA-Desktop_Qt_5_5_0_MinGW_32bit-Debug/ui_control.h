/********************************************************************************
** Form generated from reading UI file 'control.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROL_H
#define UI_CONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Control
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QSpinBox *spinBox;
    QSlider *horizontalSlider;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QComboBox *comboBox;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *Control)
    {
        if (Control->objectName().isEmpty())
            Control->setObjectName(QStringLiteral("Control"));
        Control->resize(664, 588);
        verticalLayout = new QVBoxLayout(Control);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableWidget = new QTableWidget(Control);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        groupBox = new QGroupBox(Control);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        horizontalLayout->addWidget(spinBox);

        horizontalSlider = new QSlider(groupBox);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout->addWidget(comboBox);

        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        horizontalLayout->addWidget(pushButton_5);


        verticalLayout->addWidget(groupBox);

        textBrowser = new QTextBrowser(Control);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout->addWidget(textBrowser);


        retranslateUi(Control);

        QMetaObject::connectSlotsByName(Control);
    } // setupUi

    void retranslateUi(QWidget *Control)
    {
        Control->setWindowTitle(QApplication::translate("Control", "Form", 0));
        groupBox->setTitle(QString());
        pushButton->setText(QApplication::translate("Control", "PushButton", 0));
        pushButton_2->setText(QApplication::translate("Control", "PushButton", 0));
        pushButton_3->setText(QApplication::translate("Control", "PushButton", 0));
        pushButton_4->setText(QApplication::translate("Control", "PushButton", 0));
        pushButton_5->setText(QApplication::translate("Control", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class Control: public Ui_Control {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROL_H
