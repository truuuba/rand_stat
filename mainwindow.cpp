#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QComboBox>
#include <QMessageBox>
#include "methods.cpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    diag = new diagramm(this);
    connect(this, &MainWindow::signal_, diag, &diagramm::slot);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int s_end = 10;

bool MainWindow::validateItem(QString const &str, int a, int b)
{
    std::string convertedStr = str.toStdString();

    char *end_str;
    double res = std::strtof(convertedStr.c_str(), &end_str);

    return end_str == convertedStr.c_str() + convertedStr.size() && a <= res && res <= b;
}

bool MainWindow::prov_elem()
{
    bool pr_start = 1, pr_end = 1, pr_pic = 1, pr_count = 1;
    if(!validateItem(ui->min_values_Tr->text(), -1000, 1000) || ui->min_values_Tr->text().isEmpty())
        pr_start = 0;
    if(!validateItem(ui->max_values_Tr->text(), -1000, 1000) || ui->max_values_Tr->text().isEmpty())
        pr_end = 0;
    if(!validateItem(ui->peak_value_Tr->text(), -1000, 1000) || ui->peak_value_Tr->text().isEmpty())
        pr_pic = 0;
    if(!validateItem(ui->count_Tr->text(), 10, 1000) || ui->count_Tr->text().isEmpty())
        pr_count = 0;
    if(pr_count && pr_end && pr_pic && pr_start)
    {
        if ((ui->min_values_Tr->text().toInt() < ui->max_values_Tr->text().toInt()) && (ui->peak_value_Tr->text().toInt() >= ui->min_values_Tr->text().toInt())
        && (ui->peak_value_Tr->text().toInt() <= ui->max_values_Tr->text().toInt()))
            return true;
        else
            return false;
    }
    else
        return false;
}

void MainWindow::on_statistics_LK_clicked()
{
    int n;
    if(!validateItem(ui->count_LK->text(), 10, 1000) || ui->count_LK->text().isEmpty())
        QMessageBox::critical(this, "Ошибка!", "Пожалуйста, измените вводимые значения");
    else
    {
        n = ui->count_LK->text().toInt();
        QVector<int> results(n);
        results = LK_counter(n, s_end);
        emit signal_(results);
        diag->show();
    }
}


void MainWindow::on_values_LK_activated(int index)
{
    s_end = 10;
    if (index != 0)
    {
        for(int i = 0; i < index; i++)
            s_end *= 10;
    }
}


void MainWindow::on_statistics_Tr_clicked()
{
    int s_start, s_end, s_pic, s_count;
    if (prov_elem())
    {
        s_start = ui->min_values_Tr->text().toInt();
        s_end = ui->max_values_Tr->text().toInt();
        s_pic = ui->peak_value_Tr->text().toInt();
        s_count = ui->count_Tr->text().toInt();
        QVector<int> results = Tr_counter(s_start, s_end, s_pic, s_count);
        emit signal_(results);
        diag->show();
    }
    else
        QMessageBox::critical(this, "Ошибка!", "Пожалуйста, измените вводимые значения");
}


void MainWindow::on_statistics_Time_clicked()
{
    int n;
    if(!validateItem(ui->count_Time->text(), 10, 1000) || ui->count_Time->text().isEmpty())
        QMessageBox::critical(this, "Ошибка!", "Пожалуйста, измените вводимые значения");
    else
    {
        n = ui->count_Time->text().toInt();
        QVector<int> results(n);
        results = Time_counter(n, s_end);
        emit signal_(results);
        diag->show();
    }
}


void MainWindow::on_values_Time_activated(int index)
{
    s_end = 10;
    if (index != 0)
    {
        for(int i = 0; i < index; i++)
            s_end *= 10;
    }
}

