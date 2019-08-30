#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(800,600);//设置主窗口的长宽
    w.show();

    return a.exec();
}
