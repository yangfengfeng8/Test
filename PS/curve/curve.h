#ifndef CURVE_H
#define CURVE_H

#include <qwt/qwt_plot.h>
#include "base.h"

class QwtPlotCurve;

class Curve : public QwtPlot
{
    Q_OBJECT
public:
    Curve(int device_port,int ele_max,QColor color,QWidget *parent = 0);

signals:

public slots:
    void recv_data(int device_port,int val);

    void get_ele_max(int device_port, int ele_max);

    void reset();

private slots:
    void get_coord(int x,int y);

private:
    int device_port;

    QwtPlotCurve *d_curve;
    QwtPlotCurve *d_curve_Max;
    QColor color;

    QList<QPointF> store;
    QPolygonF dis_points;

    int move_coord;
    int count;
    int x_min;
    int x_max;

    int ele_max;
};

#endif // CURVE_H
