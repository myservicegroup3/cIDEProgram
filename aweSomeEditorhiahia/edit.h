#ifndef EDIT_H
#define EDIT_H
#include "mainwindow.h"
void MainWindow::edit_init()
{
    QAction *phide = pview->addAction(u8"隐藏菜单栏");
    phide ->setShortcut(tr("ctrl+h"));
    connect(phide,SIGNAL(triggered()),this,SLOT(hidebar()));
}

void MainWindow::hidebar()
{
    if (mbar->height() > 0){//设置菜单栏高度以实现隐藏效果
        mbar->setMaximumHeight(0);
    } else {
        mbar->setMaximumHeight(100);
    }
}
#endif // EDIT_H
