#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include <vector>
using namespace std;

class Plotter : public QWidget
{
    Q_OBJECT
private:
    float time;
    std::vector<double> tempos;
    std::vector<double> dados;
public:
    /**
     * @brief Plotter seta valores
     * @param parent
     */
    explicit Plotter(QWidget *parent = nullptr);
    /**
     * @brief paintEvent
     * @param e
     */
    void paintEvent(QPaintEvent *e);
    /**
     * @brief loadData
     */
    void loadData(vector <double>, vector <double>);

signals:

public slots:
};

#endif // PLOTTER_H
