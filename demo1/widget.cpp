#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    flag = 1;
}

Widget::~Widget()
{
    qDebug() << "析构函数";
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    this->close();// 调用关闭事件
}

void Widget::closeEvent(QCloseEvent *ev)
{
    qDebug() << "关闭事件";
    if(flag==1){
        ev->accept();
    }else{
        ev->ignore();
    }

}

void Widget::hideEvent(QHideEvent *ev)
{
    qDebug() << "隐藏事件";
}

// 接受关闭事件
void Widget::on_pushButton_2_clicked()
{
    flag = 1;
}

// 忽略关闭事件
void Widget::on_pushButton_3_clicked()
{
    flag = 0;
}

void Widget::on_pushButton_4_clicked()
{
    this->hide();
}
