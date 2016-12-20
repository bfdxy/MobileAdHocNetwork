#ifndef MAIN_H
#define MAIN_H
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <QString>
#define random1(x)(rand()%x)
#define MaxPnum 200
#define MaxM 100
#define MaxN 100
using namespace std;
extern int row,col,pnum;
extern int num;
extern int ConnectNum;
extern int MoveNum;
extern float ConnectPrecent[100];

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
void Show(Node *p);
#endif // MAIN_H
