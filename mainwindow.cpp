#include "mainwindow.h"

Win::Win(QWidget *parent):QWidget(parent)
{
    setWindowTitle("Возведение в квадрат");
    frame = new QFrame(this);                         //фрейм для группировки виджетов
    frame->setFrameShadow(QFrame::Raised);            //тень
    frame->setFrameShape(QFrame::Panel);              //форма
    inputLabel = new QLabel("Введите число:", this);
    inputEdit = new QLineEdit("", this);
    StrValidator *v=new StrValidator(inputEdit);      //валидатор для проверки типа данных, который поступает через inputEdit
    inputEdit->setValidator(v);
    outputLabel = new QLabel("Результат:", this);
    outputEdit = new QLineEdit("", this);
    nextButton = new QPushButton("Следующее", this);
    exitButton = new QPushButton("Выход", this);
        // компоновка приложения выполняется согласно рисунку 2

    QVBoxLayout *vLayout1 = new QVBoxLayout(frame);   //разметка, frame - родитель
    vLayout1->addWidget(inputLabel);
    vLayout1->addWidget(inputEdit);                   //элементы в левой части окна
    vLayout1->addWidget(outputLabel);
    vLayout1->addWidget(outputEdit);
    vLayout1->addStretch();                           //расстояние между элементами

    QVBoxLayout *vLayout2 = new QVBoxLayout();        //ещё одна разметка (только тепреь для элементов в правой части окна)
    vLayout2->addWidget(nextButton);
    vLayout2->addWidget(exitButton);
    vLayout2->addStretch();

    QHBoxLayout *hLayout = new QHBoxLayout(this);   //горизонтальная разметка для того, чтобы поместить
    hLayout->addWidget(frame);                      //все элементы 2х разметок на одном уровне по горизонтали
    hLayout->addLayout(vLayout2);

    begin(); //вызываем для первоначальной настройки

        //описываем сигналы, соединяем их со слотами
    connect(exitButton,SIGNAL(clicked(bool)), this, SLOT(close()));     //close прописан в родителе QWidget
    connect(nextButton,SIGNAL(clicked(bool)), this, SLOT(begin()));
    connect(inputEdit,SIGNAL(returnPressed()), this, SLOT(calc()));
}

void Win::begin() //слот первоначальной настройки/перенастройки
{
    inputEdit->clear();
    nextButton->setEnabled(false);
    nextButton->setDefault(false);
    inputEdit->setEnabled(true);
    outputLabel->setVisible(false);
    outputEdit->setVisible(false);
    outputEdit->setEnabled(false);
    inputEdit->setFocus();
}

void Win::calc()            //сам подсчёт
{
    bool Ok=true; float r,a;
    QString str=inputEdit->text();
    a=str.toDouble(&Ok);        //bool аргумент нужен для проверки ввода (true - число, false - другой символ)
    if (Ok)
    {
        r=a*a;
        str.setNum(r);          //r преобразуется в строку и заносится в str
        outputEdit->setText(str);
        inputEdit->setEnabled(false);
        outputLabel->setVisible(true);
        outputEdit->setVisible(true);
        nextButton->setDefault(true);
        nextButton->setEnabled(true);
        nextButton->setFocus();
    }
    else
        if (!str.isEmpty())     //условие нужно на случай, если при нажатии строка была пустой
        {
            QMessageBox msgBox(QMessageBox::Information, "Возведение в квадрат.", "Введено неверное значение.", QMessageBox::Ok);
            msgBox.exec();
        }
}
