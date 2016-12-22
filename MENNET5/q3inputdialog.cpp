#include "q3inputdialog.h"
#include "ui_q3inputdialog.h"

Q3InputDialog::Q3InputDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Q3InputDialog)
{
    ui->setupUi(this);
    ui->InputBox->setRange(0,MaxTime);
}

Q3InputDialog::~Q3InputDialog()
{
    delete ui;
}

void Q3InputDialog::on_buttonBox_accepted()
{
    Time=ui->InputBox->text().toInt();
}
