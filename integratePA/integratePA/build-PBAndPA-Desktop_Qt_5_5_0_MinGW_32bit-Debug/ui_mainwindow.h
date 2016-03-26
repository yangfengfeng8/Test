/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QToolBox *toolBox;
    QWidget *page_1;
    QVBoxLayout *verticalLayoutPA;
    QWidget *page_2;
    QVBoxLayout *verticalLayoutPB;
    QWidget *page_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(925, 631);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        toolBox = new QToolBox(centralWidget);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolBox->sizePolicy().hasHeightForWidth());
        toolBox->setSizePolicy(sizePolicy);
        toolBox->setMinimumSize(QSize(300, 0));
        toolBox->setStyleSheet(QLatin1String("QToolBox::tab{\n"
"        background:transparent;\n"
"        color:black;\n"
"        min-width:22ex;\n"
"        min-height:25px;\n"
"        max-height:25px;\n"
"}\n"
"QToolBox::tab:hover{\n"
"        background:rgb(255, 255, 255, 100);\n"
"}\n"
"QToolBox::tab:selected{\n"
"        border-color: white;\n"
"        background:white;\n"
"        color:green;\n"
"}"));
        toolBox->setFrameShape(QFrame::StyledPanel);
        toolBox->setFrameShadow(QFrame::Sunken);
        page_1 = new QWidget();
        page_1->setObjectName(QStringLiteral("page_1"));
        page_1->setGeometry(QRect(0, 0, 352, 518));
        verticalLayoutPA = new QVBoxLayout(page_1);
        verticalLayoutPA->setSpacing(0);
        verticalLayoutPA->setContentsMargins(11, 11, 11, 11);
        verticalLayoutPA->setObjectName(QStringLiteral("verticalLayoutPA"));
        verticalLayoutPA->setContentsMargins(0, 0, 0, 0);
        toolBox->addItem(page_1, QStringLiteral("Programmable attenuator/matrix"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 352, 518));
        page_2->setMinimumSize(QSize(300, 0));
        verticalLayoutPB = new QVBoxLayout(page_2);
        verticalLayoutPB->setSpacing(0);
        verticalLayoutPB->setContentsMargins(11, 11, 11, 11);
        verticalLayoutPB->setObjectName(QStringLiteral("verticalLayoutPB"));
        verticalLayoutPB->setContentsMargins(0, 0, 0, 0);
        toolBox->addItem(page_2, QStringLiteral("Programmable power breaker"));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        page_3->setGeometry(QRect(0, 0, 352, 518));
        toolBox->addItem(page_3, QStringLiteral("Fiber switch/matrix"));

        horizontalLayout_2->addWidget(toolBox);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(widget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy1);
        scrollArea->setMinimumSize(QSize(571, 101));
        scrollArea->setMaximumSize(QSize(16777215, 100));
        scrollArea->setStyleSheet(QLatin1String("margin: 1px;\n"
"background-color: rgb(255, 255, 255);"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 567, 97));
        sizePolicy1.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        scrollAreaWidgetContents->setFont(font);
        scrollAreaWidgetContents->setStyleSheet(QStringLiteral("margin: 0px;"));
        horizontalLayout = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMaximumSize(QSize(16777215, 16777215));
        label->setStyleSheet(QLatin1String("background-color: rgb(252, 159, 36);\n"
"image: url(:/image/hbte.bmp);"));

        horizontalLayout->addWidget(label);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        horizontalLayout_2->addWidget(widget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 925, 18));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        toolBox->setCurrentIndex(0);
        toolBox->layout()->setSpacing(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        toolBox->setItemText(toolBox->indexOf(page_1), QApplication::translate("MainWindow", "Programmable attenuator/matrix", 0));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("MainWindow", "Programmable power breaker", 0));
        toolBox->setItemText(toolBox->indexOf(page_3), QApplication::translate("MainWindow", "Fiber switch/matrix", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
