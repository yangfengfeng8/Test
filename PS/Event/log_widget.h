#ifndef LOG_WIDGET_H
#define LOG_WIDGET_H

#include <QWidget>
#include <QCloseEvent>

namespace Ui {
class Log_widget;
}

class Log_widget : public QWidget
{
    Q_OBJECT

public:
    explicit Log_widget(QWidget *parent = 0);
    ~Log_widget();

protected:
    void closeEvent(QCloseEvent *e);

public slots:
    void show_log(QString str);

private:
    Ui::Log_widget *ui;
};

#endif // LOG_WIDGET_H
