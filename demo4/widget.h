#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QDebug>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;

protected:
    virtual void mousePressEvent(QMouseEvent* ev);
    virtual void mouseReleaseEvent(QMouseEvent* ev);
    virtual void mouseMoveEvent(QMouseEvent* ev);
};


#endif // WIDGET_H
