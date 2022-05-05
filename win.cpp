#include "win.h"

Win::Win(QWidget *parent)
    : QWidget(parent)
{

    setWindowTitle("Возведение в квадрат");

    frame = new QFrame(this);//Делаем выделение памяти для рамки
    frame->setFrameShadow(QFrame::Raised);
    frame->setFrameShape(QFrame::Panel);

    inputLabel = new QLabel("Введите число:", this);//Текст к полю ввода числа
    inputEdit = new QLineEdit("", this);// Поле ввода числа
    outputLabel = new QLabel("Результат:", this);//Текст к полю выводв результата
    outputEdit = new QLineEdit("", this);//Поле вывода результата
    nextButton = new QPushButton("Следующее", this);//кнопка для следующего вычесления
    exitButton = new QPushButton("Выход", this);//Кнопка выхода

    QVBoxLayout *vLayout1 = new QVBoxLayout(frame);//создание объекта
    //добавление полей в BoxLayout
    vLayout1->addWidget(inputLabel);
    vLayout1->addWidget(inputEdit);
    vLayout1->addWidget(outputLabel);
    vLayout1->addWidget(outputEdit);
    vLayout1->addStretch();

    QVBoxLayout *vLayout2 = new QVBoxLayout();//создание объекта
    //добавление полей в BoxLayout
    vLayout2->addWidget(nextButton);
    vLayout2->addWidget(exitButton);
    vLayout2->addStretch();

    QHBoxLayout *hLayout = new QHBoxLayout(this);//создание объекта
    //добавление полей в BoxLayout
    hLayout->addWidget(frame);
    hLayout->addLayout(vLayout2);

    begin();
   //Сигналы
    connect(exitButton, &QPushButton::clicked, this, &Win::close);//закрытие окна
    connect(nextButton, &QPushButton::clicked, this, &Win::begin);//переход к следующему вычислению
    connect(inputEdit, &QLineEdit::returnPressed, this, &Win::calc);//вывод результата при нажатии клавиши Enter
}
void Win::begin()
{
    inputEdit->clear();//удаление предыдущего результата
    nextButton->setEnabled(false);//отлючаем кнопку
    inputEdit->setEnabled(true);//активируем поле
    outputLabel->setVisible(false);//виджет невидим
    outputEdit->setVisible(false);//виджет невидим
    outputEdit->setEnabled(false);//отлючаем ввод в данное поле
    inputEdit->setFocus();//ставим фокус
}

void Win::calc()
{
    bool Ok = true;
    float r, a;

    QString str = inputEdit->text();
    a = str.toDouble(&Ok);

    if (Ok)
    {
        r = a * a;

        str.setNum(r);

        outputEdit->setText(str);//вывод результата
        inputEdit->setEnabled(false);//отлючаем ввод в данное поле
        outputLabel->setVisible(true);//виджет видим
        outputEdit->setVisible(true);//виджет видим
        nextButton->setDefault(true);
        nextButton->setEnabled(true);//активируем кнопку
        nextButton->setFocus();//ставим фокус
    }
    else if (!str.isEmpty())
    {
        //вывод сообщения об ошибке
        QMessageBox msgBox(QMessageBox::Information, "Возведение в квадрат.", "Введено неверное значение.", QMessageBox::Ok);
        msgBox.exec();
    }
}
