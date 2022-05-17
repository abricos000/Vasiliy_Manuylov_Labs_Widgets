#ifndef AREA_H
#define AREA_H

#include "figura.h"
#include <QWidget>
class Area : public QWidget
{//поля класса
    int myTimer; // идентификатор таймера
    float alpha; // угол поворота
    public:
    Area(QWidget *parent = 0);
    ~Area();
    MyLine *myline;//Создание экземпляра объекта линии
    MyRect *myrect;//Создание экземпляра объект квадрата
protected:
//обработчики событий
    void paintEvent(QPaintEvent *event);//рисование пошагово перемещающихся фигур;
    void timerEvent(QTimerEvent *event);//инициация перерисовки Холста;
    void showEvent(QShowEvent *event);//включение таймера;
    void hideEvent(QHideEvent *event);//выключение таймера.
};
#endif // AREA_H
