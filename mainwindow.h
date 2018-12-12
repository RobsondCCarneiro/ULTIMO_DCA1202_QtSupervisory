#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  
public slots:
    /**
   * @brief tcpConnect conecta com o servidor
   */
  void tcpConnect();
  /**
   * @brief putData Pega o host (endereco IP) fornecido pelo usuario para usar na funcao tcpConnect()
   */
  void putData();
  /**
   * @brief StopData Serve para parar de enviar dados para o servidor
   */
  void StopData();
  /**
   * @brief tcpDisconnect desconecta o servidor
   */
  void tcpDisconnect();
  /**
   * @brief timerEvent para repetir o putData() com a quantidade de milissegundos fornecidos pelo usuario
   * @param t
   */
  void timerEvent(QTimerEvent *t);
  /**
   * @brief getHost pega o Host para usar na funcao tcpConnect()
   * @return
   */
  QString getHost();

private:
  Ui::MainWindow *ui;
  QTcpSocket *socket;
  int idTime;
};

#endif // MAINWINDOW_H
