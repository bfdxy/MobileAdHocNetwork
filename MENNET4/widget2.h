#ifndef WIDGET2_H
#define WIDGET2_H

#include "main.h"
#include <QMainWindow>

namespace Ui {
class Widget;
}

class Widget2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Widget2(QWidget *parent = 0);
    ~Widget2();

protected:
    virtual void changeEvent(QEvent *e);
    virtual bool eventFilter(QObject *watched, QEvent *e);
    void paintOnWidget2(QWidget *w);

private:
    Ui::Widget *ui;
};

#endif // WIDGET2_H
