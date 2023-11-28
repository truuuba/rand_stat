#include "diagramm.h"
#include "ui_diagramm.h"
#include "redactor_numbers.cpp"


diagramm::diagramm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::diagramm)
{
    ui->setupUi(this);
    grafic = new QCustomPlot();
}

diagramm::~diagramm()
{
    delete ui;
}

Stat_for_diag stat_numbers;
void diagramm::slot(QVector<int> a)
{
    stat_numbers = count_vect(a);
    ui->grafic->clearGraphs();
    ui->grafic->addGraph();
    ui->grafic->graph(0)->setData(stat_numbers.get_orig_ch(), stat_numbers.get_amount_ch());
    ui->grafic->xAxis->setLabel("number");
    ui->grafic->yAxis->setLabel("count");
    ui->grafic->xAxis->setRange(minimum(stat_numbers.get_orig_ch()), maximum(stat_numbers.get_orig_ch()));
    ui->grafic->yAxis->setRange(0, maximum(stat_numbers.get_amount_ch()));
    ui->grafic->replot();
}
