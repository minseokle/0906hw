#ifndef RECTANGLE_H
#define RECTANGLE_H
#include"shape.h"

class Rectangle:public Shape
{
public:
    Rectangle(QGraphicsScene*_scene);
    void Draw(double _x,double _y,double width,double high,QPen pen,QBrush brush);
};

#endif // RECTANGLE_H
