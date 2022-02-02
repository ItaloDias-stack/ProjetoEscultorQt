#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sculptor.h"
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
    void on_redValueSlider_valueChanged(int value);

    void on_greenSliderValue_valueChanged(int value);

    void on_blueValueSlider_valueChanged(int value);

    void on_opacityValueSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    int r,g,b,a;
    Sculptor *s;
    int dimX,dimY,dimZ;
};
#endif // MAINWINDOW_H
