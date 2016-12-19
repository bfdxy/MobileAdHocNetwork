#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen pen;//画笔
    pen.setColor(QColor(255,0,0));
    QBrush brush(QColor(0,0,0,0));//painter
    painter.setPen(pen);
    painter.setBrush(brush);
    int i,j,k=0;
    int a[10][3];
    for(i=0;i<10;i++)
        for(j=0;j<3;j++)
            a[i][j]=i+j;
    QString s[10];
    for(i=0;i<10;i++)
        for(j=0;j<3;j++)
        {
            s[i]+=QString::number(a[i][j]);
            s[i]+="\n";
        }

    int row=10,col=10;
    for(i=0;i<col;i++)
        for(j=0;j<row;j++)
        {
            QRectF rect(50+150*i,50+150*j,100,100);
            painter.drawRect(rect);
            painter.drawText(rect,Qt::AlignHCenter,s[i]);
        }
    //painter.drawRect(50,150,100,50);
    //painter.drawText(50,50,"Node1");
    //QRectF rect(20,20,300,200);


    //painter.drawRect(200,50,100,50);

}
