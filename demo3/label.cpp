#include "label.h"

label::label(QWidget *parent):
    QLabel(parent)
{

}

bool label::eventFilter(QObject *watched, QEvent *event)
{
    // 先判断事件派发方是否为当前控件的父控件
    if(watched != this->parent()){
        return false;
    }

    // 再判断发送过来的事件是否为键盘敲击事件
    if(event->type() != QEvent::KeyPress){
        return false;
    }

    // 剩下的就是目标事件了,直接手动调用目标事件函数
//  virtual void keyPressEvent(QKeyEvent* ev);
    QKeyEvent* ev = dynamic_cast<QKeyEvent*>(event);
    this->keyPressEvent(ev);

    return true;
}

void label::keyPressEvent(QKeyEvent *ev)
{
    QString str = this->text();
    int key = ev->key();
    Qt::KeyboardModifiers mod = ev->modifiers();

    if(key==Qt::Key_Backspace || key==Qt::Key_Delete || key==46){
        str.chop(1);
    }else if(mod==Qt::ControlModifier && key==Qt::Key_C){
        copy = this->text();
        qDebug() << copy << " 已复制";
    }else if(mod==Qt::ControlModifier && key==Qt::Key_X){
        copy = this->text();
        str.clear();
        qDebug() << copy << " 已剪切";
    }else if(mod==Qt::ControlModifier && key==Qt::Key_V){
        str += copy;
    }else{
        str += ev->text();
    }
    this->setText(str);
}
