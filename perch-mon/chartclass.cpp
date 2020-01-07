#include "chartclass.h"
#include <QLineSeries>
#include <QChart>
#include <QChartView>
#include "mainwindow.h"
#include "chartclass.h"
using namespace QtCharts;
chartclass::chartclass(QWidget *parent):
    QChartView(parent)
{


    series = new QLineSeries();
    chart = new QChart();
    chartView = new QChartView(chart);

}



