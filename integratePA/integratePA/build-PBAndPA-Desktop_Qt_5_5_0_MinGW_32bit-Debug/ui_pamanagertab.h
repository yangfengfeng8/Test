/********************************************************************************
** Form generated from reading UI file 'pamanagertab.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAMANAGERTAB_H
#define UI_PAMANAGERTAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PAManagerTab
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;

    void setupUi(QWidget *PAManagerTab)
    {
        if (PAManagerTab->objectName().isEmpty())
            PAManagerTab->setObjectName(QStringLiteral("PAManagerTab"));
        PAManagerTab->resize(721, 569);
        verticalLayout = new QVBoxLayout(PAManagerTab);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(PAManagerTab);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(PAManagerTab);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(PAManagerTab);
    } // setupUi

    void retranslateUi(QWidget *PAManagerTab)
    {
        PAManagerTab->setWindowTitle(QApplication::translate("PAManagerTab", "Form", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("PAManagerTab", "Tab 1", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("PAManagerTab", "Tab 2", 0));
    } // retranslateUi

};

namespace Ui {
    class PAManagerTab: public Ui_PAManagerTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAMANAGERTAB_H
