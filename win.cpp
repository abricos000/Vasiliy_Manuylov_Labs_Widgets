#include "win.h"
Win::Win()
{
    setWindowTitle("Вращение фигур");
    area = new Area( this );
    btn = new QPushButton("Завершить");
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(area);
    layout->addWidget(btn);
    connect(btn, &QPushButton::clicked ,this, &Win::close);
};
