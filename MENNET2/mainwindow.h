#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <iostream>
#include <QString>
#define random1(x)(rand()%x)
#define MaxPnum 100
#define MaxM 100
#define MaxN 100

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
    int GetM(){ return m; }
    int GetN(){ return n; }
    int GetNodeNo(){ return NodeNo; }
    int Getinfnum(int i=0){ infnum+=i;return infnum; }
    void Move();
    void Transfer(Node &p);
    bool IsConnected(Node &p);
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);
private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
