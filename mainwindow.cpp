#include "mainwindow.h"
#include <QPainter>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{    
    //无窗口 置顶
    setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);

    setAttribute(Qt::WA_TranslucentBackground);

    connect(this, SIGNAL(mouseEventReceived()), this, SLOT(slots_mouseEventReceived()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.setBrush(QColor("#123456"));

    const int radius = width()/2 - 10;
    
    painter.drawRoundedRect(QRect(0, 0, width(), height()), radius, radius);
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    if (e->buttons() & Qt::LeftButton)
        move(e->globalPos() - point);
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton){
        point = e->globalPos() - frameGeometry().topLeft();
        emit mouseEventReceived();

    }
    if (e->button() == Qt::RightButton){
        emit mouseEventReceived();

    }
}

void MainWindow::slots_mouseEventReceived()
{
    qDebug() << "mousePressEvent LeftButton";
}

//TODO:右键切换模式，常规模式，移动模式（保存上次位子，下次开机恢复）

//TODO:左键双击绑定回退

//TODO:左键单击唤出系统菜单

//TODO:左键按住移动，画移动围栏，并且禁止移动到围栏外，松开后回退到原点。


