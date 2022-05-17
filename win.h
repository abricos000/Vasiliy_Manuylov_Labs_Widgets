#ifndef WIN_H
#define WIN_H

#include <QWidget>
#include <QPushButton>
#include <QtGui>
#include <QVBoxLayout>
#include "area.h"
class Win : public QWidget
{
    protected:
        Area * area; // область отображения рисунка
        QPushButton * btn;// Объект кнопки
    public:
        Win();
};

#endif // WIN_H
