#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QCloseEvent>
#include <QDebug>
#include <QHideEvent>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

public slots:
    //bool close(){}

protected:
    virtual void closeEvent(QCloseEvent* ev);
    virtual void hideEvent(QHideEvent* ev);

private:
    Ui::Widget *ui;
    int flag;
};

#endif // WIDGET_H
