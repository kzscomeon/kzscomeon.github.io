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


// 功能① ：键盘按什么键，在label上以追加的形式去获取
// 功能② ：当键盘按了 backspace 或者 del 键的时候，要求删除label上面最后一个字符
// 功能③ ：当键盘按了 ctrl+c 的时候，复制label里面的所有的文字，按ctrl+x的时候，剪切label里面的所有文字，按ctrl+v的时候，将复制或者剪切(也就是粘贴板里面保存的文字)的文字，以追加的形式站迭代当前label里面来
void Widget::keyPressEvent(QKeyEvent *ev)
{
    QString str = ui->label->text();
    int key = ev->key();    // 按的单键
    Qt::KeyboardModifiers mod = ev->modifiers();    // 按的组合键 ctrl,shift,alt
    //qDebug() << key;

    if(key==Qt::Key_Backspace || key==Qt::Key_Delete || key==46){
        // 删除label上面的最后一个字符
        str.chop(1);
    }else if(mod==Qt::ControlModifier && key==Qt::Key_C){
        // 复制
        copy = ui->label->text();
        qDebug() << copy << " 已复制";
    }else if(mod==Qt::ControlModifier && key==Qt::Key_X){
        copy = ui->label->text();
        str.clear();
        qDebug() << copy << " 已剪切";
    }else if(mod==Qt::ControlModifier && key==Qt::Key_V){
        str += copy;
    }else{
        str += ev->text();
    }
    ui->label->setText(str);

}
