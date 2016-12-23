#include "dialoginput.h"
#include "ui_dialoginput.h"

DialogInput::DialogInput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogInput)
{
    ui->setupUi(this);
    ui->InputM->setRange(0,MaxM);
    ui->InputN->setRange(0,MaxN);
    ui->InputP->setRange(0,MaxPnum);
}

DialogInput::~DialogInput()
{
    delete ui;
}

void DialogInput::on_buttonBox_clicked(QAbstractButton *button)
{
    row=ui->InputM->text().toInt();
    col=ui->InputN->text().toInt();
    pnum=ui->InputP->text().toInt();
    for(int i=0;i<pnum;i++)
        p[i].SetNode();
}


