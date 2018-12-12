#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>

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
   * @brief tcpConnect Conecta ao servidor
   */
  void tcpConnect(void);
  /**
   * @brief tcpDisconnect Desconecta do servidor
   */
  void tcpDisconnect(void);
  /**
   * @brief getData
   */
  void getData(void);
  /**
   * @brief stopData Para de colher dados do servidor
   */
  void stopData(void);
  /**
   * @brief updateIP Atualiza lista de clientes produtores conectados
   */
  void updateIP(void);
  /**
   * @brief timeEvent
   * @param e
   */
  void timeEvent(QTimerEvent *e);
private:
  Ui::MainWindow *ui;
  QTcpSocket *socket;
  int idTime;
};

#endif // MAINWINDOW_H
