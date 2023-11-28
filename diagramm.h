#ifndef DIAGRAMM_H
#define DIAGRAMM_H
#include <QDialog>
#include <qcustomplot.h>
#include <QDebug>

namespace Ui {
class diagramm;
}

class diagramm : public QDialog
{
    Q_OBJECT

public:
    explicit diagramm(QWidget *parent = nullptr);
    ~diagramm();

public slots:
    void slot(QVector<int> a);

private:
    Ui::diagramm *ui;
    QCustomPlot *grafic;
};

#endif // DIAGRAMM_H
