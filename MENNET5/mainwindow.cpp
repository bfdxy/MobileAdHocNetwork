#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(QSize(1440,960));
    ui->ButtonWidget->setGeometry(0,this->size().height()-150,this->size().width(),100);
    timer=new QTimer(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    ui->ButtonWidget->setGeometry(0,this->size().height()-150,this->size().width(),100);
    int i,j,k;
    int leftWidth=50;
    int rightWidth=200;
    int width=this->size().width()-leftWidth-rightWidth-20;
    int height=this->size().height()-ui->ButtonWidget->size().height()-30;
    QString infstr[MaxM][MaxN];
    QPainter painter(this);
    QPen pen;//画笔
    QBrush brush(QColor(0,0,0,0));//painter
    pen.setColor(QColor(0,0,0));
    painter.setPen(pen);
    painter.setBrush(brush);
    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
            for(k=0;k<pnum;k++)
                if(p[k].GetM()==i&&p[k].GetN()==j)
                {
                    if(infstr[i][j]!="")
                        infstr[i][j]+=" ";
                    infstr[i][j]+=QString::number(p[k].GetNodeNo());
                }
    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
        {
            QFont font("黑体");
            int FontSize=50;
            font.setPixelSize(FontSize);
            painter.setFont(font);
            QFontMetrics fm=painter.fontMetrics();
            int textHeight=fm.lineSpacing();
            int textWidth=fm.width(infstr[i][j]);
            int RectWidth=width/col*0.75;
            int RectHeight=height/row*0.75;
            if(RectWidth<FontSize*2)
                FontSize=RectWidth;
            if(RectHeight<FontSize)
                FontSize=RectHeight;
            while((textWidth/RectWidth+1)*(textHeight-fm.leading())>RectHeight&&FontSize>5)
            {
                FontSize-=5;
                font.setPixelSize(FontSize);
                painter.setFont(font);
                fm=painter.fontMetrics();
                textHeight=fm.lineSpacing();
                textWidth=fm.width(infstr[i][j]);
                RectWidth=width/col*0.75;
                RectHeight=height/row*0.75;
            }
            QRectF rect(50+width/col*j,50+height/row*i,RectWidth,RectHeight);
            painter.drawRect(rect);
            painter.drawText(rect,Qt::AlignCenter|Qt::TextWrapAnywhere,infstr[i][j]);
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
        timer->start(500) ;//每隔0.7s
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


