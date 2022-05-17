#ifndef FIGURA_H
#define FIGURA_H

#include <QtGui>
class Figura
{
    protected:
        int x,y,halflen,dx,dy,r;//определение переменных координат и размера фигуры
        virtual void draw(QPainter *Painter)=0;
    public:
        Figura(int X,int Y,int Halflen):
        x(X),y(Y),halflen(Halflen){}//конструктор размера и положения объекта
        void move(float Alpha,QPainter *Painter);
};
//Объявление класса линии
class MyLine:public Figura
{
    protected:
        void draw(QPainter *Painter);//метод рисования линии
    public:
        MyLine(int x,int y,int halflen):Figura(x,y,halflen){}//конструктор размерова и позиции
};
//Объявление класса квадрата
class MyRect:public Figura
{
    protected:
        void draw(QPainter *Painter);//метод рисования квадрата
    public:
        MyRect(int x,int y,int halflen):Figura(x,y,halflen){}//конструктор размера и позиции
};
#endif // FIGURA_H
