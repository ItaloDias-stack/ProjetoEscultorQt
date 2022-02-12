#ifndef MATRIX_H
#define MATRIX_H

#include <QWidget>
#include <string>
#include <vector>
struct  Obj {
  int r, g, b,a;
  int x,y,z;
};
class Matrix : public QWidget
{
    Q_OBJECT
public:
    std::vector<Obj> objs;
    int r=0, g=0, b=0;
    int z=1;
    explicit Matrix(QWidget *parent = nullptr);
    ~Matrix();
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent ( QMouseEvent * ev ) override;
    void mouseMoveEvent( QMouseEvent * ev) override;
    void mouseReleaseEvent(QMouseEvent * ev)override;
    void draw(int x,int y);
public slots:
    void setZValue(int z);
    void setRValue(int r);
    void setGValue(int g);
    void setBValue(int b);
private:
    std::string estado;
signals:

};

#endif // MATRIX_H
