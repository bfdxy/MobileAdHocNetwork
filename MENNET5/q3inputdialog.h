#ifndef Q3INPUTDIALOG_H
#define Q3INPUTDIALOG_H

#include <main.h>
#include <QDialog>

namespace Ui {
class Q3InputDialog;
}

class Q3InputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit Q3InputDialog(QWidget *parent = 0);
    ~Q3InputDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Q3InputDialog *ui;
};

#endif // Q3INPUTDIALOG_H
