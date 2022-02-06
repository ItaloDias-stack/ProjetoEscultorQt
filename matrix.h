#ifndef MATRIX_H
#define MATRIX_H

#include <QWidget>
#include <string>
#include <vector>
struct  Obj {
  int r, g, b;
  int x,y;
};
class Matrix : public QWidget
{
    Q_OBJECT
public:
    int r=0, g=0, b=0;
    explicit Matrix(QWidget *parent = nullptr);
    ~Matrix();
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent ( QMouseEvent * ev ) override;
    void mouseMoveEvent( QMouseEvent * ev) override;
    void mouseReleaseEvent(QMouseEvent * ev)override;
    void draw(int x,int y);
public slots:
    void setRValue(int r);
    void setGValue(int g);
    void setBValue(int b);
private:
    std::string estado;
protected:
    std::vector<Obj> objs;
signals:

};

#endif // MATRIX_H
