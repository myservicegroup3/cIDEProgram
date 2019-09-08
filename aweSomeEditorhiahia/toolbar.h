#ifndef TOOLBAR_H
#define TOOLBAR_H
#include "mainwindow.h"
#include <QToolBar>
#include <QToolButton>
void MainWindow::buttonPics()
{
    QToolBar * toolBar=addToolBar("toolBar");
    QToolButton * b1 = new QToolButton(this);


    toolBar->setFixedSize(1000,50);

    b1->setIcon(QIcon(":/img/img/new.png"));
    b1->setStyleSheet("background-image:url(img/2.png)");
    b1->setStyleSheet("QToolButton{background-image:url(:/img/tree.jpg);}" // 按键本色
"QToolButton:hover{background-color:white; color: black;}"  // 鼠标停放时的色彩
"QToolButton:pressed{background-color:rgb(85, 170, 255); border-style: inset; }");
    b1->setFixedSize(30,30);
    toolBar->addWidget(b1);
    connect(b1,SIGNAL(clicked()),this,SLOT(New()));

    QToolButton *b2=new QToolButton(this);
    b2->setIcon(QIcon(":/img/img/open.png"));
    b2->setStyleSheet(
"QToolButton:hover{background-color:white; color: black;}"  // 鼠标停放时的色彩
"QToolButton:pressed{background-color:rgb(85, 170, 255); border-style: inset; }");
    b2->setFixedSize(30,30);
    connect(b2,SIGNAL(clicked()),this,SLOT(open()));
     toolBar->addWidget(b2);
     toolBar->addSeparator();

    QToolButton *b3=new QToolButton(this);
    //littlePic->addWidget(b3);
    b3->setIcon(QIcon(":/img/img/save.png"));
    b3->setStyleSheet(
"QToolButton:hover{background-color:white; color: black;}"  // 鼠标停放时的色彩
"QToolButton:pressed{background-color:rgb(85, 170, 255); border-style: inset; }");
    b3->setFixedSize(30,30);
    connect(b3,SIGNAL(clicked()),this,SLOT(save()));
     toolBar->addWidget(b3);
     toolBar->addSeparator();

    QToolButton *b4=new QToolButton(this);
    b4->setIcon(QIcon(":/img/img/eye.png"));
    //littlePic->addWidget(b4);
    b4->setStyleSheet(
"QToolButton:hover{background-color:white; color: black;}"  // 鼠标停放时的色彩
"QToolButton:pressed{background-color:rgb(85, 170, 255); border-style: inset; }");
    b4->setFixedSize(30,30);
    connect(b4,SIGNAL(clicked()),this,SLOT(hidebar()));
    toolBar->addWidget(b4);
    toolBar->addSeparator();

    QToolButton *b5=new QToolButton(this);
    b5->setIcon(QIcon(":/img/img/run.png"));
    //littlePic->addWidget(b5);
    b5->setStyleSheet(
"QToolButton:hover{background-color:white; color: black;}"  // 鼠标停放时的色彩
"QToolButton:pressed{background-color:rgb(85, 170, 255); border-style: inset; }");
    b5->setFixedSize(30,30);
    connect(b5,SIGNAL(clicked()),this,SLOT(on_comp()));toolBar->addWidget(b5);

    /*
    QToolButton *b6=new QToolButton(this);
    //littlePic->addWidget(b6);
    b6->setStyleSheet("background-color:#EEEEEE;  border:none");
    b6->setFixedSize(1000,50);
    b6->setDisabled(true);
    //b6->setStyleSheet("boder:none");
    //connect(b5,SIGNAL(clicked()),this,SLOT(on_comp()));
     toolBar->addWidget(b6);

     toolBar->addWidget(b6);*/
}

#endif // TOOLBAR_H
