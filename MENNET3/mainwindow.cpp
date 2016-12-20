#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize( QSize( 1440,960 ));
    Show(p);
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
    QFont font("黑体",8);
    painter.setPen(pen);
    painter.setBrush(brush);
    int i,j,k,l;
    QString infstr[MaxM][MaxN];
    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
        {
            for(k=0;k<pnum;k++)
                if(p[k].GetM()==i&&p[k].GetN()==j)
                {
                    infstr[i][j]+=QString::number(p[k].GetNodeNo());
                    infstr[i][j]+="\n";
                }
            if(infstr[i][j].size()>9)
            {
                infstr[i][j]="";
                for(k=0,l=0;k<pnum;k++)
                    if(p[k].GetM()==i&&p[k].GetN()==j)
                    {
                        infstr[i][j]+=QString::number(p[k].GetNodeNo());
                        if(l==0)
                        {
                            infstr[i][j]+=" ";
                            l=1;
                        }
                        else
                        {
                            infstr[i][j]+="\n";
                            l=0;
                        }
                    }
            }
        }
    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
        {
            QRectF rect(50+1400/col*j,50+900/row*i,1400/col*0.75,900/row*0.75);
            painter.drawRect(rect);
            if(infstr[i][j].size()<6)
                font.setPointSize(15);
            else
                font.setPointSize(10);
            painter.setFont(font);
            painter.drawText(rect,Qt::AlignHCenter,infstr[i][j]);
        }
}

void MainWindow::on_pushButton_clicked()
{
    int k;
    for(k=0;k<pnum;k++)
        p[k].Move();
    MoveNum++;
    Show(p);
    repaint();
}
