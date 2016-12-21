#include "dialoginput.h"
#include "ui_dialoginput.h"

DialogInput::DialogInput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogInput)
{
    ui->setupUi(this);
}

DialogInput::~DialogInput()
{
    delete ui;
}

void DialogInput::on_buttonBox_clicked(QAbstractButton *button)
{
    int i;
    if(ui->InputM->text().trimmed().toInt()>0&&ui->InputM->text().trimmed().toInt()<=MaxM)
        row=ui->InputM->text().trimmed().toInt();
    if(ui->InputN->text().trimmed().toInt()>0&&ui->InputN->text().trimmed().toInt()<=MaxN)
        col=ui->InputN->text().trimmed().toInt();
    if(ui->InputP->text().trimmed().toInt()>0&&ui->InputP->text().trimmed().toInt()<=MaxPnum)
        pnum=ui->InputP->text().trimmed().toInt();
    for(i=0;i<pnum;i++)
        p[i].SetNode();
}


