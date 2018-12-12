#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QTextBrowser>
#include <QLabel>
#include <QLineEdit>
#include <QTimer>
#include <QLCDNumber>


MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent), ui(new Ui::MainWindow){
  ui->setupUi(this);
  socket = new QTcpSocket(this);
  //tcpConnect();

  connect(ui->pushButtonPut,
          SIGNAL(clicked(bool)),
          this,
          SLOT(putData()));
  connect(ui->pushButton_Stop,
          SIGNAL(clicked(bool)),
          this,
          SLOT(StopData()));
  connect(ui->pushButton_Connect,
          SIGNAL(clicked(bool)),
          this,
          SLOT(tcpConnect()));
  connect(ui->pushButton_Disconnect,
          SIGNAL(clicked(bool)),
          this,
          SLOT(tcpDisconnect()));
}

void MainWindow::tcpConnect(){
  //socket->connectToHost("127.0.0.1",1234);
  socket->connectToHost(getHost(),1234);
  if(socket->waitForConnected(3000)){
    qDebug() << "Connected";
  }
  else{
    qDebug() << "Disconnected";
  }
}
void MainWindow::tcpDisconnect(){
    socket->disconnectFromHost();
}

void MainWindow::putData(){
  QString timeStr;
  timeStr = ui->label_time->text();
  idTime = startTimer((timeStr.toInt())*1000);
}

QString MainWindow::getHost(){
    QString ip;

    ip = ui->lineEdit->text();

    return ip;
}
void MainWindow::StopData(){
    killTimer(idTime);
}
void MainWindow::timerEvent(QTimerEvent *t){
    QString str;
    int min, max;
    qint64 msecdate;

    max = ui->lcdNumber_Max->value();
    min = ui->lcdNumber_Min->value();

    if(min>max){
        ui->textBrowser->insertPlainText("Erro: O valor mínimo deve ser menor que o máximo!\n");
        killTimer(idTime);
    }
    else{
        if(socket->state()== QAbstractSocket::ConnectedState){

          msecdate = QDateTime::currentDateTime().toMSecsSinceEpoch();
          str = "set "+ QString::number(msecdate) + " " + QString::number(qrand()%(max - min) + min)+"\r\n";
          ui->textBrowser->append(str);

            qDebug() << str;
            qDebug() << socket->write(str.toStdString().c_str()) << " bytes written";
            if(socket->waitForBytesWritten(3000)){
              qDebug() << "wrote";
            }
        }
    }
}

MainWindow::~MainWindow(){
  delete socket;
  delete ui;
}
