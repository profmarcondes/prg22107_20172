#include "plotter.h"
#include "ui_plotter.h"

using namespace std;

Plotter::Plotter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Plotter)
{
    ui->setupUi(this);

    Seno f;

    FuncaoAgregada g;
    g.agrega(new Seno(new FuncaoAgregada(new Escalar(1), new Constante(2))));

    QCustomPlot * plot = ui->centralWidget;

    plot->addGraph();
    plot->addGraph();
    plot->graph(0)->setPen(QPen(Qt::blue));
    plot->graph(1)->setPen(QPen(Qt::red));
    plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

    double x = -10;
    while (x < 10){
       cout << "f(" << x << ") = " << f(x) << endl;
       plot->graph(0)->addData(x, f(x));
       plot->graph(1)->addData(x, g(x));
       x += 0.01;
    }

    plot->rescaleAxes();

    //plot->replot();

}

Plotter::~Plotter()
{
    delete ui;
}
