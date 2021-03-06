#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QLCDNumber>
#include <QGraphicsView>
#include <QLineSeries>
#include "mychart.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QUdpSocket *socket;
    MyChart myChart;
private slots:
    void Read_perch();
    //void Build_amps();
    void on_pushButton_clicked();
};




#endif // MAINWINDOW_H

