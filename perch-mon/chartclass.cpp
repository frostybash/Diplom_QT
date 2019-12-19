#include "chartclass.h"
#include <QLineSeries>
#include <QChart>
#include "mainwindow.h"
using namespace QtCharts;
chartclass::chartclass(QWidget *parent):
    QChartView(parent)
{


    series = new QLineSeries();
    chart = new QChart();
    chartView = new QChartView(chart);
   /* series->append(0,3);
    series->append(2,7);
    series->append(5,1);
    *series <<QPointF(11,1) <<QPointF(13,4) <<QPointF(2,7) <<QPointF(17,6);
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("Amplitude Spectrum");
    chartView->setRenderHint((QPainter::Antialiasing));
    /*QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(0,10);
    window.show();*/
    for(int i=0; i<10;i++)
    series->append(i,i*i);

    chart->addSeries(series);
    chart->setTitle("Amplitude spectrum");
    //add x axis to the chart
    QDateTimeAxis *axisX = new QDateTimeAxis;
    axisX->setTickCount(100);
    chart->addAxis(axisX,Qt::AlignBottom);
    series->attachAxis(axisX);
    //add y axis to the chart
    QValueAxis *axisY = new QValueAxis;
    axisY->setLabelFormat ("%i");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);



    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
   // setCentralWidget(chartView);
}

