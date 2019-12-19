#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QChartView>
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
struct perchHeader
{
    quint8 ver;     // version of the protocol
    quint8 hlen;    // lenght of the head
    quint8 ptype;   // packet type
    quint8 pcntr;   // number of packets
    quint8 dlen;    // dlen
    quint8 rsv;     // reserved
};
struct perchDataAmps
{
    quint16 len;     // lenght of the spectrm
    quint16 ref;      // number of spectrm
    quint16 amps;     // frame of the spectrm
    quint16 resv[];   // reserve variable lenght


};
void MainWindow::Read_perch()
{
    QByteArray head;
    QByteArray counter;
    QByteArray amplitude;
    /*QGraphicsScene scene;
    scene.addText("Amplitude Spectrum");
    QGraphicsView view(&scene);
    view.show();*/
    QNetworkDatagram datagram = socket->receiveDatagram();
    ui->textEdit->setText(datagram.senderAddress().toString());
    head = datagram.data();
    perchHeader *header = (perchHeader*)head.constData();
  //  perchDataAmps *amplituder = (perchDataAmps*)amplitude.swap();

    this->setWindowTitle(QString::number(header->ver, 16));
    ui->lcdNumber->display(header->pcntr);
  //  ui->textEdit_2->setText(amplituder->amps);
  //  ui->chart->chartclass
}
void MainWindow::Build_chart()
{

    //![1]
        QLineSeries *series = new QLineSeries();
    //![1]

    //![2]
        series->append(0, 6);
        series->append(2, 4);
        series->append(3, 8);
        series->append(7, 4);
        series->append(10, 5);
        *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);
    //![2]

    //![3]
        QChart *chart = new QChart();
        chart->legend()->hide();
        chart->addSeries(series);
        chart->createDefaultAxes();
        chart->setTitle("Simple line chart example");
    //![3]

    //![4]
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
    //![4]


    //![5]
        QMainWindow window;
        window.setCentralWidget(chartView);
        window.resize(400, 300);
        window.show();
        ui->chart->show();
    //![5]


}

