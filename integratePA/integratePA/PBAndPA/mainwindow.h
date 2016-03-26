#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QSplitter>
#include <QLabel>

class PADeviceList;
class PAManagerTab;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void initMainWindow();

    void initLayout();

    void addStatusBar();

    void initPA();

    void initPADeviceList();

    void initPAManagerTab();

protected:
    void closeEvent(QCloseEvent *);

    void resizeEvent(QResizeEvent *);

public slots:
    void errors(const QString &Str);

signals:
    void closed();

private:
    Ui::MainWindow *ui;

    PADeviceList *pADeviceList;
    PAManagerTab *pAManagerTab;

    QSplitter *splitter;

    QLabel *label_bar_url;
    QLabel *label_device_name_bar;
    QLabel *label_ip_bar;
    QLabel *label_status;
    QLabel *label_user;
};

#endif // MAINWINDOW_H
