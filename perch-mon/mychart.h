#ifndef MYCHART_H
#define MYCHART_H

#include <QtCharts>
#include <QLineSeries>
#include <QtCharts>


class MyChart : public QChart
{
public:
    MyChart();

    void set(quint16* array, size_t length);
private:
    QLineSeries *lineSeries;
    QValueAxis *xAxis;
    QValueAxis *yAxis;
};

#endif // MYCHART_H
