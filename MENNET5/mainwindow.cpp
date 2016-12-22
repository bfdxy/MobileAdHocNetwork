#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize( QSize( 1440,960 ));
    //Width=QMainWindow.frameGeometry().width();
    timer=new QTimer(this);

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
                    infstr[i][j]+=" ";
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
                            infstr[i][j]+=" ";
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
            if(row>19||col>19)
                font.setPointSize(6);
            else if(row>14||col>14)
                font.setPointSize(10);
            else if(infstr[i][j].size()>5||row>9||col>9)
                font.setPointSize(12);
            else
                font.setPointSize(15);
            painter.setFont(font);
            painter.drawText(rect,Qt::TextWrapAnywhere,infstr[i][j]);
        }
}
void MainWindow::paint()
{
    if(ConnectPrecent[MoveNum]>9.99999)
        count=0;
    if(count==1)
    {
        for(int k=0;k<pnum;k++)
            p[k].Move();
        MoveNum++;
        Show(p,pnum);
        repaint();
    }
    else
    {
        QMessageBox::warning(this,"Move", "结点已全部连通！");
        if(timer->isActive())
        {
            timer->stop();
            ui->AutoMoveButton->setText("自动移动结点");
        }
    }
}

int MainWindow::count=1 ;

void MainWindow::on_pushButton_4_clicked()
{
    Widget *w=new Widget;
    w->show();
}

void MainWindow::on_AutoMoveButton_clicked()
{
    if(!(timer->isActive()))
    {
        timer=new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(paint())) ;
        timer->start(1000) ;//每隔1s
        ui->AutoMoveButton->setText("停止移动");
    }
    else
    {
        timer->stop();
        ui->AutoMoveButton->setText("自动移动结点");
    }
}

QString MainWindow::filename="";

void MainWindow::on_SaveButton_clicked()
{
    if(filename=="")
        filename=QFileDialog::getSaveFileName(this,"Save","file","*.txt");
    if(MoveNum==0)
        SaveTime0(filename);
    else
        SaveTime(filename);
    if(filename!="")
        QMessageBox::information(this,"Save", "保存成功！");
}

void MainWindow::on_InputButten_clicked()
{
    this->hide();
    DialogInput1.exec();
    this->show();
    Show(p,pnum);
}

void MainWindow::on_MoveButton_clicked()
{
    paint();
}

void MainWindow::on_pushButton_clicked()
{
    Q3InputDialog q3;
    q3.exec();
    ThirdProblem();
    Widget2 *w2=new Widget2;
    w2->show();
}


