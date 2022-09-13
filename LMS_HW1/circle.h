#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"

class Circle:public Shape
{
public:
    Circle(QGraphicsScene*_scene);
    void Draw(double _x,double _y,double width,double high,QPen pen,QBrush brush);
};

#endif // CIRCLE_H
