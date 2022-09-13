#include "circle.h"

Circle::Circle(QGraphicsScene*_scene):Shape(_scene)
{

}
void Circle::Draw(double _x,double _y,double width,double high,QPen pen,QBrush brush)
{
    item=scene->addEllipse(_x-width/2,_y-high/2,width,high,pen,brush);
    x=_x;
    y=_y;
}

