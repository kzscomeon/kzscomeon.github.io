#ifndef LABEL_H
#define LABEL_H

#include <QWidget>
#include <QKeyEvent>
#include <QLabel>
#include <QDebug>

class label : public QLabel
{
    Q_OBJECT
public:
    label(QWidget* parent = nullptr);
    virtual bool eventFilter(QObject *watched, QEvent *event);

protected:
    virtual void keyPressEvent(QKeyEvent* ev);

private:
    QString copy;
};

#endif // LABEL_H
