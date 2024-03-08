#ifndef MAINWINDOW_H
#define win_h
#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QLayout>

class Counter:public QLineEdit
{
    Q_OBJECT
public:
    Counter(const QString & contents, QWidget *parent=0):
        QLineEdit(contents,parent){}
signals:
    void tick_signal();
public slots:
    void add_one();
};

class Win: public QWidget
{
    Q_OBJECT
protected:
    QLabel *label1,*label2;
    Counter *edit1,*edit2;
    QPushButton *calcbutton;
    QPushButton *exitbutton;
public:
    Win(QWidget *parent = 0);
};
#endif // MAINWINDOW_H
