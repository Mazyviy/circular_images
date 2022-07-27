#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <QDebug>
#include <QPainter>
#include <random>

double sigm, ro1, ro2, stdl=1.0;
double n_x[400000], x[400000], ksi[400000],teta[400000],x1[400000],n_x1[400000];
int valueTurns = 150, valuePoints=2000;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Circular image");
}

MainWindow::~MainWindow()
{
    delete ui;
}

double normirovanie()
{
    double max, min;
    max = x[0];
    min = x[0];
    for (int i = 0; i < valueTurns*valuePoints; ++i) {
        if (x[i] < min) min = x[i];
        if ((x[i]) > max) max = x[i];
    }
    for (int i = 0; i < valueTurns*valuePoints; ++i) {
        n_x[i] = (x[i] - min) / (max - min);
    }
}
void normirovanie1()
{
    double max, min;
    max = x1[0];
    min = x1[0];
    for (int i = 0; i < valueTurns*valuePoints; ++i) {
        if (x1[i] < min) min = x1[i];
        if ((x1[i]) > max) max = x1[i];
    }
    for (int i = 0; i < valueTurns*valuePoints; ++i) {
        n_x1[i] = (x1[i] - min) / (max - min);
    }
}

void Habibi()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<double> distribution(0.0, 1.0);
    for (int i = 0; i < valueTurns*valuePoints; ++i) {
        ksi[i]=distribution(gen);
    }

    x[0] = sigm * ksi[0];
    for (int i = 1; i < valuePoints; ++i) {
        x[i] = ro2 * x[i - 1] + sigm * sqrt(1 - pow(ro2, 2)) * ksi[i];
    }
    for (int i = valuePoints; i < (valueTurns*valuePoints)-valuePoints; ++i) {
        x[i] = ro2 * x[i - 1] +ro1*x[i-valuePoints]-ro2*ro1*x[i-valuePoints-1]+sigm *
                sqrt((1 - pow(ro1, 2)) * (1 - pow(ro2, 2))) * ksi[i];
    }
}
void HabibiNoise(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<double> distribution1(0.0, stdl);
    for (int i = 0; i < valueTurns*valuePoints; ++i) {
        teta[i]=distribution1(gen);
    }
    for (int i = 0; i < valueTurns*valuePoints; ++i) {
       x1[i]=x[i]+teta[i];
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    sigm = ui->doubleSpinBox_2->value();
    ro1 = ui->doubleSpinBox_4->value();
    ro2 = ui->doubleSpinBox_3->value();
    valueTurns=ui->spinBox->value();
    valuePoints=ui->spinBox_2->value();

    Habibi();
    normirovanie();

    ui->label_4->FlagDraw = true;
    ui->label_4->update();
    ui->label_6->FlagDraw = false;
    ui->label_6->update();
    ui->label_7->FlagDraw = false;
    ui->label_7->update();
}

void MainWindow::on_pushButton_clicked()
{
    stdl=ui->doubleSpinBox->value();
    HabibiNoise();
    normirovanie1();

    ui->label_6->FlagDraw = true;
    ui->label_6->update();
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->label_7->FlagDraw = true;
    ui->label_7->update();
}
