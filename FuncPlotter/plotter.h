#ifndef PLOTTER_H
#define PLOTTER_H

#include <QMainWindow>
#include "qcustomplot.h"
#include "funcoes.h"

namespace Ui {
class Plotter;
}

class Plotter : public QMainWindow
{
    Q_OBJECT

public:
    explicit Plotter(QWidget *parent = 0);
    ~Plotter();

private:
    Ui::Plotter *ui;
};

#endif // PLOTTER_H
