#include "area.h"
Area::Area(QWidget *parent):QWidget(parent)
{
    setFixedSize(QSize(300,200));//параметры интерфейса
    myline=new MyLine(80,100,50);//размер и позиция линии
    myrect=new MyRect(220,100,50);//размер и позиция квадрата
    alpha=0;//угол разворота
}
//метод включения таймера
void Area::showEvent(QShowEvent *)
{
    myTimer=startTimer(50); // создать таймер
}
//метод отрисовки перемещающихся фигур;
void Area::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setPen(Qt::red);//цвет Pen
    myline->move(alpha,&painter);//разворот линии
    myrect->move(alpha*(-0.5),&painter);//разворот квадрата
}
//метод перерисовки Холста;
void Area::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == myTimer) // если наш таймер
    {
        alpha=alpha+0.2;//меняем угол
        update(); // обновить внешний вид
    }
    else
        QWidget::timerEvent(event); // иначе передать для стандартной
// обработки
}
//метод выключения таймера
void Area::hideEvent(QHideEvent *)
{
    killTimer(myTimer); // уничтожить таймер
}
Area::~Area()
{
    delete myline;
    delete myrect;
}
© 2022 GitHub, Inc.
Term
