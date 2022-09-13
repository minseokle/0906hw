#include "shape.h"

Shape::Shape(QGraphicsScene *_scene)
{
    scene=_scene;
    x=0;
    y=0;
    rotate=0;
}
void Shape::Rotate(double deg)
{
    QTransform transform=item->transform();
    transform.rotate(deg);
    item->setTransform(transform);

    rotate+=deg;
    if(rotate>360)
        rotate-=360;
    else if(rotate<0)
        rotate+=360;
}
void Shape::Move(double _x,double _y)
{
    x+=_x;
    y+=_y;
    item->setPos(x,y);
}
