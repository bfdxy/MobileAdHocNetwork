#ifndef MAIN_H
#define MAIN_H
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QTime>
#include <QFileDialog>
#include <QMessageBox>
#define random1(x)(qrand()%x)
#define MaxPnum 1000
#define MaxM 150
#define MaxN 150
#define MaxTime 100
using namespace std;
extern int row,col,pnum;
extern int num;
extern int ConnectNum;
extern int MoveNum;
extern int Time;
extern float ConnectPrecent[MaxTime];
extern float ConnectPrecent2[MaxTime][MaxPnum];//时刻、节点数目
class Node
{
private:
    int m;
    int n;
    int NodeNo;
    int movefrom;
    int infnum;
public:
    int inf[MaxPnum];
    Node();
    void SetNode();
    int GetM(){ return m; }
    int GetN(){ return n; }
    int GetNodeNo(){ return NodeNo; }
    int Getinfnum(int i=0){ infnum+=i;return infnum; }
    void Move();
    void Transfer(Node &p);
    bool IsConnected(Node &p);
};

extern Node p[MaxPnum];
void Show(Node *p,int pnumber);
void SaveTime0(QString filename) ;
void SaveTime(QString filename)  ;
void ThirdProblem();
#endif // MAIN_H
