#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QLCDNumber>
#include <QGraphicsView>
#include <QLineSeries>

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
private slots:
    void Read_perch();
    //void Build_amps();
};


#endif // MAINWINDOW_H

