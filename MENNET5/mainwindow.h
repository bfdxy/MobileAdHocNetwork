#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "main.h"
#include "dialoginput.h"
#include "widget.h"
#include "widget2.h"
#include "q3inputdialog.h"
#include <QMainWindow>
#include <QPainter>
#include <QTimer>
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
    static int count ;
    static QString filename;
private slots:
    void on_pushButton_4_clicked();
    void paint() ;
    void on_SaveButton_clicked();
    void on_InputButten_clicked();
    void on_MoveButton_clicked();
    void on_pushButton_clicked();
    void on_AutoMoveButton_clicked();
private:
    Ui::MainWindow *ui;
    DialogInput DialogInput1 ;
    QTimer * timer ;

};

#endif // MAINWINDOW_H
