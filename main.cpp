#include<iostream>
#include<ctime>
#include<stdlib.h>
using namespace std;
#include"head.h"
void Node::Move()
{
    int x0,y0;
    srand((unsigned)time(NULL));
    x0=rand()%3+(X-1);
    srand((unsigned)time(NULL));
    y0=rand()%3+(Y-1);
    if((x0!=x&&y0!=y)&&(x0!=X&&y0!=Y))
    {
        x=X;
        y=Y;
        X=x0;
        Y=y0;
    }
    else
        Move();
}
void Node::SetName(char a)
{
    name=a;
}
int* CreatLoad(int n)
{
    int *X;
    X=new int[n];
    return X;
}
Node* CreatNode(int j,int m,int n)
{
    char h='A';
    Node *NODE;
    NODE=new Node[j];
    for(int i=0;i<j;i++)
    {
        NODE[i].Node1(m,n);
        NODE[i].SetName((char)(h+i));
    }
    return NODE;
}
bool Check1(int m,int n,Node *N,int p)
{
    for(int i=0;i<p;i++)
    {
        if(m==N[i].GetX()&&n==N[i].GetY())
            return false;
    }
    return true;
}
int Check2(int m,int n,Node *N,int p)
{
    for(int i=0;i<p;i++)
    {
        if(m==N[i].GetX()&&n==N[i].GetY())
            return i;
    }
    return 0;
}
void Print(int m,int n,Node *N,int p)
{
    int b=0;
    int h=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!Check1(i,j,N,p))
                {
                    cout<<N[Check2(i,j,N,p)].GetName()<<"  ";
                    h++;
                }
            else
                cout<<b<<"  ";
        }
        cout<<endl<<endl;
    }
}
int main()
{
    int m,n,p,*X,*Y;
    Node *N;
    cout<<"请输入M（横向道路数目）："<<endl;
    cin>>m;
    X=CreatLoad(m);
    cout<<"请输入N（纵向道路数目）："<<endl;
    cin>>n;
    Y=CreatLoad(n);
    cout<<"请输入P（节点数目）："<<endl;
    cin>>p;
    N=CreatNode(p,m,n);
    Print(m,n,N,p);
    N[2].Move();
    cout<<endl<<endl;
    Print(m,n,N,p);
    return 0;

}
