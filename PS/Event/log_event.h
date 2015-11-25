#ifndef LOG_EVENT_H
#define LOG_EVENT_H

#include <QWidget>

namespace Ui {
class Log_Event;
}

class Log_Event : public QWidget
{
    Q_OBJECT

public:
    explicit Log_Event(QWidget *parent = 0);
    ~Log_Event();

private:
    Ui::Log_Event *ui;
};

#endif // LOG_EVENT_H
