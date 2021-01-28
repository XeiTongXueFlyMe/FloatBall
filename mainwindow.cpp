#include "mainwindow.h"
#include <QPainter>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{    
    //无窗口 置顶
    setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);

    setAttribute(Qt::WA_TranslucentBackground);
}

MainWindow::~MainWindow()
{

}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.setBrush(QColor("#123456"));

    const int radius = 20;
    
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
        qDebug() << "mousePressEvent LeftButton";
    }
    if (e->button() == Qt::RightButton){
        qDebug() << "mousePressEvent RightButton";
    }
}
