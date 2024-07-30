#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QBoxLayout>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>

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
    QWidget* tab3;
    QTextEdit* te;
    QLineEdit* le;
    QPushButton* btn;
    QHBoxLayout* hlay;
    QVBoxLayout* vlay;
    QWidget* w;
};

#endif // WIDGET_H
