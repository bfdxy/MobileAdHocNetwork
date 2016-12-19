#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <iostream>
#include <QDebug>
extern int RoadNode[MaxM][MaxN];
extern int row,col,pnum;
extern int num;
extern int ConnectNum;
extern QString infstr[MaxM][MaxN];
extern Node p[MaxPnum];
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize( QSize( 1280,1280 ));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen pen;//画笔
    QBrush brush(QColor(0,0,0,0));//painter
    pen.setColor(QColor(0,0,0));
    painter.setPen(pen);
    painter.setBrush(brush);
    int i,j,k;   
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
            QRectF rect(50+125*i,50+125*j,100,100);
            painter.drawRect(rect);
            qDebug()<<infstr[i][j].size()<<"\n";
            int TextNum=8;
            if(infstr[i][j].size()<6)
                TextNum=15;
            QFont font("黑体",TextNum, QFont::Bold, true);
            painter.setFont(font);
            painter.drawText(rect,Qt::AlignHCenter,infstr[i][j]);
        }


}

void MainWindow::on_pushButton_clicked()
{
    int k;
    for(k=0;k<pnum;k++)
        p[k].Move();
    repaint();
}
