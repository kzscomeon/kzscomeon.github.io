#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mousePressEvent(QMouseEvent *ev)
{
    qDebug() << ev->pos();
}

void Widget::mouseReleaseEvent(QMouseEvent *ev)
{
    qDebug() << ev->pos();
}

void Widget::mouseMoveEvent(QMouseEvent *ev)
{
    qDebug() << ev->pos();
}
