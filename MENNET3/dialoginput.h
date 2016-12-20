#ifndef DIALOGINPUT_H
#define DIALOGINPUT_H

#include "main.h"
#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class DialogInput;
}

class Node;

class DialogInput : public QDialog
{
    Q_OBJECT

public:
    explicit DialogInput(QWidget *parent = 0);
    ~DialogInput();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::DialogInput *ui;
};

#endif // DIALOGINPUT_H
