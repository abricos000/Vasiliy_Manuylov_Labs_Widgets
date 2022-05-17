#include <math.h>
#include "figura.h"
void Figura::move(float Alpha,QPainter *Painter)
{
    dx=halflen*cos(Alpha);//координата вращения по оси x
    dy=halflen*sin(Alpha);//координата вращения по оси y
    draw(Painter);
}
void MyLine::draw(QPainter *Painter)
{
    Painter->drawLine(x+dx,y+dy,x-dx,y-dy);//отрисовка линии после вращения
}
void MyRect::draw(QPainter *Painter)
{
    //Отрисовываем линии стенок квадрата после вращения
    Painter->drawLine(x+dx,y+dy,x+dy,y-dx);
    Painter->drawLine(x+dy,y-dx,x-dx,y-dy);
    Painter->drawLine(x-dx,y-dy,x-dy,y+dx);
    Painter->drawLine(x-dy,y+dx,x+dx,y+dy);
}
