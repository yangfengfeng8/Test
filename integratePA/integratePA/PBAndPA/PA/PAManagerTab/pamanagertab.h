#ifndef PAMANAGERTAB_H
#define PAMANAGERTAB_H

#include <QWidget>
#include <QTabWidget>

class PAControl;

namespace Ui {
class PAManagerTab;
}

class PAManagerTab : public QWidget
{
    Q_OBJECT

public:
    explicit PAManagerTab(QWidget *parent = 0);
    ~PAManagerTab();

    void initPAManagerTab();

    void initPATabwidget();

    void initPAControl();

private:
    Ui::PAManagerTab *ui;

    QTabWidget *tabWidget;

    PAControl *pAControl;
};

#endif // PAMANAGERTAB_H
