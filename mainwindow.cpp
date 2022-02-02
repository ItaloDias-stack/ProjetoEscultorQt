#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_redValueSlider_valueChanged(int value)
{
    this->r = value;
    ui->redValueLabel->setNum(value);
}


void MainWindow::on_greenSliderValue_valueChanged(int value)
{
     this->g = value;
}


void MainWindow::on_blueValueSlider_valueChanged(int value)
{
     this->b = value;
}


void MainWindow::on_opacityValueSlider_valueChanged(int value)
{
     this->a = value;
}

