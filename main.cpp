#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    //TODO:根据屏幕分辨率设置按钮大小
    w.setFixedSize(100, 100);
    w.show();

    return a.exec();
}
