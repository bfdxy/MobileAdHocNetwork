#include "mainwindow.h"
#include "dialoginput.h"
#include "widget.h"
#include <QApplication>
#include <QDebug>

//
//  main.cpp
//  MobileAdHocNetwork
//
//  Created by YMB on 2016/12/15.
//  Copyright © 2016 YMB. All rights reserved.
//
int RoadNode[MaxM][MaxN];
int row,col,pnum;
int num=1;
int ConnectNum=0;
int MoveNum=0;
float ConnectPrecent[100];
float ConnectPrecent2[100][MaxPnum];
Node p[MaxPnum];

Node::Node()
{
    m=0;
    n=0;
    NodeNo=num;
    num++;
    movefrom=-1;
    infnum=1;
    inf[0]=NodeNo;
}

void Node::SetNode()
{
    srand((unsigned)time(0)+this->GetNodeNo());
    m=random1(row);
    n=random1(col);
    movefrom=-1;
    infnum=1;
    for(int i=0;i<MaxPnum;i++)
        inf[i]=0;
    inf[0]=NodeNo;
}

void Node::Transfer(Node &p)
{
    int i,j;
    if((m==p.GetM()&&p.GetN()>=n-1&&p.GetN()<=n+1)||(n==p.GetN()&&p.GetM()>=m-1&&p.GetM()<=m+1))
    {
        for(i=0;i<p.Getinfnum();i++)
        {
            bool flag=false;
            for(j=0;j<infnum;j++)
                if(inf[j]==p.inf[i])
                    flag=true;
            if(flag==false)
            {
                inf[infnum]=p.inf[i];
                infnum++;
            }

        }
        for(i=0;i<infnum;i++)
        {
            bool flag=false;
            for(j=0;j<p.Getinfnum();j++)
                if(p.inf[j]==inf[i])
                    flag=true;
            if(flag==false)
            {
                p.inf[p.Getinfnum()]=inf[i];
                p.Getinfnum(1);
            }

        }
    }
}

bool Node::IsConnected(Node &p)
{
    int i;
    for(i=0;i<p.Getinfnum();i++)
            if(p.inf[i]==NodeNo)
                return true;
    return false;
}
void Node::Move()
{
    bool flag=false;
    int x=0;
    while(!flag)
    {
        x=random1(4);
        while(movefrom!=-1&&(movefrom==(x-2)||movefrom==(x+2)))
            x=random1(4);
        switch(x)
        {
            case 0:
                if(m-1>=0)
                {
                    m=m-1;
                    flag=true;
                }
                break;
            case 1:
                if(n-1>=0)
                {
                    n=n-1;
                    flag=true;
                }
                break;
            case 2:
                if(m+1<row)
                {
                    m=m+1;
                    flag=true;
                }
                break;
            case 3:
                if(n+1<col)
                {
                    n=n+1;
                    flag=true;
                }
                break;
        }
    }
    movefrom=x;
}

void Show(Node *p,int pnumber=pnum)
{
    int i,j,k;
    for(k=0;k<pnumber;k++)
    {
        cout<<"("<<p[k].GetM()<<","<<p[k].GetN()<<")"<<p[k].GetNodeNo()<<"-";
        for(i=0;i<p[k].Getinfnum();i++)
            cout<<p[k].inf[i];
        cout<<endl;
    }
    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
        {
            RoadNode[i][j]=0;
            for(k=0;k<pnumber;k++)
                if(p[k].GetM()==i&&p[k].GetN()==j)
                    RoadNode[i][j]=p[k].GetNodeNo();
        }
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            cout<<RoadNode[i][j];
            if(j!=col-1)
                cout<<"  ";
            if(RoadNode[i][j]<100)
                cout<<" ";
            if(RoadNode[i][j]<10)
                cout<<" ";
        }
        cout<<endl;
        if(i!=row-1)
            cout<<endl;
    }
    for(i=0;i<pnumber;i++)
        for(j=0;j<pnumber;j++)
            p[i].Transfer(p[j]);
    ConnectNum=0;
    for(i=0;i<pnumber;i++)
        for(j=0;j<pnumber;j++)
            if(i!=j)
            {
                cout<<"["<<p[i].GetNodeNo()<<"]->["<<p[j].GetNodeNo()<<"]  ";
                if(p[i].IsConnected(p[j]))
                {
                    cout<<"Yes";
                    ConnectNum++;
                }
                else
                    cout<<"No";
                cout<<endl;
            }
    //cout<<"ConnectNumber:"<<ConnectNum<<" "<<(float)ConnectNum/(pnumber*(pnumber-1))*100<<"%"<<endl;
    ConnectPrecent[MoveNum]=(float)ConnectNum/(pnumber*(pnumber-1))*10;
    if(ConnectPrecent[MoveNum]>10)
        ConnectPrecent[MoveNum]=0;
    qDebug()<<MoveNum<<" "<<ConnectPrecent[MoveNum]<<"/n";
    /*if(ConnectPrecent[MoveNum]>9.99999)
    {
        Widget *w=new Widget;
        w->show();
    }*/
}
void SaveTime0()
{
    QFile data("C:/file.txt");
    if(data.open(QFile::WriteOnly|QIODevice::WriteOnly))
    {
        QTextStream out(&data);
        out<<"Initial time: "<<"\r\n";
        out<<"M:"<<row<<"    "<<"N:"<<col<<"    "<<"P:"<<pnum<<"\r\n";
        for(int i=0;i<pnum;i++)
        {
            out<<"Node "<<i+1<<": "<<"row: "<<p[i].GetM()<<"  "<<"col: "<<p[i].GetN()<<"\r\n";
        }
    }
}

void SaveTime()
{
    QFile data("C:/file.txt");
    if(data.open(QFile::WriteOnly|QIODevice::Append))
    {
        QTextStream out(&data);
        out<<"Time "<<MoveNum<<":"<<"\r\n";
        for(int i=0;i<pnum;i++)
        {
            out<<"Node "<<i+1<<": "<<"row: "<<p[i].GetM()<<"  "<<"col: "<<p[i].GetN()<<"\r\n";
        }
    }
}

void ThirdProblem()
{
    int i,j,k;
    for(i=1;i<pnum;i++)
    {
        MoveNum=0;
        ConnectNum=0;
        for(j=0;j<=i;j++)
            p[j].SetNode();
        while(ConnectNum<i*(i+1))
        {
            for(k=0;k<=i;k++)
                p[k].Move();
            Show(p,i+1);
            ConnectPrecent2[MoveNum][i]=((float)ConnectNum/(i*(i+1)))*10;
            MoveNum++;
        }
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    srand((unsigned)time(0));
        MainWindow w;
        w.show();
        return a.exec();
        return 0;
}
