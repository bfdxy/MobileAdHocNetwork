#include "widget.h"
#include "ui_widget.h"
#include <QtGui/QPainter>
Widget::Widget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->installEventFilter(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeEvent(QEvent *e)
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
bool Widget::eventFilter(QObject *watched, QEvent *e)
{
    if(watched==this)
    {
        if(e->type()==QEvent::Paint)
        {
            paintOnWidget(this);
            return true;
        }
    }
    return QWidget::eventFilter(watched,e);
}

void Widget::paintOnWidget(QWidget *w)
{
    QPainter painter(w);
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
    int number=6;
    int count=10;           //分成10成
    float deltaX=width/(float)number;           //x坐标上每分的宽度
    float deltaY=(float)height/count;   //y坐标上每分的宽度

    //画横坐标
    painter.drawLine(0,0,width,0);
    for(int i=1;i<=number;++i)
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

float N[100],x,y,x0,y0;
N[0]=2.5;
N[1]=4.8;
N[2]=6.4;
N[3]=8.7;
N[4]=9.7;
N[5]=10;
N[6]=5;
for(int i=0;i<=number;i++)
{
    x=i;
    y=N[i];
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
    if(i>=1)
    {
        x0=i-1;
        y0=N[i-1];

        painter.drawLine(deltaX*x0,-y0*deltaY,deltaX*x,-y*deltaY);//连线
    }
}
}
