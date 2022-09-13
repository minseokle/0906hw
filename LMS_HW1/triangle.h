#ifndef TRIANGLE_H
#define TRIANGLE_H
#include"shape.h"


class Triangle:public Shape
{
public:
    Triangle(QGraphicsScene*_scene);
    void Draw(double _x,double _y,double width,double high,QPen pen,QBrush brush);
};

#endif // TRIANGLE_H
