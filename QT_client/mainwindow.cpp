#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"
#include "string"
#include "winsock2.h"
#include <QApplication>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket();
    QObject::connect(socket,&QTcpSocket::readyRead,this,&MainWindow::on_ConnectButton_clicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ConnectButton_clicked()
{
    socket->abort();
    socket->connectToHost("192.168.43.136",1234);  // the ip of Raspberry Pi and the port of server
    if(!socket->waitForConnected(30000))
        ui->label->setText("Connection failure, try again!");
    else
        ui->label->setText("Connection successful！");
}

void MainWindow::on_UpButton_pressed()   //  perform up if UP Button is pressed
{
    socket->write("UPUP");
}

void MainWindow::on_UpButton_released()   //  stop if UP Button is released
{
    socket->write("STOP");
}

void MainWindow::on_BreakButton_clicked() // quit if BREAK Button is pressed
{
    socket->write("QUIT");
    ui->label->setText("OFF");            //  show OFF on the QT screen
}

void MainWindow::on_DownButton_pressed()  //  perform down if DOWN Button is pressed
{
    socket->write("DOWN");
}

void MainWindow::on_DownButton_released() //  stop if DOWN Button is released
{
    socket->write("STOP");
}

void MainWindow::on_LeftButton_pressed() //  perform left if LEFT Button is pressed
{
    socket->write("LEFT");
}

void MainWindow::on_LeftButton_released() //  stop if LEFT Button is released
{
    socket->write("STOP");
}

void MainWindow::on_RightButton_pressed() //  perform right if RIGHT Button is pressed
{
    socket->write("RIGHT");
}

void MainWindow::on_RightButton_released() //  stop if RIGHT Button is released
{
    socket->write("STOP");
}
