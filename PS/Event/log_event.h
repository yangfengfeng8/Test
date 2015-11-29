#ifndef LOG_EVENT_H
#define LOG_EVENT_H

#include <QWidget>
#include "base.h"
#include "./Event/log_widget.h"

namespace Ui {
class Log_Event;
}

class Log_Event : public QWidget
{
    Q_OBJECT

public:
    explicit Log_Event(QWidget *parent = 0);
    ~Log_Event();

    //创建存储路径；
    bool create_dir();

    QString search_log(QString old_date,QString new_date,QString old_time,QString new_time);

    QString last_log();

    QString from_log();

public slots:
    void save_log(Device_Name name,QString str);

private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_radioButton_last_clicked(bool checked);

    void on_radioButton_From_clicked(bool checked);

    void on_apply_clicked();

    void on_clear_log_clicked();

    void on_create_new_window_clicked();

signals:
    void new_widget(QString);

private:
    Ui::Log_Event *ui;

    int flag;
    int index;
    int old_date;
    int old_time;
    int new_date;
    int new_time;

    QString str;
    Log_widget *log_widget;
};

#endif // LOG_EVENT_H
