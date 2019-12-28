#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QChartView>
#include <QDebug>
#include <QVector>
#include "perch.h"
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
    QByteArray arr;
    QByteArray head;
    QVector<quint8> amplitude;
    perch_packet packet;
    //amplitude *ptr;
    //amplitude[0]= header->data;
    QByteArray counter;
   // QByteArray amplitude;
    /*QGraphicsScene scene;
    scene.addText("Amplitude Spectrum");
    QGraphicsView view(&scene);
    view.show();*/
    QNetworkDatagram datagram = socket->receiveDatagram();
    ui->textEdit->setText(datagram.senderAddress().toString());
    head = datagram.data();
    packet.headerr = (perchHeader*)head.constData();
    packet.perchAmp = (perchData*)(head.constData() + sizeof(perchHeader));
    packet.amps = (quint16*)(head.constData() + sizeof(perchHeader) + sizeof(perchData));
    for(int i = 0; i < packet.perchAmp->len; i++)
    {

        qDebug()<<packet.amps[i];
        ui->chart->series->append(packet.amps[i],500);

       // ui->textEdit_2->setText(packet.amps[i]);

    }
   // amplitude.push_front(header->data);
    //arr.push_front( header->data);
    //qDebug() << amplituder->amps;
   // this->setWindowTitle(QString::number(header->ver, 16));
   // qDebug() << amplitude;
   // ui->lcdNumber->display(he);
  //  ui->textEdit_2->setText(amplituder->amps);


}


