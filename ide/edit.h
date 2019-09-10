#ifndef EDIT_H
#define EDIT_H
#include "mainwindow.h"
#include <QToolBar>
bool judge=false;
void MainWindow::edit_init()
{
    QAction *phide = pview->addAction(u8"隐藏菜单栏");
    phide ->setShortcut(tr("ctrl+h"));
    QAction * phidebar = pview->addAction(u8"隐藏工具栏");
        connect(phidebar,SIGNAL(triggered()),this,SLOT(hidetoolbar()));
    connect(phide,SIGNAL(triggered()),this,SLOT(hidebar()));
    QAction *copy_edit =pview->addAction(u8"复制");
    copy_edit ->setShortcut(tr("ctrl+c"));
     connect(copy_edit,SIGNAL(triggered()),this,SLOT(copy()));

     QAction *paste_edit = pview->addAction(u8"粘贴");
     paste_edit ->setShortcut(tr("ctrl+v"));
     connect(paste_edit,SIGNAL(triggered()),this,SLOT(paste()));

     QAction *cut_edit = pview->addAction(u8"剪切");
     cut_edit ->setShortcut(tr("ctrl+x"));
     connect(cut_edit,SIGNAL(triggered()),this,SLOT(cut()));
}

void MainWindow::hidebar()
{
    if (mbar->height() > 0){//设置菜单栏高度以实现隐藏效果
        mbar->setMaximumHeight(0);
    } else {
        mbar->setMaximumHeight(100);
    }
}
void MainWindow::hidetoolbar()
{
    if(judge==false)
    {
        toolBar->setVisible(judge);
        judge = true;
    }
    else
    {
        toolBar->setVisible(judge);
        judge = false;
    }
}

void MainWindow::copy()
{
    configEditor->blankEditor->copy();
}
void MainWindow::paste()
{
    configEditor->blankEditor->paste();
}
void MainWindow::cut()
{
    configEditor->blankEditor->cut();
}
#endif // EDIT_H
