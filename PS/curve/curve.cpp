#include "curve.h"
#include <qwt/qwt_plot_curve.h>
#include <qwt/qwt_plot_canvas.h>
#include <qwt/qwt_legend.h>
#include <qwt/qwt_plot_zoomer.h>
#include <qwt/qwt_plot_magnifier.h>
#include <qwt/qwt_plot_picker.h>
#include <qwt/qwt_plot_panner.h>
#include <qwt/qwt_symbol.h>

Curve::Curve(int device_port, int ele_max,QColor color, QWidget *parent)
    : QwtPlot(parent),device_port(device_port),color(color),ele_max(ele_max)
{
    reset();

    setObjectName(tr("%1-%2 Real-Eletric").arg(device_port));
    setTitle(tr("实时电流"));

    setAxisTitle(QwtPlot::xBottom,"时间(s)");

    setAxisTitle(QwtPlot::yLeft,tr("电流(A)"));

    setAxisScale(QwtPlot::xBottom,x_min,x_max);

    setAxisScale(QwtPlot::yLeft,0.0,50.0);

    QwtPlotCanvas *canvas    = new QwtPlotCanvas;
    canvas->setPalette(QColor("#404040"));
    canvas->setBorderRadius(10);
    canvas->setFocusIndicator(QwtPlotCanvas::ItemFocusIndicator);
    setCanvas(canvas);

    insertLegend(new QwtLegend(),QwtPlot::RightLegend);

    QwtPlotZoomer *zoomer   = new QwtPlotZoomer(canvas);
    zoomer->setRubberBandPen(QPen(QColor(Qt::red),1));
    zoomer->setTrackerPen(QColor(Qt::red));

    zoomer->setMousePattern(QwtEventPattern::MouseSelect2,
                            Qt::RightButton,Qt::ControlModifier);
    zoomer->setMousePattern(QwtEventPattern::MouseSelect3,
                            Qt::RightButton);

    QwtPlotPanner *panner   = new QwtPlotPanner(canvas);
    panner->setMouseButton(Qt::MidButton);
    panner->setCursor(Qt::OpenHandCursor);
    panner->setEnabled(true);
    panner->setAxisEnabled(QwtPlot::yLeft,false);

    connect(panner,SIGNAL(panned(int,int)),this,SLOT(get_coord(int,int)));

    new QwtPlotMagnifier(this->canvas());

    QwtPlotPicker *m_picker = new QwtPlotPicker( QwtPlot::xBottom, QwtPlot::yLeft,
            QwtPlotPicker::HLineRubberBand , QwtPicker::AlwaysOn,
            this->canvas() );

    m_picker->setTrackerPen(QPen(Qt::red,1));
    QFont font;
    font.setPixelSize(15);
    m_picker->setTrackerFont(font);

    d_curve = new QwtPlotCurve(tr("支路%1").arg(device_port));
    d_curve->setSymbol(new QwtSymbol(QwtSymbol::Ellipse,Qt::blue,QPen(Qt::blue),QSize(5,5)));
    d_curve->setStyle(QwtPlotCurve::Lines);
    d_curve->setCurveAttribute( QwtPlotCurve::Fitted );
    d_curve->setPen(QPen(Qt::magenta));
    d_curve->setRenderHint(QwtPlotItem::RenderAntialiased,true);
    d_curve->attach(this);

    d_curve_Max = new QwtPlotCurve(tr("最大值"));
    d_curve_Max->setStyle(QwtPlotCurve::Lines);
    d_curve_Max->setCurveAttribute(QwtPlotCurve::Fitted);
    d_curve_Max->setPen(QPen(Qt::red));
    d_curve_Max->setRenderHint(QwtPlotItem::RenderAntialiased,true);
    d_curve_Max->attach(this);    
}

void Curve::recv_data(int device_port, int val)
{
    if(device_port != this->device_port){
        return ;
    }
    if(store.size() > 200){
        store.takeLast();
    }

    store.prepend(QPointF(count,val));

    count++;

    dis_points.clear();

    int temp    = (count-x_max <= 0 ? 0 : count-x_max);

    for(int i=temp;i<(store.size() < temp+17 ? store.size() : temp+17);i++){
        dis_points  += store.at(i);
    }
    d_curve->setSamples(dis_points);

    QPolygonF dis_points2;
    dis_points2 += QPointF((x_min-8 < 0 ? 0 : x_min - 8),ele_max);
    dis_points2 += QPointF(x_max+8,ele_max);
    d_curve_Max->setSamples(dis_points2);

    if(x_max <= count){
        setAxisScale(QwtPlot::xBottom,x_min,x_max);
        x_max++;
        x_min++;
    }

    replot();
}

void Curve::get_coord(int x, int y)
{
    y   = y;
    move_coord  = x;
    x_min   = x_min - move_coord/60;
    x_max   = x_max - move_coord/60;
}

void Curve::get_ele_max(int device_port,int ele_max)
{
    if(device_port != this->device_port){
        return ;
    }
    this->ele_max   = ele_max;

    replot();
}

void Curve::reset()
{
    count   = 0;
    move_coord  = 0;
    store.clear();
    x_min   = 0;
    x_max   = 5;
}


