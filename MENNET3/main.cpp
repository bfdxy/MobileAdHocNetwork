#include "mainwindow.h"
#include "dialoginput.h"
#include "widget.h"
#include <QApplication>

//
//  main.cpp
//  MobileAdHocNetwork
//
//  Created by YMB on 2016/12/15.
int num=1;
int ConnectNum=0;
//  Copyright © 2016 YMB. All rights reserved.
//
int RoadNode[MaxM][MaxN];
int row,col,pnum;
int MoveNum=0;
float ConnectPrecent[100];
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

void Show(Node *p)
{
    int i,j,k;
    for(k=0;k<pnum;k++)
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
            for(k=0;k<pnum;k++)
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
    for(i=0;i<pnum;i++)
        for(j=0;j<pnum;j++)
            p[i].Transfer(p[j]);
    ConnectNum=0;
    for(i=0;i<pnum;i++)
        for(j=0;j<pnum;j++)
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
    cout<<"ConnectNumber:"<<ConnectNum<<" "<<(float)ConnectNum/(pnum*(pnum-1))*100<<"%"<<endl;
    ConnectPrecent[MoveNum]=(float)ConnectNum/(pnum*(pnum-1))*10;

    if(ConnectPrecent[MoveNum]>9.99999)
    {
        Widget *w=new Widget;
        w->show();
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    srand((unsigned)time(0));
    DialogInput dlgi;

    if(dlgi.exec()==QDialog::Accepted)
    {
        MainWindow w;
        w.show();
        return a.exec();
    }
    else
        return 0;
}
