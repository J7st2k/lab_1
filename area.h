#ifndef AREA_H
#define AREA_H
#include "figure.h"
#include <QWidget>
#include <QPaintEvent>
#include <QTimerEvent>
#include <QShowEvent>
#include <QHideEvent>

class Area:public QWidget
{
    int myTimer;    // идентификатор таймера
    float alpha;    // угол поворота
public:
    Area(QWidget *parent = 0);
    ~Area();
    MyLine *myline;
    MyRect *myrect;
protected:
        //обработчики событий
    void paintEvent(QPaintEvent *event);    //рисование фигур
    void timerEvent(QTimerEvent *event);    //инициация перерисовки холста
    void showEvent(QShowEvent *event);      //включение таймера
    void hideEvent(QHideEvent *event);      //выключение таймера
};
#endif // AREA_H
