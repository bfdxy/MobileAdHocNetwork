#include "widget2.h"
#include "ui_widget.h"
#include <QtGui/QPainter>

Widget2::Widget2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->installEventFilter(this);
}

Widget2::~Widget2()
{
    delete ui;
}

void Widget2::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch(e->type())
    {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
bool Widget2::eventFilter(QObject *watched, QEvent *e)
{
    if(watched==this)
    {
        if(e->type()==QEvent::Paint)
        {
            paintOnWidget2(this);
            return true;
        }
    }
    return QWidget::eventFilter(watched,e);
}

void Widget2::paintOnWidget2(QWidget *w)
{
    QPainter painter(w);
    painter.setRenderHint(QPainter::Antialiasing,true);//设置反锯齿模式，好看一点
    QFontMetrics metrics=painter.fontMetrics();
    int textHeight=metrics.ascent()+metrics.descent();
    int leftWidth=metrics.width(tr("100"))+5;
    int rightWidth=metrics.width(tr(""));
    int width=w->size().width()-leftWidth-rightWidth-20;
    int height=w->size().height()-3*textHeight;
    //绘制外框
    painter.drawRect(0,0,w->size().width()-1,w->size().height()-1);
    //移动坐标系
    painter.translate(leftWidth,1.75*textHeight+height);
    int totalCount=100;    //最大值为100
    int count=10;           //分成10成
    float deltaX=width/(float)pnum;           //x坐标上每分的宽度
    float deltaY=(float)height/count;   //y坐标上每分的宽度

    //画横坐标
    painter.drawLine(0,0,width,0);
    for(int i=1;i<=pnum;++i)
    {
        QString month=tr("%1").arg(i);
        int stringWidth=metrics.width(month);
        //绘制坐标刻度
        painter.drawLine(deltaX*i,0,deltaX*i,4);
        //绘制坐标值
        int monthX=deltaX*(i-1)+((deltaX-stringWidth)/2);
        painter.drawText(monthX,textHeight,month);
    }
    //画纵坐标
    painter.drawLine(0,0,0,-height);
    painter.drawText(-metrics.width(tr("%")),-(deltaY*count+textHeight/2+metrics.descent()),tr("%"));
    for(int i=1;i<=count;++i)
    {
        QString value=QString("%1").arg(i*totalCount/count);
        int stringWidth=metrics.width(value);
        //绘制坐标刻度
        painter.drawLine(-4,-i*deltaY,0,-i*deltaY);
        //绘制坐标值
        painter.drawText(-stringWidth-4,-(deltaY*i+textHeight/2-metrics.ascent()),value);
    }

    float x,y,x0,y0;
    int time=5;
    for(int i=1;i<pnum;i++)
    {
        x=i+1;
        y=ConnectPrecent2[time][i];
        QPen pen; //画笔
        pen.setColor(QColor(255,0,0));
        QBrush brush(QColor(0,0,255)); //画刷
        pen.setStyle(Qt::SolidLine);
        painter.setPen(pen); //添加实线画笔
        painter.setBrush(brush); //添加画刷
        painter.drawEllipse(deltaX*x-3,-y*deltaY-3,8,8); //绘制点
        pen.setStyle(Qt::DotLine);
        painter.setPen(pen); //添加虚线画笔
        painter.drawLine(0,-y*deltaY,deltaX*x,-y*deltaY);//绘制出横坐标线
        painter.drawLine(deltaX*x,0,deltaX*x,-y*deltaY);//绘制出纵坐标线
        pen.setStyle(Qt::SolidLine);
        painter.setPen(pen); //添加实线画笔
        if(i>=2)
        {
            x0=i;
            y0=ConnectPrecent2[time][i-1];

            painter.drawLine(deltaX*x0,-y0*deltaY,deltaX*x,-y*deltaY);//连线
        }
    }
}
