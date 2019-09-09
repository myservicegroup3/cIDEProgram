#include "mainwindow.h"
#include "setting.h"
#include "toolbar.h"
#include "search.h"
#include "redefine.h"
#include "edit.h"
#include "file.h"
#include "debug.h"
#include "others.h"
#include "debug.h"
#include "tab.h"
#include <QMenuBar>
#include<QMenu>
#include<QAction>
#include<QDebug>
#include<QToolBar>
#include<QLabel>
#include<QStatusBar>
#include<QMessageBox>
#include<QDialog>
#include<QFileDialog>
#include<QFile>
#include<QLineEdit>
#include<QDialog>
#include<QPushButton>
#include<QPlainTextEdit>
#include <QTabWidget>
#include<QTabBar>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
       this->setupUi(this);
       this->setWindowIcon(QIcon(":/img/img/2.png"));
       tab_init();//tab
       file_init();//文件
       setting_init();//设置
       edit_init();//视图
       setsearch();//搜索
       debug_init();//编译调试
       about_init(); //关于
       buttonPics();//工具栏
       re = new redefine();//prosses
}


MainWindow::~MainWindow()
{
}


//视图


void MainWindow::hidestatus()
{

}


void MainWindow::test()
{

}

//搜索替换部分
