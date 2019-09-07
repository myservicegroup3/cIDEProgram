#ifndef TOOLBAR_H
#define TOOLBAR_H
#include "mainwindow.h"
#include <QToolBar>
#include <QToolButton>
void MainWindow::buttonPics()
{
    QToolBar * toolBar=addToolBar("toolBar");
    QToolButton * b1 = new QToolButton(this);
    toolBar->addWidget(b1);




    b1->setStyleSheet("QToolButton{background-color:rgba(255,178,0,100%);\
                      color: white;   border-radius: 10px;  \
border: 2px groove gray; border-style: outset;}" // 按键本色
"QToolButton:hover{background-color:white; color: black;}"  // 鼠标停放时的色彩
"QToolButton:pressed{background-color:rgb(85, 170, 255); border-style: inset; }");
    b1->setFixedSize(50,50);
    connect(b1,SIGNAL(clicked()),this,SLOT(New()));

    QToolButton *b2=new QToolButton(this);

    b2->setStyleSheet("QToolButton{background-color:rgba(255,178,0,100%);\
                      color: white;   border-radius: 10px;  \
border: 2px groove gray; border-style: outset;}" // 按键本色
"QToolButton:hover{background-color:white; color: black;}"  // 鼠标停放时的色彩
"QToolButton:pressed{background-color:rgb(85, 170, 255); border-style: inset; }");
    b2->setFixedSize(50,50);
    connect(b2,SIGNAL(clicked()),this,SLOT(open()));
     toolBar->addWidget(b2);

    QToolButton *b3=new QToolButton(this);
    //littlePic->addWidget(b3);
    b3->setStyleSheet("QToolButton{background-color:rgba(255,178,0,100%);\
                      color: white;   border-radius: 10px;  \
border: 2px groove gray; border-style: outset;}" // 按键本色
"QToolButton:hover{background-color:white; color: black;}"  // 鼠标停放时的色彩
"QToolButton:pressed{background-color:rgb(85, 170, 255); border-style: inset; }");
    b3->setFixedSize(50,50);
    connect(b3,SIGNAL(clicked()),this,SLOT(save()));
     toolBar->addWidget(b3);

    QToolButton *b4=new QToolButton(this);
    //littlePic->addWidget(b4);
    b4->setStyleSheet("QToolButton{background-color:rgba(255,178,0,100%);\
                      color: white;   border-radius: 10px;  \
border: 2px groove gray; border-style: outset;}" // 按键本色
"QToolButton:hover{background-color:white; color: black;}"  // 鼠标停放时的色彩
"QToolButton:pressed{background-color:rgb(85, 170, 255); border-style: inset; }");
    b4->setFixedSize(50,50);
    connect(b4,SIGNAL(clicked()),this,SLOT(hidebar()));
 toolBar->addWidget(b4);
    QToolButton *b5=new QToolButton(this);
    //littlePic->addWidget(b5);
    b5->setStyleSheet("QToolButton{background-color:rgba(255,178,0,100%);\
                      color: white;   border-radius: 10px;  \
border: 2px groove gray; border-style: outset;}" // 按键本色
"QToolButton:hover{background-color:white; color: black;}"  // 鼠标停放时的色彩
"QToolButton:pressed{background-color:rgb(85, 170, 255); border-style: inset; }");
    b5->setFixedSize(50,50);
    connect(b5,SIGNAL(clicked()),this,SLOT(on_comp()));

 toolBar->addWidget(b5);
    QToolButton *b6=new QToolButton(this);
    //littlePic->addWidget(b6);
    b6->setStyleSheet("background-color:#EEEEEE;  border:none");
    b6->setFixedSize(1000,50);
    b6->setDisabled(true);
    //b6->setStyleSheet("boder:none");
    //connect(b5,SIGNAL(clicked()),this,SLOT(on_comp()));
     toolBar->addWidget(b6);

}

#endif // TOOLBAR_H
