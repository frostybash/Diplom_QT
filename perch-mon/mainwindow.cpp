#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QChartView>
#include <QDebug>
#include <QVector>
#include "perch.h"
#include "chartclass.h"
#include <QtMath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    socket = new QUdpSocket(this);
    ui->setupUi(this);
    socket->bind(QHostAddress::Any, 1025);
    connect(socket, SIGNAL(readyRead()),this,SLOT(Read_perch()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::Read_perch()
{
    QLineSeries *series = new QLineSeries();
    QChart *chart = new QChart();
    QChartView *chartView = new QChartView(chart);
    QByteArray head;
    perch_packet packet;

    QByteArray counter;
    QNetworkDatagram datagram = socket->receiveDatagram();
    ui->textEdit->setText(datagram.senderAddress().toString());
    head = datagram.data();
    packet.headerr = (perchHeader*)head.constData();
    packet.perchAmp = (perchData*)(head.constData() + sizeof(perchHeader));
    packet.amps = (quint16*)(head.constData() + sizeof(perchHeader) + sizeof(perchData));
    for(int i = 0; i < packet.perchAmp->len; i++)
    {

              series->append(packet.perchAmp->len, 1024);
              series->append(packet.headerr->ptype,100);

    }
    // series->append(packet.headerr->dlen, 2);

     ui->lcdNumber->display(packet.headerr->pcntr);

     ui->widget->chart->legend()->setVisible(true);
     ui->widget->chart->addSeries(series);
    // ui->widget->chart->createDefaultAxes();
     ui->widget->chart->legend()->setAlignment((Qt::AlignBottom));

     ui->widget->chartView->setRenderHint(QPainter::Antialiasing);
    // ui->widget->chartView->setChart();

}






