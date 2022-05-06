#ifndef WIN_H
#define WIN_H


#include <QBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>

// Данный счетчик будем строить на базе одного класса Counter, наследуемого от QLineEdit.

class Counter : public QLineEdit
{
    Q_OBJECT

public:
    Counter(const QString &contents, QWidget *parent = nullptr) : QLineEdit(contents, parent) {}

signals:
    void tick_signal();//В производном классе предусмотрим соответствующие сигнал tick_signal() и слот add_one() из рис.2.10

public slots:
    void add_one()
    {
        QString str = text();//Преобразуем строку в текст
        int r = str.toInt();//Преобразуем текст в число

        if (r != 0 && r % 5 == 0)
        {
            emit tick_signal();
        }

        r++;

        str.setNum(r);//Преобразуем число в текст
        setText(str);//показываем текст
    }
};

class Win : public QWidget
{
    Q_OBJECT

protected:
    //Создание объекта интерфейса
    QLabel *label1, *label2;
    Counter *edit1, *edit2;
    QPushButton *calcbutton;
    QPushButton *exitbutton;

public:
    Win(QWidget *parent = nullptr);
};


#endif // WIN_H
