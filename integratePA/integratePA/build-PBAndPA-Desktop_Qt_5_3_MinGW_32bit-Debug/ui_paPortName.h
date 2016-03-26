/********************************************************************************
** Form generated from reading UI file 'paPortName.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAPORTNAME_H
#define UI_PAPORTNAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_PAPortName
{
public:
    QGridLayout *gridLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_4;
    QGridLayout *gridLayout;
    QTableView *tableViewOut;
    QTableView *tableViewIn;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout_3;
    QPushButton *PubImport;
    QPushButton *PubExport;
    QPushButton *PubClear;
    QPushButton *PubOK;

    void setupUi(QDialog *PAPortName)
    {
        if (PAPortName->objectName().isEmpty())
            PAPortName->setObjectName(QStringLiteral("PAPortName"));
        PAPortName->resize(701, 373);
        gridLayout_2 = new QGridLayout(PAPortName);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(16);
        gridLayout_2->setVerticalSpacing(12);
        gridLayout_2->setContentsMargins(15, 9, 15, 9);
        label = new QLabel(PAPortName);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(309, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 0, 1, 1, 1);

        label_2 = new QLabel(PAPortName);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 0, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(308, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 0, 3, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tableViewOut = new QTableView(PAPortName);
        tableViewOut->setObjectName(QStringLiteral("tableViewOut"));
        tableViewOut->horizontalHeader()->setStretchLastSection(true);

        gridLayout->addWidget(tableViewOut, 0, 2, 1, 1);

        tableViewIn = new QTableView(PAPortName);
        tableViewIn->setObjectName(QStringLiteral("tableViewIn"));
        tableViewIn->horizontalHeader()->setStretchLastSection(true);

        gridLayout->addWidget(tableViewIn, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 4);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        PubImport = new QPushButton(PAPortName);
        PubImport->setObjectName(QStringLiteral("PubImport"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(75);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PubImport->sizePolicy().hasHeightForWidth());
        PubImport->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(PubImport, 0, 0, 1, 1);

        PubExport = new QPushButton(PAPortName);
        PubExport->setObjectName(QStringLiteral("PubExport"));
        sizePolicy.setHeightForWidth(PubExport->sizePolicy().hasHeightForWidth());
        PubExport->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(PubExport, 0, 1, 1, 1);

        PubClear = new QPushButton(PAPortName);
        PubClear->setObjectName(QStringLiteral("PubClear"));
        sizePolicy.setHeightForWidth(PubClear->sizePolicy().hasHeightForWidth());
        PubClear->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(PubClear, 0, 2, 1, 1);

        PubOK = new QPushButton(PAPortName);
        PubOK->setObjectName(QStringLiteral("PubOK"));
        sizePolicy.setHeightForWidth(PubOK->sizePolicy().hasHeightForWidth());
        PubOK->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(PubOK, 0, 3, 1, 1);


        gridLayout_2->addLayout(gridLayout_3, 2, 0, 1, 4);

        QWidget::setTabOrder(PubOK, tableViewOut);
        QWidget::setTabOrder(tableViewOut, PubImport);
        QWidget::setTabOrder(PubImport, PubExport);
        QWidget::setTabOrder(PubExport, tableViewIn);
        QWidget::setTabOrder(tableViewIn, PubClear);

        retranslateUi(PAPortName);

        QMetaObject::connectSlotsByName(PAPortName);
    } // setupUi

    void retranslateUi(QDialog *PAPortName)
    {
        PAPortName->setWindowTitle(QApplication::translate("PAPortName", "Dialog", 0));
        label->setText(QApplication::translate("PAPortName", "IN:", 0));
        label_2->setText(QApplication::translate("PAPortName", "OUT:", 0));
        PubImport->setText(QApplication::translate("PAPortName", "Import", 0));
        PubExport->setText(QApplication::translate("PAPortName", "Export", 0));
        PubClear->setText(QApplication::translate("PAPortName", "Default", 0));
        PubOK->setText(QApplication::translate("PAPortName", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class PAPortName: public Ui_PAPortName {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAPORTNAME_H
