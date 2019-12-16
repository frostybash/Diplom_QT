#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket.bind( QHostAddress("192.168.0.11"), 1025);
    connect(&socket, SIGNAL(readyRead()),this,SLOT(Read_perch()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Read_perch()
{
    QNetworkDatagram datagram = socket.receiveDatagram();
    ui->textEdit->setText(datagram.senderAddress().toString());
    ui->textEdit->append(QString(datagram.data()));

}
