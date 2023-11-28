#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QVector>
#include <QMainWindow>
#include <diagramm.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_statistics_LK_clicked();
    void on_values_LK_activated(int index);
    void on_statistics_Tr_clicked();
    void on_statistics_Time_clicked();
    void on_values_Time_activated(int index);
    bool validateItem(QString const &str, int a, int b);
    bool prov_elem();

signals:
    void signal_(QVector<int>);

private:
    Ui::MainWindow *ui;
    diagramm *diag;
};
#endif // MAINWINDOW_H
