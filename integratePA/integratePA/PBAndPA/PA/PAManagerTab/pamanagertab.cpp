#include "pamanagertab.h"
#include "ui_pamanagertab.h"

#include "pacontrol.h"

PAManagerTab::PAManagerTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PAManagerTab)
{
    ui->setupUi(this);

    initPAManagerTab();
}

PAManagerTab::~PAManagerTab()
{
    delete ui;
}

void PAManagerTab::initPAManagerTab()
{
    initPATabwidget();

    initPAControl();
}

void PAManagerTab::initPATabwidget()
{
    tabWidget   = ui->tabWidget;
    tabWidget->removeTab(1);
    tabWidget->removeTab(0);
    tabWidget->setTabsClosable(false);
    tabWidget->setStyleSheet("QTabWidget::pane{border: 0px solid green;margin: 1px;margin-bottom: 0px;}"
                             "QTabWidget::tab-bar{alignment:left;}"
                             "QTabBar::tab{background:transparent; color:black; min-width:22ex; min-height:25px;max-height:25px;}"
                             "QTabBar::tab:hover{background:rgb(255, 255, 255, 100);}"
                             "QTabBar::tab:selected{border-color: white;background:white;color:green;}"
                             "");
}

void PAManagerTab::initPAControl()
{
    pAControl   = new PAControl(this);
    tabWidget->addTab(pAControl,QString("Control"));

    pAControl->getDeviceType(QString("HBTE-PAM-8*8-4-63-0.5"));
}
