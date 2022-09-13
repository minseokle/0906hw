#include "triangle.h"

Triangle::Triangle(QGraphicsScene*_scene):Shape(_scene)
{

}
void Triangle::Draw(double _x,double _y,double width,double high,QPen pen,QBrush brush)
{
    QPolygonF Triangle;
    Triangle.append(QPointF(-width/2,high/2));
    Triangle.append(QPointF(0.,-high/2));
    Triangle.append(QPointF(width/2,high/2));
    Triangle.append(QPointF(-width/2,high/2));

    item= scene->addPolygon(Triangle,pen,brush);

    x=_x;
    y=_y;
}
