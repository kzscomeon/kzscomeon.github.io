#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QKeyEvent>
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

protected:
    virtual void keyPressEvent(QKeyEvent* ev);

private:
    Ui::Widget *ui;
    QString copy;//粘贴板
};

#endif // WIDGET_H
