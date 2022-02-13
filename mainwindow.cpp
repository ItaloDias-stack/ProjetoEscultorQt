#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <windows.h>
#include <ShellAPI.h>
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
    this->ui->widget->r = value;
    ui->redValueLabel->setNum(value);
}


void MainWindow::on_greenSliderValue_valueChanged(int value)
{
    this->g = value;
    this->ui->widget->g = value;
    this->ui->greenValueLabel->setNum(value);
}


void MainWindow::on_blueValueSlider_valueChanged(int value)
{
    this->b = value;
    this->ui->widget->b = value;
    this->ui->blueValueLabel->setNum(value);
}


void MainWindow::on_opacityValueSlider_valueChanged(int value)
{
    this->a = value;
    this->ui->opacityValueLabel->setNum(value);
}

void MainWindow::generateOff()
{
    if(this->ui->widget->objs.size()>0){
        this->s =new Sculptor(100,100,100);
        for(int i = 0; i < this->ui->widget->objs.size();i++){
            int x = this->ui->widget->objs[i].x==0 ? 1 : this->ui->widget->objs[i].x;
            int y = this->ui->widget->objs[i].y==0 ? 1 : this->ui->widget->objs[i].y;
            int z = this->ui->widget->objs[i].z==0 ? 1 : this->ui->widget->objs[i].z;
            s->setColor(this->ui->widget->objs[i].r/255,this->ui->widget->objs[i].g/255,this->ui->widget->objs[i].b/255,this->ui->widget->objs[i].a/100);
            s->putVoxel(x,y,z);
        }
        s->writeOFF("escultura.off");
        ShellExecute(0,0,L"C:\\Users\\Italo Dias\\Documents\\NetBeansProjects\\CProjects\\build-ProjetoEscultorQt-Desktop_Qt_5_12_12_MinGW_64_bit-Debug\\escultura.off",0,0,SW_RESTORE);
    }
}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    this->ui->widget->setZValue(value);
}

