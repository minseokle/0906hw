#ifndef SHAPE_H
#define SHAPE_H

#include <QGraphicsScene>
#include<QGraphicsItem>

class Shape
{
public:
    Shape(QGraphicsScene *_scene);
    ~Shape();
    virtual void Draw(double _x,double _y,double width,double high,QPen pen,QBrush brush)=0;
    void Rotate(double deg);
    void Move(double _x,double _y);
protected:
    double x,y,rotate;
    QGraphicsScene *scene;
    QGraphicsItem *item;

};

#endif // SHAPE_H
