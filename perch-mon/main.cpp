#include "mainwindow.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;


    w.resize(1000, 500);

    w.show();

    return a.exec();
}
