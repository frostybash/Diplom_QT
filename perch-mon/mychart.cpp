#include "mychart.h"

MyChart::MyChart()
{
    // Setup axis
    xAxis = new QValueAxis();
    yAxis = new QValueAxis();

    xAxis->setTitleText("X");
    yAxis->setTitleText("Y");

    // Setup series
    lineSeries = new QLineSeries();
    lineSeries->setName("Amplitude");
    addSeries(lineSeries);

    // Setup chart
    setTitle("MyChart");
    addAxis(xAxis, Qt::AlignBottom);
    addAxis(yAxis, Qt::AlignLeft);

    lineSeries->attachAxis(xAxis);
    lineSeries->attachAxis(yAxis);


}

void MyChart::set(quint16 *array, size_t length)
{
    // Fill Vector array with points
    QVector<QPointF> points;
    qint16 maxValue = 0;

    for(int i = 0; i < length; i++)
    {
        points.push_back(QPointF(i, array[i]));

        if(array[i] > maxValue)
            maxValue = array[i];
    }

    // Replace points in series
    lineSeries->replace(points);

    // Once adjust axis to our range
    static bool oneTimeFlag = false;
    if(oneTimeFlag == false)
    {
        xAxis->setRange(0, length);
        yAxis->setRange(0, maxValue);

        oneTimeFlag = true;
    }
}
