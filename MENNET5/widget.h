#ifndef WIDGET_H
#define WIDGET_H

#include "main.h"
#include <QMainWindow>

namespace Ui {
class Widget;
}

class Widget : public QMainWindow
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    virtual bool eventFilter(QObject *watched, QEvent *e);
    void paintOnWidget(QWidget *w);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H*/
