#ifndef CHARTCLASS_H
#define CHARTCLASS_H
#include <QObject>
#include <QWidget>
#include <QChartView>
#include <QLineSeries>
#include <QtCharts>
QT_CHARTS_USE_NAMESPACE


class chartclass : public QChartView
{
public:
    chartclass(QWidget *parent);
    QLineSeries *series;
    QChart *chart;
    QChartView *chartView;
};



#endif // CHARTCLASS_H
