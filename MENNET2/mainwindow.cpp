#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <iostream>
extern int RoadNode[MaxM][MaxN];
extern int row,col,pnum;
extern int num;
extern int ConnectNum;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize( QSize( 800,600 ));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event,Node *p)
{
    QPainter painter(this);
    QPen pen;//画笔
    QBrush brush(QColor(0,0,0,0));//painter
    QFont font("宋体",10, QFont::Bold, true);
    pen.setColor(QColor(0,0,0));
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.setFont(font);
    int i,j,k;
    row=6;col=6;
    QString infstr[MaxM][MaxN];
    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
            for(k=0;k<pnum;k++)
                if(p[k].GetM()==i&&p[k].GetN()==j)
                {
                    infstr[i][j]+=QString::number(p[k].GetNodeNo());
                    infstr[i][j]+="\n";
                }
    for(i=0;i<col;i++)
        for(j=0;j<row;j++)
        {
            QRectF rect(50+75*i,50+75*j,50,50);
            painter.drawRect(rect);
            painter.drawText(rect,Qt::AlignHCenter,infstr[i][j]);
        }
    //painter.drawRect(50,150,100,50);
    //painter.drawText(50,50,"Node1");
    //QRectF rect(20,20,300,200);


    //painter.drawRect(200,50,100,50);

}
