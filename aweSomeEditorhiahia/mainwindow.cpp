#include "mainwindow.h"
#include <QMenuBar>
#include<QMenu>
#include<QAction>
#include<QDebug>
#include<QToolBar>
#include<QLabel>
#include<QStatusBar>
#include<QMessageBox>
#include<QDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->setupUi(this);
    configEditor = new CodeEditor();
    configEditor->setMode(EDIT);
    gridLayout->addWidget(configEditor);
    MyHighLighter *highlighter = new MyHighLighter(configEditor->document());

     //添加菜单栏
    QMenuBar *mbar=menuBar();
    //添加菜单项
    QMenu *pfile=mbar->addMenu("文件");
    QMenu *pfind =mbar->addMenu("搜索");
    QMenu *pexeute=mbar->addMenu("运行");
    QMenu *psetting=mbar->addMenu("设置");
    QMenu *pabout =mbar->addMenu("关于");

    //关于
    QAction *ab=pabout->addAction("开发人员");
    connect(ab,&QAction::triggered,[=]()
    {
        QMessageBox::about(this,"about","开发人员：七只羊，赵英健，刘俊杰，刘常思冰，黄啸嵩");
    });


    //文件菜单栏
    //1.新建文件
    QAction *pNew = pfile->addAction("新建");
    pNew ->setShortcut(tr("ctrl+n"));
    connect(pNew,&QAction::triggered,[=](){

    }
    );
       pfile->addSeparator();


    //2.打开文件
    QAction *popen =pfile->addAction("打开");
    popen ->setShortcut(tr("ctrl+o"));
    connect(popen,&QAction::triggered,[=](){

    }
    );




   //工具栏，添加快捷方式
       QToolBar * toolBar=addToolBar("toolBar");
       toolBar->addAction(pNew);
       toolBar->addAction(popen);

   //状态栏，我准备在这里显示编译成功与否
       QStatusBar *sBar =statusBar();
       QLabel *label =new QLabel(this);
       label->setText("编译");
       sBar->addWidget(label);
       sBar->addWidget(new QLabel("2",this));










}

MainWindow::~MainWindow()
{
}
