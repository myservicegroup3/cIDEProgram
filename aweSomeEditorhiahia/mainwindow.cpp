#include "mainwindow.h"
#include "setting.h"
#include "toolbar.h"
#include "search.h"

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

    /****************************初始化Tabwidget**************************/

    this->configEditor = new tabCodeEditor();
    configEditor->setTabsClosable(true);
    connect(configEditor,SIGNAL(tabCloseRequested(int)),this,SLOT(removetab(int)));
    gridLayout->addWidget(configEditor);
    /*******************************************************************/

    /****************************新建Tabwidget**************************/
    //QAction *pceshi = ptest->addAction("test");
    //connect(pceshi, SIGNAL(triggered()), this, SLOT(addPageSlot()));
    /**********************************************************/



     /****************************设置**************************/
        setting_init();
     /**********************************************************/

     /***************************视图**************************/
        QAction *phide = pview->addAction(u8"隐藏菜单栏");
        phide ->setShortcut(tr("ctrl+h"));
        connect(phide,SIGNAL(triggered()),this,SLOT(hidebar()));
    /**********************************************************/



    MyHighLighter *highlighter = new MyHighLighter(configEditor->blankEditor->document());



    /****************************文件菜单栏**************************/


    //1.新建文件  //代码已完成，可测试
    QAction *pNew = pfile->addAction(u8"新建");
    pNew ->setShortcut(tr("ctrl+n"));
    connect(pNew,SIGNAL(triggered()),this,SLOT(New()));
    connect(pNew, SIGNAL(triggered()), this, SLOT(addPageSlot()));
    pfile->addSeparator();


    //2.打开文件,即读已写文件，已完成，可测试
    QAction *popen =pfile->addAction(u8"打开");
    popen ->setShortcut(tr("ctrl+o"));
    connect(popen,SIGNAL(triggered()),this,SLOT(open()));
    pfile->addSeparator();

    //3.保存为文件,代码已完成，可测试
    QAction *psave = pfile->addAction(u8"保存");
    psave ->setShortcut(tr("ctrl+s"));
    connect(psave,SIGNAL(triggered()),this,SLOT(save()));
    pfile->addSeparator();
   /**************************************************************/

    /***************************搜索********************************/
    setsearch();
    /**************************************************************/


   /**************************编译运行*********************************/
   //编译完成 ljj lcsb 测试可用
    QAction *comp = pexeute->addAction(u8"编译");
    QAction *run = pexeute->addAction(u8"运行");
    //connect(configEditor->toPlainText(),SIGNAL(textChanged()),this,SLOT(on_changed()));
    connect(comp,SIGNAL(triggered()),this,SLOT(on_comp()));
    connect(run,SIGNAL(triggered()),this,SLOT(on_run()));

    /**************************************************************/



    /***********************栏*************************************/

   //状态栏，我准备在这里显示编译成功与否
       QStatusBar *sBar =statusBar();
       QLabel *label =new QLabel(this);
       label->setText(u8"编译");
       sBar->addWidget(label);
       sBar->addWidget(new QLabel("2",this));

       //关于
       QAction *ab=pabout->addAction(u8"开发人员");
       connect(ab,&QAction::triggered,[=]()
       {
           QMessageBox::about(this,"about",u8"开发人员：祁志洋，赵英健，刘俊杰，刘常思冰，黄啸嵩");
       });
    /**************************************************************/


    /***************************工具栏*****************************/
       buttonPics();

   /**************************************************************/

}


MainWindow::~MainWindow()
{
}
void MainWindow :: addPageSlot()
{
    //定义一个QWidget.
    CodeEditor * temp = new CodeEditor;
    //blankWidget *temp = new blankWidget;
    //在当前页面的后面插入一个新的页面.
    configEditor->insertTab(configEditor->currentIndex()+1,temp,QIcon("Icons/2.png"),QString::number(count));
   //configEditor->insertTab(configEditor->currentIndex()+1,temp,QIcon("Icons/2.png"),QString::number(count));
            //显示新的页面
    configEditor->setCurrentIndex(configEditor->indexOf(temp));

    count++;
}
void MainWindow::New()
{
      filepath= QFileDialog::getSaveFileName(this,"save","../","souce(*cpp *h);;Text(*.txt)");
      if(filepath.isEmpty()==false)
      {
          QFile file;//创建文件对象
          file.setFileName(filepath);
          bool isok=file.open(QIODevice::WriteOnly);
          file.close();
      }
}
void MainWindow::open()
{
    filepath= QFileDialog::getOpenFileName(
                this,
                "open",
                "../",
                "souce(*cpp *h);;Text(*.txt)"
                );
     if (filepath.isEmpty()==false)
     {    QFile file (filepath);
     bool isok =file.open(QIODevice::ReadOnly);
     if(isok==true)
     {
         //读文件
     QByteArray array= file.readAll();
     configEditor->blankEditor->appendPlainText(array);
         }
     }
}
void MainWindow::save()
{
          filepath= QFileDialog::getSaveFileName(this,"save","../","souce(*cpp *h);;Text(*.txt)");
          if(filepath.isEmpty()==false)
          {
              QFile file;//创建文件对象
              file.setFileName(filepath);
              bool isok=file.open(QIODevice::WriteOnly);
              if(isok==true)
              {
              QString str=configEditor-> blankEditor->toPlainText();
              file.write(str.toUtf8());
              }
              file.close();
          }
}

//编译
//判断代码是否被修改
void MainWindow::on_change()
{
    is_changed = true;
}
//编译运行
void MainWindow::on_comp()
{
    if(is_changed == true)
    {








    }
    QString cmd;
    cmd = "gcc -o " + filepath.replace(QRegExp("\\..*$"),"") + ".exe " + filepath + ".cpp";
    system(cmd.toStdString().data());//编译
    //运行
    cmd = filepath + ".exe";
    system(cmd.toStdString().data());
}
//运行
void MainWindow::on_run()
{
    QString cmd;
    cmd = filepath.replace(QRegExp("\\..*$"),"") + ".exe";
    system(cmd.toStdString().data());
}
//视图
void MainWindow::hidebar()
{
    if (mbar->height() > 0){//设置菜单栏高度以实现隐藏效果
        mbar->setMaximumHeight(0);
    } else {
        mbar->setMaximumHeight(100);
    }
}
void MainWindow::test()
{

}

//搜索替换部分

void MainWindow::showFindText1()
{
    QString str = findLineEdit->text();
    if(!configEditor->blankEditor->find(str,QTextDocument::FindBackward))
    {
            QMessageBox::warning(this,tr("错误"),tr("找不到%1").arg(str));
    }

}

void MainWindow::showFindText2()
{
    QString str = findLineEdit->text();
    if(!configEditor->blankEditor->find(str))
    {
            QMessageBox::warning(this,tr("错误"),tr("找不到%1").arg(str));
    }

}

void MainWindow::showFindText_1()
{
    QString str = findLineEdit_1->text();
    if(!configEditor->blankEditor->find(str,QTextDocument::FindBackward))
    {
            QMessageBox::warning(this,tr("错误"),tr("找不到%1").arg(str));
    }
}

void MainWindow::showFindText_2()
{
    QString str = findLineEdit_1->text();
    if(!configEditor->blankEditor->find(str))
    {
            QMessageBox::warning(this,tr("错误"),tr("找不到%1").arg(str));
    }

}

void MainWindow::showFindText3()
{
    QString str = findLineEdit_1->text();
    QString str1 = findLineEdit_2->text();
    if(configEditor->blankEditor->textCursor().selectedText()==str)
    {
            configEditor->blankEditor->textCursor().insertText(str1);
    }
}
void MainWindow::removetab(int index)
{
   configEditor->removeTab(index);
};
