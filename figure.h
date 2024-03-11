#ifndef FIGURE_H
#define FIGURE_H
#include <QPainter>

class Figure
{
protected:
    int x,y,halflen,dx,dy,r;
    virtual void draw(QPainter *Painter)=0; //объявляем для вызова в move
public:
    Figure(int X,int Y,int Halflen):x(X),y(Y),halflen(Halflen){}
    void move(float Alpha,QPainter *Painter);
};

class MyLine:public Figure
{
protected:
    void draw(QPainter *Painter);
public:
    MyLine(int x,int y,int halflen):Figure(x,y,halflen){}
};

class MyRect:public Figure
{
protected:
    void draw(QPainter *Painter);
public:
    MyRect(int x,int y,int halflen):Figure(x,y,halflen){}
};

#endif // FIGURE_H
