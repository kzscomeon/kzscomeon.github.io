#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    tab3 = new QWidget();
    ui->tabWidget->addTab(tab3,"标签3");

    QWidget* tab1 = ui->tabWidget->widget(0);
    te = new QTextEdit(tab1);
    w = new QWidget(tab1);
    le = new QLineEdit(w);
    btn = new QPushButton(w);
    hlay = new QHBoxLayout(w);
    hlay->addWidget(le);
    hlay->addWidget(btn);

    vlay = new QVBoxLayout(tab1);
    vlay->addWidget(te);
    vlay->addWidget(w);

}

Widget::~Widget()
{
    delete tab3;
    delete ui;
}
