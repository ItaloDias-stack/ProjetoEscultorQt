#include "matrix.h"
#include "QPainter"
#include "QBrush"
#include "QPen"
#include "QPoint"
#include <stdio.h>
#include <QMouseEvent>
Matrix::Matrix(QWidget *parent) : QWidget(parent)
{
}

Matrix::~Matrix()
{
}

void Matrix::paintEvent(QPaintEvent *event)
{
    // Set the image size:

    QPainter painter(this);
    QBrush brush;
    QPen pen;

    brush.setColor(QColor(240,240,240));
    brush.setStyle(Qt::SolidPattern);

    pen.setColor(QColor(0,0,0));
    pen.setWidth(1);

    painter.setBrush(brush);
    painter.setPen(pen);

    painter.drawRect(0,0,450,450);

    for(int x = 0; x<450 ;x=x+10){
        for(int y = 0; y<450 ;y=y+10){
            painter.drawRect(x,y,10,10);
        }
    }
    for(int x = 0; x<this->objs.size() ;x++){
        pen.setColor(QColor(objs[x].r,objs[x].g,objs[x].b));
        brush.setColor(QColor(objs[x].r,objs[x].g,objs[x].b));
        brush.setStyle(Qt::SolidPattern);
        painter.setPen(pen);
        painter.setBrush(brush);
        painter.drawEllipse((float) objs[x].x*10+2.5,(float)objs[x].y*10+2.5,7,7);
        //painter.drawRect(objs[x].x*10,objs[x].y*10,10,10);
    }
}

void Matrix::mousePressEvent(QMouseEvent *ev)
{
    QWidget::mousePressEvent(ev);
    this->estado="Clicou";
    if(ev->x() < 450 && ev->y() <450){
        draw(ev->x(),ev->y());
    }
    //printf()
}

void Matrix::mouseMoveEvent(QMouseEvent *ev)
{
    QWidget::mouseMoveEvent(ev);
    if(ev->x() < 450 && ev->y() <450){
        draw(ev->x(),ev->y());
    }

}

void Matrix::mouseReleaseEvent(QMouseEvent *ev)
{
    QWidget::mouseReleaseEvent(ev);
    this->estado="Liberou";
}


void Matrix::draw(int x, int y)
{
    Obj o;
    o.b = this->b;
    o.g = this->g;
    o.r = this->r;
    o.x = x/10;
    o.y = y/10;
    this->objs.push_back(o);
    repaint();
}

void Matrix::setRValue(int r)
{
    this->r = r;
}

void Matrix::setGValue(int g)
{
    this->g=g;
}

void Matrix::setBValue(int b)
{
    this->b=b;
}
