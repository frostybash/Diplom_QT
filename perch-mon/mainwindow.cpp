#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug("log 1");
    socket.bind( QHostAddress::Any, 1025);
    qDebug("log 3");
    connect(&socket, SIGNAL(readyRead()),this,SLOT(Read_perch()));
    qDebug("log 2");
}

MainWindow::~MainWindow()
{
    delete ui;
}
struct perchHeader
{
    quint8 ver;     //version of the protocol
    quint8 hlen;    //lenght of the head
    quint8 ptype;   //packet type
    quint8 pcntr;   //number of packets
    quint8 dlen;    // dlen
    quint8 rsv;     // reserved
};
struct perchDataAmps
{
    quint16 len;     //lenght of the spectrm
    quint16 ref;      //number of spectrm
    quint16 amps;     //frame of the spectrm
   // quint16 resv[];   // reserve variable lenght


};
void MainWindow::Read_perch()
{
    QByteArray head;
    QByteArray counter;
    QNetworkDatagram datagram = socket.receiveDatagram();
    qDebug("log 5");
    ui->textEdit->setText(datagram.senderAddress().toString());
    qDebug("log 4");
    head = datagram.data();
    perchHeader *header = (perchHeader*)head.constData();
    this->setWindowTitle(QString::number(header->ver, 16));
    ui->lcdNumber->display(header->pcntr);
}
